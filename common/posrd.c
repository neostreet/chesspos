#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#ifdef WIN32
#include <io.h>
#else
#include <unistd.h>
#endif

#include "pos.h"
#include "pos.fun"
#include "pos.glb"
#include "pos.mac"
#include "bitfuns.h"

static unsigned char initial_board[] = {
  (unsigned char)0x23, (unsigned char)0x45, (unsigned char)0x64, (unsigned char)0x32,
  (unsigned char)0x11, (unsigned char)0x11, (unsigned char)0x11, (unsigned char)0x11,
  (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00,
  (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00,
  (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00,
  (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00, (unsigned char)0x00,
  (unsigned char)0xff, (unsigned char)0xff, (unsigned char)0xff, (unsigned char)0xff,
  (unsigned char)0xed, (unsigned char)0xcb, (unsigned char)0xac, (unsigned char)0xde
};

int get_piece_type_ix(int chara)
{
  int n;

  for (n = 0; n < NUM_PIECE_TYPES; n++)
    if (chara == piece_ids[n])
      return n;

  return 0; /* should never happen */
}

void set_initial_board(unsigned char *board)
{
  int n;

  for (n = 0; n < CHARS_IN_BOARD; n++)
    board[n] = initial_board[n];
}

int read_game_position(char *filename,struct game_position *position_pt)
{
  int fhndl;
  unsigned int bytes_to_read;
  unsigned int bytes_read;

  if ((fhndl = open(filename,O_RDONLY | O_BINARY)) == -1)
    return 1;

  bytes_to_read = sizeof (struct game_position);

  bytes_read = read(fhndl,(char *)position_pt,bytes_to_read);

  if (bytes_read != bytes_to_read) {
    close(fhndl);
    return 2;
  }

  close(fhndl);

  return 0;
}

int write_game_position(char *filename,struct game_position *position_pt)
{
  int fhndl;
  unsigned int bytes_to_write;
  unsigned int bytes_written;

  if ((fhndl = open(filename,O_CREAT | O_TRUNC | O_WRONLY | O_BINARY,
      S_IREAD | S_IWRITE)) == -1)
    return 1;

  bytes_to_write = sizeof (struct game_position);

  bytes_written = write(fhndl,(char *)position_pt,bytes_to_write);

  if (bytes_written != bytes_to_write) {
    close(fhndl);
    return 2;
  }

  close(fhndl);

  return 0;
}
