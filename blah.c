#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv){
        if(argc==1){
                printf("No input file entered. Enter   %s [filename]   to use this program\n",argv[0]);
                exit(1);
        }
        int r,c;
        FILE *in;

        in=fopen(argv[1],"r");

        if(in==NULL){
                printf("Invalid file\n");
                exit(1);
        }
        fscanf(in,"%d",&r);
        fscanf(in,"%d",&c);

        char str[r*c];
        int Arr[r][c];


        for(int i=0;i<r;i++)
                for(int k=0;k<c;k++)
                        fscanf(in,"%d",&Arr[i][k]);
        int count=0;
        for(int i=0;i<r;i++)
                for(int k=0;k<c;k++){
                        int colRet=-1,rowRet=-1;

                        for(int p=0;p<r;p++)
                                if(Arr[p][k]==Arr[i][k])
                                        colRet++;
                        for(int p=0;p<c;p++)
                                if(Arr[i][p]==Arr[i][k])
                                        rowRet++;


//Went with this solution because I didn't want to work with an array of strings and printing it out on one line
//Even though it's easier than printing one string on multiple lines, it was just how I felt when I was coding it
                        if(colRet>0&&rowRet>0)
                                str[count]='+';
                        else if(colRet>0)
                                str[count]='|';
                        else if(rowRet>0)
                                str[count]='-';
                        else
                                str[count]=' ';
                        count++;
                }
        printf("As a grid\n");
        for(int i=0;i<(r*c);i++){
                printf("%c",str[i]);
                if(i%c==c-1)
                        puts("");
        }
        printf("End of grid\n");
        printf("\n\nAs one string\n");
        for(int i=0;i<(r*c);i++)
                printf("%c",str[i]);
        printf("End of String\n");



return 0;}
