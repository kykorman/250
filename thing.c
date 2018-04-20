#include <stdio.h>
#include <string.h>
void printBoard(char board[][4]);
void arrangeBoard(char board[][4],char str[]);
int checkWin(char board[][4]);
void getBoard(char board[]);
int main(){
        printf("Enter your tic tac toe board as one string\n");
        char buff[10]="";
        char board[3][4]={""};//Then I have a /0 at the end of each for printf("%s\n",board[i]);

        getBoard(buff);
        arrangeBoard(board,buff);
        printBoard(board);
        int res=checkWin(board);
        if(res!=0){
                if(res/10==2)
                        printf("x won by means of ");
                else
                        printf("o won by means of ");
                switch(res%10){
                        case 1:printf("top row completion");break;
                        case 2:printf("middle row completion");break;
                        case 3:printf("bottom row completion");break;
                        case 4:printf("left column completion");break;
                        case 5:printf("middle column completion");break;
                        case 6:printf("right column completion");break;
                        case 7:printf("top left to bottom right diagonal completion");break;
                        case 8:printf("top right to bottom left diagonal completion");break;


                }
        }else
                printf("No winner");
        puts("");
return 0;}

void getBoard(char board[]){
        fgets(board,10,stdin);
}
void arrangeBoard(char board[][4],char str[]){
        int count=0;
        for(int i=0;i<3;i++)
                for(int k=0;k<3;k++){
                        if(str[count]=='x'||str[count]=='o')
                                board[i][k]=str[count];
                        else
                                board[i][k]=' ';
                        count++;
                }

}
void printBoard(char board[][4]){
        for(int i=0;i<3;i++)
                printf("%s\n",board[i]);

}

int checkWin(char board[][4]){
        if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]){
                if(board[0][0]=='x')
                        return 27;
                else if(board[0][0]=='o')
                        return 37;
        }if(board[2][0]==board[1][1]&&board[1][1]==board[0][2]){
                if(board[2][0]=='x')
                        return 28;
                else if(board[2][0]=='o')
                        return 38;
        }for(int i=0;i<3;i++){
                if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]){
                        if(board[i][0]=='x')
                                return 20+1+i;
                        else if(board[i][0]=='o')
                                return 30+1+i;
                }if(board[0][i]==board[1][i]&&board[1][i]==board[2][i]){
                        if(board[0][i]=='x')
                                return 20+i+4;
                        else if(board[0][i]=='o')
                                return 30+i+4;
                }
        }

return 0;}
