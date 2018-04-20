#include <stdio.h>
void chngPtr(int *x, int *y, int **ptr){
	*ptr=y;
}
int main(){
	int x=1900;

	int *ptr=&x;
	int y=10;

	chngPtr(&x,&y,&ptr);
	printf("%d\n",*ptr);
return 0;}
