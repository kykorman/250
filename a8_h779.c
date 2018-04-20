#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LSize 50 
void insertEnd( int L[], int x ){
//	L[++L[0]]=x;  could've been worse
	L[0]++;
	int len=L[0];
	L[len]=x;
}

void insertFront( int L[], int x ){
	L[0]++;
	int len=L[0];

	for(int i=len;i>1;i--)
		L[i]=L[i-1];

	L[1]=x;
}

int isEmpty( int L[] ){
	if(L[0]==0)
		return 1;
return 0;}

int isFull( int L[] ){
	if(L[0]>=LSize-1)//if overfilled, still return full; -1 because 50 total spots in array for list, L[0] is not part of the list. 
		return 1;
return 0;}
 
void printList( int L[] ){
	for(int i=1;i<=L[0];i++)
		printf("%2d ",L[i]);
	printf("\n");
}

int main(){
	int L[LSize] = {0};
	int x, i;

	srand( 3 );

	if (isEmpty(L))
	   printf("1 empty\n");
	else
	   printf("1 notempty\n");

	if (isFull(L))
	   printf("1 full\n");
	else
	   printf("1 notfull\n");


	x = rand() % 100;
	insertEnd( L, x );  
	printList( L );
	x = rand() % 100;
	insertEnd( L, x );  
	printList( L );


	if (isEmpty(L))
	   printf("2 empty\n");
	else
	   printf("2 notempty\n");

	if (isFull(L))
	   printf("2 full\n");
	else
	   printf("2 notfull\n");


	for (i = 0; i < 5; ++i)
	{
	   x = rand() % 100;
	   insertEnd( L, x );  
	   printList( L );
	}
	for (i = 0; i < 5; ++i)
	{
	   x = rand() % 100;
	   insertFront( L, x );  
	   printList( L );
	}

	if (isEmpty(L))
	   printf("3 empty\n");
	else
	   printf("3 notempty\n");

	if (isFull(L))
	   printf("3 full\n");
	else
	   printf("3 notfull\n");


return 0;}
