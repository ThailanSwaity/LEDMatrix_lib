#include <stdio.h>
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

void init(void);

int main(void) {

  wiringPiSetup();

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  init();

  return 0;
}

void init(void) {

  int cells[COLS][ROWS] = {0};

  cells[3][0] = cells[3][7] = 1;
  cells[4][0] = cells[4][7] = 1;
  cells[5][0] = cells[5][7] = 1;

  cells[2][1] = cells[2][6] = 1;
  cells[6][1] = cells[6][6] = 1;

  cells[1][2] = cells[1][5] = 1;
  cells[3][2] = cells[3][5] = 1;
  cells[7][2] = cells[7][5] = 1;

  cells[1][3] = cells[1][4] = 1;
  cells[5][3] = cells[5][4] = 1;
  cells[7][3] = cells[7][4] = 1;
  
  draw_cells(cells, dataPin, latchPin, clockPin);

}
