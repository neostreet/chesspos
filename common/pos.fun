/*** Chesspos function declarations ***/

int read_position(char *filename,unsigned char *board);

void set_initial_board(unsigned char *board);

int get_piece1(unsigned char *board,int board_offset);
int get_piece2(unsigned char *board,int rank,int file);
void set_piece1(unsigned char *board,int board_offset,int piece);
void set_piece2(unsigned char *board,int rank,int file,int piece);

void print_bd0(unsigned char *board,int orientation);
