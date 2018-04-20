#include <stdio.h>
#include <string.h>

void reverseString(char s1[],char s2[]){
	int len=strlen(s1);
	for(int i=0;i<len;i++)
		s2[i]=s1[len-1-i];

}

int main(){
	char s1[100]="",s2[100]="";

	printf("Enter string: ");
	scanf("%s",s1);

	reverseString(s1,s2);
	printf("String reversed is: %s\n",s2);
return 0;}
