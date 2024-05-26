#include "matrix_draw.h"

void draw_cells(int cells[COLS][ROWS], int dataPin, int latchPin, int clockPin) {
  int i;

  unsigned char x = 0x80;
  for (i = 0; i < COLS; i++) {
    digitalWrite(latchPin, LOW);
    _shiftOut_col(dataPin, clockPin, MSBFIRST, cells[i]); // Shifts out the array of all the column cells
    _shiftOut(dataPin, clockPin, MSBFIRST, ~x);
    digitalWrite(latchPin, HIGH);
    x>>=1;
    delay(1);
  }
}

void _shiftOut_col(int dPin, int cPin, int order, int col[ROWS]) {
  int i;
  for (i = 0; i < ROWS; i++) {
    digitalWrite(cPin, LOW);
    if (order == LSBFIRST) {
      digitalWrite(dPin, col[i] ? HIGH : LOW);
      delayMicroseconds(10);
    } else {
      digitalWrite(dPin, col[ROWS - i] ? HIGH : LOW);
      delayMicroseconds(10);
    }
    digitalWrite(cPin, HIGH);
    delayMicroseconds(10);
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
      delayMicroseconds(10);
    }
    digitalWrite(cPin, HIGH);
    delayMicroseconds(10);
  }
}
