#include<stdbool.h>
bool tie(char** board,int num_rows,int num_cols)
{
 /*
   Function to check if the game is a tie
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @return:True or false depending on the whether the game has been tied
 */
 int i,j;
 for(i=0;i<num_rows;i++)
    {
     for(j=0;j<num_cols;j++)
        {
         if(board[i][j]=='*')
           {
            return false;
           }
        }
    }
 return true;
}//end of function
bool horiz_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the win was due to the same elements being in the same row
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int count,i,j;
 char first;
 for(i=0;i<num_rows;i++)
    {
     first=board[i][0];
     count=1;
     for(j=1;j<num_cols;j++)
        {
         if(first!='*')
           {
            if(board[i][j]==first)
              {
               count+=1;
               if(count==num_to_win)
                 {
                  return true;
                 }
              }
            else
            {
             first=board[i][j];
             count=1;
            }
           }
         else
         {
          first=board[i][j];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool vert_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the win was due to the same elements being in the same column
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int count,i,j;
 char first;
 for(i=0;i<num_cols;i++)
    {
     first=board[0][i];
     count=1;
     for(j=1;j<num_rows;j++)
        {
         if(first!='*')
           {
            if(board[j][i]==first)
              {
               count+=1;
               if(count==num_to_win)
                 {
                  return true;
                 }
              }
            else
            {
             first=board[j][i];
             count=1;
            }
           }
         else
         {
          first=board[j][i];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool left_diag_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the same elements are on the diagonals of the board
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int i,j,count=1;
 char first=board[0][0];
 for(i=1;i<num_rows;i++)
    {
     for(j=1;j<num_cols;j++)
        {
         if(first!='*')
           {
            if(i==j)
              {
               if(board[i][j]==first)
                 {
                  count+=1;
                  if(count==num_to_win)
                    {
                     return true;
                    }
                 }
               else
               {
                first=board[i][j];
                count=1;
               }
              }
           }
         else
         {
          first=board[i][j];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool right_diag_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the same elements were on the diagonals of the board
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int i,j,count=1;
 char first=board[0][num_cols-1];
 for(i=1;i<num_rows;i++)
    {
     for(j=0;j<num_cols-1;j++)
        {
         if(first!='*')
           {
            if(i+j==num_cols-1)
              {
               if(board[i][j]==first)
                 {
                  count+=1;
                  if(count==num_to_win)
                    {
                     return true;
                    }
                 }
               else
               {
                first=board[i][j];
                count=1;
               }
              }
           }
         else
         {
          first=board[i][j];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool left_lower_diag_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the same elements are on the diagonals of the board
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int i,j,count=1;
 char first=board[num_rows-1][0];
 for(i=num_rows-1;i>=0;i--)
    {
     for(j=1;j<num_cols;j++)
        {
         if(first!='*')
           {
            if(i+j==num_rows-1)
              {
               if(board[i][j]==first)
                 {
                  count+=1;
                  if(count==num_to_win)
                    {
                     return true;
                    }
                 }
               else
               {
                first=board[i][j];
                count=1;
               }
              }
           }
         else
         {
          first=board[i][j];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool right_lower_diag_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the same elements are on the diagonals of the board
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 int i,j,count=1;
 char first=board[num_rows-1][num_cols-1];
 for(i=num_rows-1-1;i>=0;i--)
    {
     for(j=num_cols-1-1;j>=0;j--)
        {
         if(first!='*')
           {
            if(j==i+1)
              {
               if(board[i][j]==first)
                 {
                  count+=1;
                  if(count==num_to_win)
                    {
                     return true;
                    }
                 }
               else
               {
                first=board[i][j];
                count=1;
               }
              }
           }
         else
         {
          first=board[i][j];
          count=1;
         }
        }
    }
 return false;
}//end of function
bool diag_win(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the same elements were on the diagonals
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 return left_diag_win(board,num_rows,num_cols,num_to_win)||right_diag_win(board,num_rows,num_cols,num_to_win)||left_lower_diag_win(board,num_rows,num_cols,num_to_win)||right_lower_diag_win(board,num_rows,num_cols,num_to_win);
}//end of function
bool won(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the game has a winner
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive places that are essential for a win
   @return:True or false depending on whether there is a winner or not
 */
 return horiz_win(board,num_rows,num_cols,num_to_win)||vert_win(board,num_rows,num_cols,num_to_win)||diag_win(board,num_rows,num_cols,num_to_win);
}//end of function
bool game_over(char** board,int num_rows,int num_cols,int num_to_win)
{
 /*
   Function to check if the game is over
   @board:The board on which the game will be played on
   @num_rows:Number of rows in the board
   @num_cols:Number of columns in the board
   @num_to_win:Number of successive pieces that are essential for a win
   @return:True or false depending on the result of the game
 */
 return tie(board,num_rows,num_cols)||won(board,num_rows,num_cols,num_to_win);//the game will only be over when the game has either been tied or has been won by a player
}//end of function
