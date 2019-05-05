/*
  Name:Varun Peesapati
  Due Date:November 11 2016
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
#include"board.h"
#include"win.h"
bool checkFormatting(int num_args_read,int num_args_need)
{
 /*
   Function to check if the user input is valid
   @num_args_read:Number of arguments read by the scanf() function
   @num_args_need:Number of arguments needed to be read by the scanf() function
   @return:True if user input is valid, false otherwise
 */
 bool isValid=true;
 char new_line='\n';
 if(num_args_read!=num_args_need)
   {
    isValid=false;
   }
 do
 {
  scanf("%c",&new_line);
  if(!isspace(new_line))//checking for whitespace
    {
     isValid=false;
    }
 }while(new_line!='\n');
 return isValid;
}//end of function
int validInt(char** board,int num_cols)
{
 /*
   Function that checks if the user has entered a valid positive integer
   @board:The board on which the game will be played on
   @num_cols:The number of columns in the board
   @return:A valid positive integer
 */
 int x,num_args_read;
 do
 {
  printf("Enter a column between 0 and %d to play in: ",num_cols-1);
  num_args_read=scanf("%d",&x);
 }while(!(checkFormatting(num_args_read,1))||x<0||x>=num_cols||board[0][x]!='*');
 return x;
}//end of function
void checkNumArgs(int num_args)
{
 /*
   Function to check the number of arguments that have been inputted in the command line argument
   @num_args:Number of arguments
   @return:None(Since it has 'void' as its return type
 */
 if(num_args<4)
   {
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
    exit(0);//exitting the program
   }
 else if(num_args>4)
        {
         printf("Too many arguments entered\n");
         printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
         exit(0);//exitting the program
        }
}//end of function
void readArgs(char* args[],int* num_rows,int* num_cols,int* num_to_win)
{
 /*
   Function to read the arguments into a different variable
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of pieces that need to be in a row to win
   @return:None(Since it has 'void' as its return type
 */
 sscanf(args[1],"%d",num_rows);//reads the second element of the array into num_rows
 sscanf(args[2],"%d",num_cols);//reads the third element of the array into num_cols
 sscanf(args[3],"%d",num_to_win);//reads the fourth element of the array into num_to_win
}//end of function
void declareWinner(char** board,int num_rows,int num_cols,int num_to_win,int turn)
{
 /*
   Function that declares the winner of the game
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of pieces that need to be in a row to win
   @turn:Number of turns played
 */
 if(tie(board,num_rows,num_cols)&&!won(board,num_rows,num_cols,num_to_win))//if the game has been tied
   {
    printf("Tie game!\n");
   }
 else if(turn%2==0)//if there is a winner
        {
         printf("Player 2 Won!\n");
        }
 else
 {
  printf("Player 1 Won!\n");
 }
}//end of function
void play(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to play the game
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of pieces that need to be in a row to win
   @return:None(Since it has 'void' as its return type)
 */
 int i,turn=0,cols;
 printBoard(board,num_rows,num_cols);
 while(!game_over(board,num_rows,num_cols,num_to_win))//while the game is not over
      {
       cols=validInt(board,num_cols);
       for(i=num_rows-1;i>=0;i--)
          {
           if(board[i][cols]=='*')
             {
              if(turn%2==0)
                {
                 board[i][cols]='X';
                 break;
                }
              else
              {
               board[i][cols]='O';
               break;
              }
             }
          }
       printBoard(board,num_rows,num_cols);
       turn++;
       if(num_to_win==1)
         {
          break;
         }
      }
  declareWinner(board,num_rows,num_cols,num_to_win,turn);
}//end of function
int main(int num_args,char* args[])
{
 /*
   The main() function
   @num_args:Number of arguments
   @args:An array of all the arguments stored as strings
 */
 char** board;
 int num_rows,num_cols,num_to_win;
 /*
   board:The board on which the game will be played on
   num_rows:Number of rows in the board
   num_cols:Number of columns in the board
   num_to_win:Number of pieces that need to be in a row to win
 */
 checkNumArgs(num_args);
 readArgs(args,&num_rows,&num_cols,&num_to_win);
 board=createBoard(num_rows,num_cols);
 play(board,num_rows,num_cols,num_to_win);
 deleteBoard(board,num_rows,num_cols);
 return 0;
}//end of main
