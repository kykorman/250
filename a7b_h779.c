#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double dist(int x1,int y1,int x2, int y2);

int main(int argc,char **argv){
	const int CENTER=7500;
	float overallClosest[2]={15000,-1};
	int redScore=0,yellowScore=0;
	int stones[10][2];//x is index 0, y is index 1
	int score[9][2]={0};//first dimension is round, second dimension: first score, then 0 for red, 1 for yellow

	if(argc==1){
		printf("No input file specified\n");
		exit(1);
	}

	FILE *in=fopen(argv[1],"r");
	if(in==NULL){
		printf("Invalid file specified\n");
		exit(1);
	}
	for(int k=1;k<=8;k++){
		int roundNum,lowStone=-1,lowOpposingStone=11;
		double lowestDist=6500.1,lowestOpposingDist=6500;//lowestOpposing Dist set to lowest distance to count as being in play for later if statement
		fscanf(in,"%d",&roundNum);
		//These two for loops scan everything in alternating so that it is in the order thrown. #itCompiles.
		if(roundNum%2==1){
			for(int i=0;i<10;i+=2)
				fscanf(in,"%d %d", &stones[i][0],&stones[i][1]);

			for(int i=1;i<10;i+=2)
				fscanf(in,"%d%d", &stones[i][0],&stones[i][1]);
		}else{
			for(int i=1;i<10;i+=2)
				fscanf(in,"%d %d", &stones[i][0],&stones[i][1]);

			for(int i=0;i<10;i+=2)
				fscanf(in,"%d%d", &stones[i][0],&stones[i][1]);
		}


		//find lowest distance (in order for tie stuff)
		for(int i=0;i<10;i++){
			if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<lowestDist){
				lowestDist=dist(CENTER,CENTER,stones[i][0],stones[i][1]);
				lowStone=i;
			}if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<overallClosest[0]&&stones[i][0]!=-1){
				overallClosest[0]=dist(CENTER,CENTER,stones[i][0],stones[i][1]);
				if(roundNum%2==0){
                	if(lowStone%2==0)
	                    overallClosest[1]=1;
    	            else
        	            overallClosest[1]=0;
           		}else{
                	if(lowStone%2==0)
                    	overallClosest[1]=0;
               		else
                    	overallClosest[1]=1;

            	}
			}
		}
		//This if/else if decides the lowest opposing stone dist, how many scoring team stones are under that distance for score, and adds it to the right team total.
		if(lowStone%2==0&&lowStone!=-1){
			int scoreCurr=0;

			for(int i=1;i<10;i+=2){
				if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<lowestOpposingDist&&stones[i][0]!=-1){
					lowestOpposingDist=dist(CENTER,CENTER,stones[i][0],stones[i][1]);
					lowOpposingStone=i;
					}
			}
			for(int i=0;i<10;i+=2){
				if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<lowestOpposingDist)
					scoreCurr++;
				else if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<=lowestOpposingDist&& i < lowOpposingStone)
					scoreCurr++;
			}
			score[roundNum][0]=scoreCurr;
			if(roundNum%2==0){
				if(lowStone%2==0)
					score[roundNum][1]=1;
				else
					score[roundNum][1]=0;
			}else{
				if(lowStone%2==0)
					score[roundNum][1]=0;
				else
					score[roundNum][1]=1;

			}
		}else if(lowStone%2==1&&lowStone!=-1){
			int scoreCurr=0;
			for(int i=0;i<10;i+=2){
				if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<lowestOpposingDist&&stones[i][0]!=-1){
					lowestOpposingDist=dist(CENTER,CENTER,stones[i][0],stones[i][1]);
					lowOpposingStone=i;
					}
			}
			for(int i=1;i<10;i+=2){
				if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<lowestOpposingDist)
					scoreCurr++;
				else if(dist(CENTER,CENTER,stones[i][0],stones[i][1])<=lowestOpposingDist && i < lowOpposingStone)
					scoreCurr++;
			}

			score[roundNum][0]=scoreCurr;

			if(roundNum%2==0){
				if(lowStone%2==0)
					score[roundNum][1]=1;
				else
					score[roundNum][1]=0;
			}else{
				if(lowStone%2==0)
					score[roundNum][1]=0;
				else
					score[roundNum][1]=1;

			}
		}
		//did this because I added it in late and I'm lazy. I didn't want to accumulate the red/yellow score
		//with the rest of my scoring stuff as it's admittedly somewhat confusing
        //Initially was set up to print out the score accumulated that specific round only, so that's why score[][]exists and is being used
		for(int i=1;i<=roundNum;i++){
			if(score[i][1])
				yellowScore+=score[i][0];
			else
				redScore+=score[i][0];
	}
		printf("====================\n");
		printf("    Round: %d\nRed score:    %2d\nYellow Score: %2d\n",roundNum,redScore,yellowScore);
		printf("====================\n");
		redScore=0;
		yellowScore=0;
	}

	for(int i=0;i<9;i++){
		if(score[i][1])
			yellowScore+=score[i][0];
		else
			redScore+=score[i][0];
	}

	printf("\n\n####################\n");
	printf("Final scores\n");
	printf("Red score:    %2d\nYellow Score: %2d\n",redScore,yellowScore);
	if(redScore>yellowScore)
		printf("Red wins!\n");
	else if(yellowScore>redScore)
		printf("Yellow wins!\n");
	else{
		if(overallClosest[1]==0)
			printf("Red wins by means of closest stone!\n");
		else if(overallClosest[1]==1)
			printf("Yellow wins by means of closest stone!\n");
		else
			printf("Nobody won...\n");
	}
	printf("####################\n");

return 0;}

//This exists solely to make Evan Bolt sad
double dist(int x1,int y1,int x2,int y2){
return pow(pow(x1-x2,2)+pow(y1-y2,2),.5);}

