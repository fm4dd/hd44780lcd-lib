/***************************************************************************/
/* RABBIT_RCM4010_TO_HD44780LCD_EXAMPLE1.C   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for HD44780-compatible LCD displays connected to Rabbit 3000    */
/* and 4000 Modules. This example demonstrates a  connect in 8-bit mode    */
/* with datalines on port A while RS, E and RW are connected to Port B     */
/* on B2, B3 and B4. Written and tested under Dynamic C Version 10.05.     */
/*                                                                         */
/*                                                       Frank4dd, @2009   */
/***************************************************************************/
#class auto

#define RSADDR       2                         // Register Select   port B-2
#define ENADDR       3                         // Enable signal     port B-3
#define RWADDR       4                         // Read/Write signal port B-4

void MsDelay(unsigned long milliSeconds) {
  unsigned long ul0;
  ul0 = MS_TIMER;                              // get the current timer value
  while(MS_TIMER < ul0 + milliSeconds);
}

void LcdWrite(int mode, char hex) {
  BitWrPortI(PBDR, &PBDRShadow, mode, RSADDR); // Choose command or data mode
  BitWrPortI(PBDR, &PBDRShadow, 0,    RWADDR); // Set LCD write mode
  WrPortI(PADR, &PADRShadow, hex);             // Set LCD command on port A

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data
  MsDelay(1);                                  // Wait 1 ms for LCD to receive
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission
  MsDelay(1);                                  // Wait 1 ms until next write
}

void main() {
  void brdInit();                              // Enable development board
  WrPortI(SPCR, NULL, 0x84);                   // Set Rabbit port A to output
  WrPortI(PADR, &PADRShadow, 0x0);             // Zero out all bits of port A
  WrPortI(PBDDR, &PBDDRShadow, 0xFF);          // Set port B to output

  LcdWrite(0, 0x30);
  MsDelay(4);
  LcdWrite(0, 0x30);
  LcdWrite(0, 0x30);
  LcdWrite(0, 0x38);                           // Send cmd "8bit, 2 lines, 5x7 font"
  LcdWrite(0, 0x06);                           // Send cmd "Entry mode, increment move"
  LcdWrite(0, 0x10);                           // Send cmd "display and cursor shift"
  LcdWrite(0, 0x0E);                           // Send cmd "display and cursor on"
  LcdWrite(0, 0x01);                           // Send cmd "LCD clear, jump to zero

  LcdWrite(1, 0x48);                           // Send data 'H'
  LcdWrite(1, 0x69);                           // Send data 'i'
}