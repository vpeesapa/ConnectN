#ifndef WIN_H
 #define WIN_H
  #include<stdbool.h>
  bool game_over(char** board,int num_rows,int num_cols,int num_to_win);
  bool tie(char** board,int num_rows,int num_cols);
  bool won(char** board,int num_rows,int num_cols,int num_to_win);
  bool horiz_win(char** board,int num_rows,int num_cols,int num_to_win);
  bool vert_win(char** board,int num_rows,int num_cols,int num_to_win);
  bool diag_win(char** board,int num_rows,int num_cols,int num_to_win);
  bool left_diag_win(char** board,int num_rows,int num_cols,int num_to_win);
  bool right_diag_win(char** board,int num_rows,int num_cols,int num_to_win);
#endif
