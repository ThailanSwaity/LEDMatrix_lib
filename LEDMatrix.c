#include <stdio.h>
#include <time.h>
#include <string.h>

#include "matrix_draw.h"

#define dataPin  0 // DS Pin of 74HC595
#define latchPin 2 // ST_CP Pin of 74HC595
#define clockPin 3 // SH_CP Pin of 74HC595

// column data of the smily face
unsigned char pic[]={0x1c,0x22,0x51,0x45,0x45,0x51,0x22,0x1c};
                    //0    0    1    1    1    1    0    0
                    //0    1    0    0    0    0    1    0
                    //1    0    0    1    1    0    0    1
                    //1    0    0    0    0    0    0    1
                    //1    0    1    0    0    1    0    1
                    //0    1    0    0    0    0    1    0
                    //0    0    1    1    1    1    0    0
                    //0    0    0    0    0    0    0    0
//
clock_t last_update_time;
int cells[COLS][ROWS] = {0};
int debug_index;

void run(void);
void update(void);
void debug_graphic(void);
int neighbours(int col, int row);
int modulo(int x, int N);

int main(void) {

  wiringPiSetup();

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  run();

  return 0;
}

void run(void) {
//  cells[3][0] = cells[3][7] = 1;
//  cells[4][0] = cells[4][7] = 1;
//  cells[5][0] = cells[5][7] = 1;
//
//  cells[2][1] = cells[2][6] = 1;
//  cells[6][1] = cells[6][6] = 1;
//
//  cells[1][2] = cells[1][5] = 1;
//  cells[3][2] = cells[3][5] = 1;
//  cells[7][2] = cells[7][5] = 1;
//
//  cells[1][3] = cells[1][4] = 1;
//  cells[5][3] = cells[5][4] = 1;
//  cells[7][3] = cells[7][4] = 1;
  
  cells[1][7] = 1;
  cells[2][6] = 1;
  cells[0][5] = 1;
  cells[1][5] = 1;
  cells[2][5] = 1;

  last_update_time = clock();
  debug_index = 0;
  
  while(1) {

    // Updates every second
    if (clock() - last_update_time >= 10000) {
      update();

      last_update_time = clock();
    }

    draw_cells(cells, dataPin, latchPin, clockPin);
  }

}

void update(void) {
  int t_cells[COLS][ROWS] = {0};

  int col, row;
  for (col = 0; col < COLS; col++) {
    for (row = 0; row < ROWS; row++) {
      int nbours = neighbours(col, row);
      if (cells[col][row] && nbours < 2) {
        t_cells[col][row] = 0;
      } else if (cells[col][row] && (nbours == 2 || nbours == 3)) {
        t_cells[col][row] = 1;
      } else if (cells[col][row] && nbours > 3) {
        t_cells[col][row] = 0;
      } else if (!cells[col][row] && nbours == 3) {
        t_cells[col][row] = 1;
      }
    }
  }

  // Copy memory from the temp array to the array used to display
  memcpy(&cells, &t_cells, sizeof(cells));
}

void debug_graphic(void) {
    cells[debug_index % COLS][debug_index / ROWS] = 1;
      
    debug_index++;
    if (debug_index > COLS * ROWS) {
      debug_index = 0;
    }
}

int neighbours(int col, int row) {
  int i, j;
  int nbours = 0;
  for (i = -1; i < 2; i++) {
    int x = modulo(col + i, COLS);
    for (j = -1; j < 2; j++) {
      int y = modulo(row + j, ROWS);
      if (!(i == 0 && j == 0)) {
        if (cells[x][y]) {
          nbours++;
        }
      }
    }
  }
  return nbours;
}

int modulo(int x, int N) {
  return (x % N + N) % N;
}
