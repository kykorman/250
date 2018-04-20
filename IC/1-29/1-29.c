#include <stdio.h>

// Kyle Korman

int main(){
	int count=1,r,c;
	printf("Enter rows: ");
	scanf("%d",&r);
	printf("Enter columns: ");
	scanf("%d",&c);

	int nums[r][c];
	for(int i=0;i<r;i++)
		for(int k=0;k<c;k++){
			nums[i][k]=count;
			count++;
		}
	for(int i=0;i<r;i++){
		for(int k=0;k<c;k++){
			printf("%2d ",nums[i][k]);
		}
		printf("\n");
	}
	printf("\n\n");
	
	count=1;

	for(int i=0;i<c;i++)
		for(int k=0;k<r;k++){
			nums[k][i]=count;
			count++;
		}
	for(int i=0;i<r;i++){
		for(int k=0;k<c;k++){
			printf("%2d ",nums[i][k]);
		}
		printf("\n");
	}

return 0;}

