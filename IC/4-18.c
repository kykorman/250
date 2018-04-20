#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct person{
	char name[25];
	int code;
	int cat;
	struct person *next;
};

struct person *makeBox(struct person add){
	struct person *tmp;

	tmp=malloc(sizeof(struct person));

	strcpy(tmp->name,add.name);

	tmp->code=add.code;

	tmp->cat=add.cat;

	tmp->next=NULL;

return tmp;}

void insertFront(struct person *peeps[11],struct person add){
	struct person *tmp=makeBox(add);

	tmp->next=peeps[add.cat];
	peeps[add.cat]=tmp;

}

struct person *getLoc(struct person *peeps[11],int code){
	for(int i=1;i<11;i++){
		struct person *tmp=peeps[i];

		while(tmp!=NULL){
			if(tmp->code==code)
				return tmp;

			tmp=tmp->next;
		}


	}
	return NULL;
}

void printList(struct person *all[11]){

	for(int i=1;i<11;i++){
		struct person *tmp=all[i];

		if(tmp!=NULL)
			printf("Category %2d\n",i);

		while(tmp!=NULL){
			printf("        %s %d\n",tmp->name,tmp->code);
			tmp=tmp->next;
		}


	}
	

}




int main(int argc, char *argv[]){


	struct person *peeps[11];

	for(int i=0;i<11;i++)
		peeps[i]=NULL;
	FILE *infp =fopen(argv[1],"r");
	
	struct person scan;

	if(infp==NULL){
		printf("Invalid file\n");
		exit(1);
	}


	fscanf(infp,"%s %d%d ",scan.name,&scan.code,&scan.cat);
	while(!feof(infp)){
		insertFront(peeps,scan);
		fscanf(infp,"%s %d%d",scan.name,&scan.code,&scan.cat);
	}
	printList(peeps);	
return 0;}
