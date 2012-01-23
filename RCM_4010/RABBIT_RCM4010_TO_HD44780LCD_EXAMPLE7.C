/***************************************************************************/
/* RABBIT_RCM4010_TO_HD44780LCD_EXAMPLE7.C   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for HD44780-compatible LCD displays connected to Rabbit 3000    */
/* and 4000 Modules. This example demonstrates using the HD44780LCD.LIB    */
/* library for convenience. Written and tested under Dynamic C Version     */
/* 10.05. With DISPLAYSIZE and DISPLAYLINES set, we use a 20x4 display.    */                                               
/*                                                                         */
/*                                                       Frank4dd, @2009   */
/***************************************************************************/
#use hd44780lcd.lib
#define INTERFACE    8
#define DISPLAYSIZE 20
#define DISPLAYLINES 4

void main() {
  void brdInit();                            // Enable development board
  SetPortAOut();                             // Set port A as output port
  WrPortI(PBDDR, &PBDDRShadow, 0xFF);        // Set port B to output

  Lcd_Config();

  pause(2);
  LcdWriteStr(1,"Rabbit-RCM4010:");
  pause(2);

  LcdWriteStr(2,"[\"Hello World!\"]");
  pause(2);

  LcdWriteStr(3,"12345678901234567890");
  pause(4);

  LcdLineClear(3);

  Lcd_noCursor_On();
  LcdWriteStr(3,"LCD off in 5 seconds");
  LcdWrite(0, 0xD4);
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
  LcdPutChar('.');
  LcdPutChar('O');
  LcdPutChar('f');
  LcdPutChar('f');
  MsDelay(900); 
  Lcd_Off();
}