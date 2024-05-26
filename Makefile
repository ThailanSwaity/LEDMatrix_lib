LEDMatrix: LEDMatrix.c matrix_draw.c 
	gcc -o LEDMatrix LEDMatrix.c matrix_draw.c -lwiringPi -I.
