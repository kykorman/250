#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int manyUpper( char s[] );
int manyDigit( char s[] );


int main( int argc, char *argv[] )
{

	char line[100],maxLine[100],minLine[100];
	int lineNum = 1;
	FILE *infp;
	if(argc==1){
		printf("No argument entered for input file. Please enter  %s [input file name]    \n",argv[0]);
		exit(1);
	}

	infp=fopen(argv[1],"r");

	if(infp==NULL){
		printf("Error reading input file %s\nPlease validate that the file is in the directory that you specified.\n",argv[1]);
		exit(1);
	}
	int numDig,maxNumDig=0,numUpper,maxNumUpper=0,maxNumDigLine=0,maxUpperLine=0,maxLineLen=0,minLineLen=1000,maxLineNum,minLineNum;

	fgets(line,100,infp);
	line[strlen(line)-1]='\0';

	while(!feof(infp)){

		numDig=manyDigit(line);

		if(numDig>maxNumDig){
			maxNumDig=numDig;
			maxNumDigLine=lineNum;
		}

		numUpper=manyUpper(line);

		if(numUpper>maxNumUpper){
			maxNumUpper=numUpper;
			maxUpperLine=lineNum;
		}		
		if(strlen(line)>maxLineLen){
			maxLineLen=strlen(line);
			strcpy(maxLine,line);
			maxLineNum=lineNum;
		}
		if(strlen(line)<minLineLen){
			minLineLen=strlen(line);
			strcpy(minLine,line);
			minLineNum=lineNum;
		}
		lineNum++;
		fgets(line,100,infp);
		line[strlen(line)-1]='\0';

	}
	printf("Longest line:   line # %2d, %s\n",maxLineNum,maxLine);
	printf("Shortest line:  line # %2d, %s\n",minLineNum,minLine);
	printf("Most uppercase: line # %2d, %d\n",maxUpperLine,maxNumUpper);
	printf("Most digits:    line # %2d, %d\n",maxNumDigLine,maxNumDig);

	return 0;
}


int manyUpper( char s[] )
{
	int num=0,len=strlen(s);

	for(int i=0;i<len;i++)
		if(s[i]>='A'&&s[i]<='Z')
			num++;

return num;}

int manyDigit( char s[] )
{
	int num=0,len=strlen(s);

	for(int i=0;i<len;i++)
		if(s[i]>='0'&&s[i]<='9')
			num++;

return num;}

