#include <stdio.h>

int main(int argc, char **argv){

	FILE *fin, *fout;
	int x,y;
	fin = fopen(argv[1],"r");
	fout = fopen(argv[2],"w");


	fscanf(fin,"%d %d",&x,&y);

	while(!feof(fin)){
		fprintf(fout,"%d + %d = %d\n",x,y,x+y);
		fscanf(fin,"%d %d",&x,&y);
	}

return 0;}
