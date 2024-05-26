#include <stdio.h>
#include <wiringPi.h>
#include <wiringShift.h>

#define ROWS 8
#define COLS 8

void draw_cells(int cells[COLS][ROWS], int dataPin, int latchPin, int clockPin);
void _shiftOut_col(int dPin, int cPin, int order, int col[ROWS]);
void _shiftOut(int dPin, int cPin, int order, int val);
