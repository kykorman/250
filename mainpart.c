#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct convert{
	int num;
	char word[25];
};

int getPairs(struct convert pairs[],char file[]);
int scanNums(int nums[]);
int scanWords(char words[][25]);
int main(int argc,char **argv){

	int many,nums[100];
	char buff[100],words[100][25];
	struct convert pairs[100];

	many=getPairs(pairs,argv[1]);

	printf("Nums to text (y/n): ");
	fgets(buff,100,stdin); //so that additional characters don't sit in buffer.

	if(buff[0]=='y'||buff[0]=='Y'){
		int msgLen=scanNums(nums);
		num2letter(pairs,many,nums,msgLen);
	}
	else{
		printf("Text to nums (y/n): ");
		fgets(buff,100,stdin); //so that additional characters don't sit in buffer.
		if(buff[0]=='y'||buff[0]=='Y'){
			int msgLen=scanWords(words);
			letter2num(pairs,many,words,msgLen);
		}
	}
return 0;}

int getPairs(struct convert pairs[],char file[]){
	int many=0;
	FILE *in = fopen(file,"r");

	if(in==NULL){
		printf("Invalid file specified.\n");
		exit(1);
	}

	fscanf(in,"%s%d",pairs[many].word,&pairs[many].num);
	while(!feof(in)){
		many++;
		fscanf(in,"%s%d",pairs[many].word,&pairs[many].num);
	}
return many;}

int scanNums(int nums[100]){
	int many;
	char file[25];
	printf("Enter name of file: ");
	scanf("%s",file);
	FILE *in=fopen(file,"r");

	if(in==NULL){
		printf("Invalid file specified.\n");
		exit(1);
	}
	fscanf(in,"%d",&many);

	for(int i=0;i<many;i++){
		fscanf(in,"%d",&nums[i]);
	}
return many;}

int scanWords(char words[][25]){
	int many;
	char file[25];
	printf("Enter name of file: ");
	scanf("%s",file);
	FILE *in=fopen(file,"r");

	if(in==NULL){
		printf("Invalid file specified.\n");
		exit(1);
	}
	fscanf(in,"%d",&many);

	for(int i=0;i<many;i++){
		fscanf(in,"%s",words[i]);
	}
return many;}

