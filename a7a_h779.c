#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv){
	int grid[20][20]={0};
	int x,y,val;
	if(argc==1){
		printf("No valid input file specified. Type     %s [filename]     to use this program\n");
		exit(1);
	}

	FILE *in = fopen(argv[1],"r");
	if(in ==NULL){
		printf("Invalid file\n");
		exit(1);
	}

	fscanf(in,"%d%d%d",&x,&y,&val);

	while(!feof(in)){
		grid[x][y]+=val;
		fscanf(in,"%d%d%d",&x,&y,&val);
	}
	int most=grid[0][0];
	for(int i=0;i<20;i++)
		for(int k=0;k<20;k++)
			if(grid[i][k]>most)
				most=grid[i][k];

	printf("Most visitors in one spot: %d\n",most);
	printf("\nSpot(s) with the most visitors\nGiven as (x,y)\n");

	for(int i=0;i<20;i++)
		for(int k=0;k<20;k++)
			if(grid[i][k]==most){
				printf("(%d,%d)\n",i,k);
			}
	int num=0;
	for(int i=0;i<20;i++)
		for(int k=0;k<20;k++)
			if(grid[i][k]==0)
				num++;

	printf("%d locations not visited\n",num);

	printf("\n20x20 grid\n\n");
	for(int i=0;i<20;i++){
		for(int k=0;k<20;k++){
			if(grid[i][k]==0)
				printf(".");
			else if(grid[i][k]>10)
				printf("H");
			else
				printf("L");
		}
		printf("\n");
	}
return 0;}
