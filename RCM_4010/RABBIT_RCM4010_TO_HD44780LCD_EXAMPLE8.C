/***************************************************************************/
/* RABBIT_RCM4010_TO_HD44780LCD_EXAMPLE8.C   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for HD44780-compatible LCD displays connected to Rabbit 3000    */
/* and 4000 Modules. This example demonstrates how to load and display     */
/* custom defined characters on the LCD. Written and tested under Dynamic  */
/* C Version 10.05. DISPLAYSIZE and DISPLAYLINES unset, defaults to 16x2.  */
/* Code examples and details are described in Rabbit`s document TN211.     */
/*                                                                         */
/*                                                       Frank4dd, @2009   */
/***************************************************************************/
#use hd44780lcd.lib
#define INTERFACE 8
#define DISPLAYSIZE 16
#define DISPLAYLINES 2
/* define custom character bitmaps */
const char custom_xbox[8] = {
  0x00,		//.....
  0x1F,		//#####
  0x1B,		//##.##
  0x15,		//#.#.#
  0x1B,		//##.##
  0x1F,		//#####
  0x00,		//.....
  0x00		//.....
};
const char custom_plug[8] = {
  0x0A,		//.#.#.
  0x0A,		//.#.#.
  0x1F,		//#####
  0x11,		//#...#
  0x11,		//#...#
  0x0E,		//.###.
  0x04,		//..#..
  0x04		//..#..
};
const char custom_battery[8] = {
  0x0E,		//.###.
  0x1F,		//#####
  0x11,		//#...#
  0x11,		//#...#
  0x1F,		//#####
  0x1F,		//#####
  0x1F,		//#####
  0x1F		//#####
};
const char custom_w_circle[8] = {
  0x00,		//.....
  0x0E,		//.###.
  0x11,		//#...#
  0x11,		//#...#
  0x11,		//#...#
  0x0E,		//.###.
  0x00,		//.....
  0x00		//.....
};
const char custom_b_circle[8] = {
  0x00,		//.....
  0x0E,		//.###.
  0x1F,		//#####
  0x1F,		//#####
  0x1F,		//#####
  0x0E,		//.###.
  0x00,		//.....
  0x00		//.....
};
const char custom_smiley[8] = {
  0x00,		//.....
  0x0A,		//.#.#.
  0x00,		//.....
  0x04,		//..#..
  0x11,		//#...#
  0x0E,		//.###.
  0x00,		//.....
  0x00		//.....
};
const char custom_frowny[8] = {
  0x00,		//.....
  0x0A,		//.#.#.
  0x00,		//.....
  0x04,		//..#..
  0x00,		//.....
  0x0E,		//.###.
  0x11,		//#...#
  0x00		//.....
};
const char custom_heart[8] = {
  0x00,		//.....
  0x00,		//.....
  0x0A,		//.#.#.
  0x1F,		//#####
  0x0E,		//.###.
  0x04,		//..#..
  0x00,		//.....
  0x00		//.....
};

void main() {
  void brdInit();                            // Enable development board
  SetPortAOut();                             // Set port A as output port
  WrPortI(PBDDR, &PBDDRShadow, 0xFF);        // Set port B to output

  Lcd_Config();

  LcdDefCustomChar(0, custom_xbox);
  LcdDefCustomChar(1, custom_plug);
  LcdDefCustomChar(2, custom_battery);
  LcdDefCustomChar(3, custom_w_circle);
  LcdDefCustomChar(4, custom_b_circle);
  LcdDefCustomChar(5, custom_smiley);
  LcdDefCustomChar(6, custom_frowny);
  LcdDefCustomChar(7, custom_heart);

  LcdWriteStr(1,"Custom Character");
  pause(2);

  /* place our custom chars on the second line */
  /* with a space in between                   */
  LcdPutCustomChar(0, 2, 1);
  LcdPutCustomChar(1, 2, 3);
  LcdPutCustomChar(2, 2, 5);
  LcdPutCustomChar(3, 2, 7);
  LcdPutCustomChar(4, 2, 9);
  LcdPutCustomChar(5, 2, 11);
  LcdPutCustomChar(6, 2, 13);
  LcdPutCustomChar(7, 2, 15);
  pause(30);

  LcdLineClear(1);
  LcdWriteStr(1,"1234567890123456");
  pause(15);
  Lcd_Off();
}