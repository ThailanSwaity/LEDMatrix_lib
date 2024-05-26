#include "matrix_draw.h"

void draw_cells(int cells[ROWS][COLS], int dataPin, int latchPin, int clockPin) {
  int i, j;
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      printf("%d ", cells[i][j]);
    }
    printf("\n");
  }

  unsigned char x = 0x80;
  for (i = 0; i < ROWS; i++) {
    digitalWrite(latchPin, LOW);
    _shiftOut(dataPin, clockPin, MSBFIRST, cells[ROWS]);
    _shiftOut(dataPin, clockPin, MSBFIRST, ~x);
    digitalWrite(latchPin, HIGH);
    x>>=1;
    delay(1);
  }
}

void _shiftOut(int dPin, int cPin, int order, int col[COLS]) {
  int i;
  for (i = 0; i < COLS; i++) {
    digitalWrite(cPin, LOW);
    if (order == LSBFIRST) {
      digitalWrite(dPin, col[i] ? HIGH : LOW);
      delayMicroseconds(10);
    } else {
      digitalWrite(dPin, col[COLS - i] ? HIGH : LOW);
      delayMicroseconds(10);
    }
  }
}

void _shiftOut(int dPin, int cPin, int order, int val) {
  int i;
  for (i = 0; i < 8; i++) {
    digitalWrite(cPin, LOW);
    if (order == LSBFIRST) {
      digitalWrite(dPin, ((0x01&(val>>i)) == 0x01) ? HIGH : LOW);
      delayMicroseconds(10);
    } else {
      digitalWrite(dPin, ((0x80&(val<<i)) == 0x80) ? HIGH : LOW);
    }
    digitalWrite(cPin, HIGH);
    delayMicroseconds(10);
  }
}
