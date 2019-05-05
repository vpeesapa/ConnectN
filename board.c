#include"board.h"
#include<stdio.h>
#include<stdlib.h>
char** createBoard(int num_rows,int num_cols)
{
 /*
   Function to create a board
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:A num_rows*num_cols board
 */
 int i,j;
 char** board=(char **)malloc(num_rows*sizeof(char *));//creating an empty board of given size
 for(i=0;i<num_rows;i++)
    {
     board[i]=(char *)malloc(num_cols*sizeof(char));//creating an array for that particular row
     for(j=0;j<num_cols;j++)
        {
         board[i][j]='*';//creating a 2D character array with all its elements being asterisks
        }
    }
 return board;
}//end of function
void printBoard(char** board,int num_rows,int num_cols)
{
 /*
   Function to print the board
   @board:The board that needs to be printed
   @num_rows:The number of rows in the board
   @num_cols:The number of columns in the board
   @return:None(Since it has 'void' as its return type)
 */
 int i,j,k=num_rows-1;
 for(i=0;i<num_rows;i++)
    {
     printf("%d ",k--);
     for(j=0;j<num_cols;j++)
        {
         printf("%c ",board[i][j]);
        }
     printf("\n");
    }
 printf("  ");
 for(j=0;j<num_cols;j++)
    {
     printf("%d ",j);
    }
 printf("\n");
}//end of function
void deleteBoard(char** board,int num_rows,int num_cols)
{
 /*
   Function to free the memory allocated for the board
   @board:That board that needs to be removed
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @return:None(Since it has 'void' as its return type)
 */
 int i;
 for(i=0;i<num_rows;i++)
    {
     free(board[i]);//freeing each column of the board
    }
 free(board);//freeing the entire board
}//end of function
