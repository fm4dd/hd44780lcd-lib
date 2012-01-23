/***************************************************************************/
/* Rabbit_RCM3720_to_HD44780LCD_example5.c   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for a 16x2 HD44780 compatible LCD display on a Rabbit RCM3720   */
/* Ethernet Development Kit. We are using the HD44780LCD.LIB library for   */
/* convenience.                                                            */
/* Written and tested under Dynamic C Version 9.21       Frank4dd, @2008   */
/***************************************************************************/
#use hd44780lcd.lib
#define INTERFACE 8

void main() {
  brdInit();                                 // Enable development board
  SetPortAOut();                             // Set port A as output port
  Lcd_Config();

  pause(2);
  LcdWriteStr(1,"Rabbit-RCM3720:");
  pause(2);

  LcdWriteStr(2,"[\"Hello World!\"]");
  pause(2);

  LcdLineClear(1);
  LcdWriteStr(1,"1234567890123456");
  pause(4);

  Lcd_Clear();
  Lcd_noCursor_On();
  LcdWriteStr(1,"LCD off in 5 sec");
  LcdWrite(0, 0xA8);
  MsDelay(300); LcdPutChar('5');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('4');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('3');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('2');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('1');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('.');
  MsDelay(300); LcdPutChar('0');
  MsDelay(300); Lcd_Off();
}