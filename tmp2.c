#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	for(int i=0;i<9;i++){
		int tmp=rand()%5;
		switch(tmp){
			case 0 ... 1:printf("o");break;
			case 2 ... 3:printf("x");break;
			case 4:printf(" ");break;
		}
	}

return 0;}
