#include <Arduino.h>
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

/**
 * Method that draws the bitmap Picture, Put to the bottom becasue 
 *      it is too long and don't have any value to read.
 */
void draw();

/**
 * Display "(｡･ω･｡)" on screen
 * More emoji is originally planned but would take way to much time to manually punching in bit map data.
 */
void showEmoji()
{
    u8g.firstPage();
    do
    {
        draw();
    } while (u8g.nextPage());
}

// DON't Format this!

void draw(){
    u8g.drawPixel( 27, 20);
    u8g.drawPixel( 28, 20);
    u8g.drawPixel(102, 20);
    u8g.drawPixel(103, 20);
    u8g.drawPixel( 26, 21);
    u8g.drawPixel( 27, 21);
    u8g.drawPixel( 28, 21);
    u8g.drawPixel(103, 21);
    u8g.drawPixel(104, 21);
    u8g.drawPixel( 26, 22);
    u8g.drawPixel( 27, 22);
    u8g.drawPixel(103, 22);
    u8g.drawPixel(104, 22);
    u8g.drawPixel( 25, 23);
    u8g.drawPixel( 26, 23);
    u8g.drawPixel( 27, 23);
    u8g.drawPixel(104, 23);
    u8g.drawPixel(105, 23);
    u8g.drawPixel( 25, 24);
    u8g.drawPixel( 26, 24);
    u8g.drawPixel(104, 24);
    u8g.drawPixel(105, 24);
    u8g.drawPixel( 25, 25);
    u8g.drawPixel( 26, 25);
    u8g.drawPixel(104, 25);
    u8g.drawPixel(105, 25);
    u8g.drawPixel( 24, 26 );
    u8g.drawPixel( 25, 26 );
    u8g.drawPixel(105, 26 );
    u8g.drawPixel(106, 26 );
    u8g.drawPixel( 24, 27);
    u8g.drawPixel( 25, 27);
    u8g.drawPixel(105, 27);
    u8g.drawPixel(106, 27);
    u8g.drawPixel( 24, 28);
    u8g.drawPixel( 25, 28);
    u8g.drawPixel( 59, 28);
    u8g.drawPixel( 71, 28);
    u8g.drawPixel(105, 28);
    u8g.drawPixel(106, 28);
    u8g.drawPixel( 24, 29);
    u8g.drawPixel( 25, 29);
    u8g.drawPixel( 59, 29);
    u8g.drawPixel( 60, 29);
    u8g.drawPixel( 70, 29);
    u8g.drawPixel( 71, 29);
    u8g.drawPixel( 72, 29);
    u8g.drawPixel(105, 29);
    u8g.drawPixel(106, 29);
    u8g.drawPixel( 24, 30);
    u8g.drawPixel( 25, 30);
    u8g.drawPixel( 58, 30);
    u8g.drawPixel( 59, 30);
    u8g.drawPixel( 71, 30);
    u8g.drawPixel( 72, 30);
    u8g.drawPixel(106, 30);
    u8g.drawPixel(107, 30);
    u8g.drawPixel( 24, 31);
    u8g.drawPixel( 25, 31);
    u8g.drawPixel( 48, 31);
    u8g.drawPixel( 49, 31);
    u8g.drawPixel( 50, 31);
    u8g.drawPixel( 58, 31);
    u8g.drawPixel( 59, 31);
    u8g.drawPixel( 71, 31);
    u8g.drawPixel( 72, 31);
    u8g.drawPixel( 80, 31);
    u8g.drawPixel( 81, 31);
    u8g.drawPixel( 82, 31);
    u8g.drawPixel(106, 31);
    u8g.drawPixel(107, 31);
    u8g.drawPixel( 24, 32);
    u8g.drawPixel( 25, 32);
    u8g.drawPixel( 48, 32);
    u8g.drawPixel( 49, 32);
    u8g.drawPixel( 50, 32);
    u8g.drawPixel( 57, 32);
    u8g.drawPixel( 58, 32);
    u8g.drawPixel( 59, 32);
    u8g.drawPixel( 65, 32);
    u8g.drawPixel( 66, 32);
    u8g.drawPixel( 72, 32);
    u8g.drawPixel( 73, 32);
    u8g.drawPixel( 80, 32);
    u8g.drawPixel( 81, 32);
    u8g.drawPixel( 82, 32);
    u8g.drawPixel(106, 32);
    u8g.drawPixel(107, 32);
    u8g.drawPixel( 24, 33);
    u8g.drawPixel( 25, 33);
    u8g.drawPixel( 48, 33);
    u8g.drawPixel( 49, 33);
    u8g.drawPixel( 50, 33);
    u8g.drawPixel( 57, 33);
    u8g.drawPixel( 58, 33);
    u8g.drawPixel( 59, 33);
    u8g.drawPixel( 65, 33);
    u8g.drawPixel( 66, 33);
    u8g.drawPixel( 72, 33);
    u8g.drawPixel( 73, 33);
    u8g.drawPixel( 80, 33);
    u8g.drawPixel( 81, 33);
    u8g.drawPixel( 82, 33);
    u8g.drawPixel(106, 33);
    u8g.drawPixel(107, 33);
    u8g.drawPixel( 25, 34);
    u8g.drawPixel( 26, 34);
    u8g.drawPixel( 57, 34);
    u8g.drawPixel( 58, 34);
    u8g.drawPixel( 65, 34);
    u8g.drawPixel( 66, 34);
    u8g.drawPixel( 72, 34);
    u8g.drawPixel( 73, 34);
    u8g.drawPixel(106, 34);
    u8g.drawPixel(107, 34);
    u8g.drawPixel( 25, 35);
    u8g.drawPixel( 26, 35);
    u8g.drawPixel( 57, 35);
    u8g.drawPixel( 58, 35);
    u8g.drawPixel( 65, 35);
    u8g.drawPixel( 66, 35);
    u8g.drawPixel( 72, 35);
    u8g.drawPixel( 73, 35);
    u8g.drawPixel(106, 35);
    u8g.drawPixel(107, 35);
    u8g.drawPixel( 25, 36);
    u8g.drawPixel( 26, 36);
    u8g.drawPixel( 57, 36);
    u8g.drawPixel( 58, 36);
    u8g.drawPixel( 65, 36);
    u8g.drawPixel( 66, 36);
    u8g.drawPixel( 72, 36);
    u8g.drawPixel( 73, 36);
    u8g.drawPixel(105, 36);
    u8g.drawPixel(106, 36);
    u8g.drawPixel( 25, 37);
    u8g.drawPixel( 26, 37);
    u8g.drawPixel( 57, 37);
    u8g.drawPixel( 58, 37);
    u8g.drawPixel( 65, 37);
    u8g.drawPixel( 66, 37);
    u8g.drawPixel( 72, 37);
    u8g.drawPixel( 73, 37);
    u8g.drawPixel(105, 37);
    u8g.drawPixel(106, 37);
    u8g.drawPixel( 25, 38);
    u8g.drawPixel( 26, 38);
    u8g.drawPixel( 34, 38);
    u8g.drawPixel( 35, 38);
    u8g.drawPixel( 36, 38);
    u8g.drawPixel( 37, 38);
    u8g.drawPixel( 58, 38);
    u8g.drawPixel( 59, 38);
    u8g.drawPixel( 65, 38);
    u8g.drawPixel( 66, 38);
    u8g.drawPixel( 72, 38);
    u8g.drawPixel( 92, 38);
    u8g.drawPixel( 93, 38);
    u8g.drawPixel( 94, 38);
    u8g.drawPixel( 95, 38);
    u8g.drawPixel(105, 38);
    u8g.drawPixel(106, 38);
    u8g.drawPixel( 26, 39);
    u8g.drawPixel( 27, 39);
    u8g.drawPixel( 33, 39);
    u8g.drawPixel( 34, 39);
    u8g.drawPixel( 35, 39);
    u8g.drawPixel( 36, 39);
    u8g.drawPixel( 37, 39);
    u8g.drawPixel( 38, 39);
    u8g.drawPixel( 58, 39);
    u8g.drawPixel( 59, 39);
    u8g.drawPixel( 64, 39);
    u8g.drawPixel( 65, 39);
    u8g.drawPixel( 66, 39);
    u8g.drawPixel( 71, 39);
    u8g.drawPixel( 72, 39);
    u8g.drawPixel( 91, 39);
    u8g.drawPixel( 92, 39);
    u8g.drawPixel( 93, 39);
    u8g.drawPixel( 94, 39);
    u8g.drawPixel( 95, 39);
    u8g.drawPixel(104, 39);
    u8g.drawPixel(105, 39);
    u8g.drawPixel(106, 39);
    u8g.drawPixel( 26, 40);
    u8g.drawPixel( 27, 40);
    u8g.drawPixel( 33, 40);
    u8g.drawPixel( 34, 40);
    u8g.drawPixel( 38, 40);
    u8g.drawPixel( 39, 40);
    u8g.drawPixel( 58, 40);
    u8g.drawPixel( 59, 40);
    u8g.drawPixel( 60, 40);
    u8g.drawPixel( 63, 40);
    u8g.drawPixel( 64, 40);
    u8g.drawPixel( 66, 40);
    u8g.drawPixel( 67, 40);
    u8g.drawPixel( 68, 40);
    u8g.drawPixel( 69, 40);
    u8g.drawPixel( 70, 40);
    u8g.drawPixel( 71, 40);
    u8g.drawPixel( 90, 40);
    u8g.drawPixel( 91, 40);
    u8g.drawPixel( 95, 40);
    u8g.drawPixel( 96, 40);
    u8g.drawPixel(104, 40);
    u8g.drawPixel(105, 40);
    u8g.drawPixel( 26, 41);
    u8g.drawPixel( 27, 41);
    u8g.drawPixel( 33, 41);
    u8g.drawPixel( 38, 41);
    u8g.drawPixel( 39, 41);
    u8g.drawPixel( 60, 41);
    u8g.drawPixel( 61, 41);
    u8g.drawPixel( 62, 41);
    u8g.drawPixel( 63, 41);
    u8g.drawPixel( 67, 41);
    u8g.drawPixel( 68, 41);
    u8g.drawPixel( 69, 41);
    u8g.drawPixel( 70, 41);
    u8g.drawPixel( 90, 41);
    u8g.drawPixel( 91, 41);
    u8g.drawPixel( 95, 41);
    u8g.drawPixel( 96, 41);
    u8g.drawPixel(104, 41);
    u8g.drawPixel(105, 41);
    u8g.drawPixel( 27, 42);
    u8g.drawPixel( 28, 42);
    u8g.drawPixel( 33, 42);
    u8g.drawPixel( 34, 42);
    u8g.drawPixel( 38, 42);
    u8g.drawPixel( 39, 42);
    u8g.drawPixel( 90, 42);
    u8g.drawPixel( 91, 42);
    u8g.drawPixel( 95, 42);
    u8g.drawPixel( 96, 42);
    u8g.drawPixel(103, 42);
    u8g.drawPixel(104, 42);
    u8g.drawPixel( 27, 43);
    u8g.drawPixel( 28, 43);
    u8g.drawPixel( 34, 43);
    u8g.drawPixel( 35, 43);
    u8g.drawPixel( 36, 43);
    u8g.drawPixel( 37, 43);
    u8g.drawPixel( 38, 43);
    u8g.drawPixel( 91, 43);
    u8g.drawPixel( 92, 43);
    u8g.drawPixel( 93, 43);
    u8g.drawPixel( 94, 43);
    u8g.drawPixel( 95, 43);
    u8g.drawPixel(103, 43);
    u8g.drawPixel(104, 43);
    u8g.drawPixel( 28, 44);
    u8g.drawPixel( 29, 44);
    u8g.drawPixel( 35, 44);
    u8g.drawPixel( 36, 44);
    u8g.drawPixel( 93, 44);
    u8g.drawPixel(102, 44);
    u8g.drawPixel(103, 44);
}