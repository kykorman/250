#include <stdio.h>
int twice(int num){
	return num*2;
}
int square(int num){
	return num*num;
}
void countUp(int low, int high){
	for(int i=low;i<=high;i++){
		printf("%d ", i);
	}
	printf("\n");
}

void countDown(int low, int high){
	for(int i=high;i>=low;i--){
		printf("%d ", i);
	}
	printf("\n");
}

void countBetween(int one, int two){
	if(one>two)
		countDown(two,one);
	else
		countUp(one,two);
}

int main(){
	printf("Twice 41: %d\n", twice(41));
	printf("Square 41: %d\n", square(41));

	countUp(3,7);
	countDown(3,7);
	countBetween(3,7);
	countBetween(7,3);
return 0;}
