# Game of Life on 8x8 LED Matrix
This is a noob project. My first involving breadboards and electronic components.
But I think it's pretty cool, and laying out the details here will help me learn even more.

# Details of Assembly
All of the schematics are from the [Freenove Super Starter Kit for Raspberry Pi tutorial pdf](https://github.com/Freenove/Freenove_Super_Starter_Kit_for_Raspberry_Pi).

![20240527_15h46m09s_grim](https://github.com/ThailanSwaity/LEDMatrix_lib/assets/44379381/1faf0cd7-2775-4efa-b059-5f5d403a5c20)

![20240527_15h26m02s_grim](https://github.com/ThailanSwaity/LEDMatrix_lib/assets/44379381/cedb8cf2-8295-43e8-8653-04cf00acf7ed)
![20240527_18h51m16s_grim](https://github.com/ThailanSwaity/LEDMatrix_lib/assets/44379381/f94c32fe-a3db-4d1d-8389-f29f19d024d1)
![20240527_15h26m34s_grim](https://github.com/ThailanSwaity/LEDMatrix_lib/assets/44379381/64c8b244-d7a3-491c-9e4e-fd288d487598)

# Software
To get Game of Life running you will first need to install a library called WiringPi:
```
sudo apt-get update
git clone https://github.com/WiringPi/WiringPi
cd WiringPi
./build
```
To compile and run the executable just use:
```
make
./LEDMatrix
```
If everything is complete, you should see a glider moving across the LED Matrix :)

# Notes
- I used this on a RPi Zero W, but it should work for other Pis that fit this same Pin layout.
- When testing connections to the LED Matrix, it is useful to use the debug function. It fills out all pixels in order starting at the origin.
- When tinkering, be sure to consider the coordinate layout for the LED display. Relative to the location of the label, the layout looks something like this:

![LEDMatrixCoordinateDiagram](https://github.com/ThailanSwaity/LEDMatrix_lib/assets/44379381/0cc9b4ff-1a87-459f-9b30-713f8785f63b)

