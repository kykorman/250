/*
	Read 2 words from the user; w1 and w2
		max length is 50
	How many letters from w1 are also in w2

Decided to go with this instead of starting a for at 0 and 
working up to 127 for the ascii values because a for in a for in a for would likely
take longer and I don't need to reprint the strings 
so I am confortable modifying them (could strcpy if need be)

*/

#include <stdio.h>
#include <string.h>

void delDuplicates(char str[]);
int countDuplicates(char str1[],char str2[]);
int main()
{
	char w1[50], w2[50];
	int len1, len2;
	int count = 0;

	printf("Enter word1: ");
	fgets( w1, 50, stdin);
	len1 = strlen( w1 );
	len1--;
	w1[len1] = '\0';

	printf("Enter word2: ");
	fgets( w2, 50, stdin);
	len2 = strlen( w2 );
	len2--;
	w2[len2] = '\0';

	count = countDuplicates(w1,w2);

	printf("Final count: %d\n", count);

	return 0;
}
void delDuplicates(char str[]){

	int len=strlen(str);
/*
Selected \n as the symbol to replace with because the only time a user 
could type that in is when they hit enter to submit their answer, and that
has already been removed by the whole \0 stuff up above.
*/
	for(int i=0;i<len;i++)
		if(str[i]!='\n')
			for(int k=i+1;k<len;k++)
				if( str[i]==str[k])
					str[k]='\n';

}

int countDuplicates(char str1[],char str2[]){
	int count=0;

	delDuplicates(str1);
	delDuplicates(str2);

	int len1=strlen(str1);
	int len2=strlen(str2);

	for(int i=0;i<len1;i++)
		if(str1[i]!='\n')
			for(int k=0;k<len2;k++)
				if(str1[i]==str2[k])
					count++;


return count;}
