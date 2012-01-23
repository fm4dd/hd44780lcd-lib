/***************************************************************************/
/* Rabbit_RCM4010_TO_HD44780LCD_EXAMPLE3.C   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for HD44780-compatible LCD displays connected to Rabbit 3000    */
/* and 4000 Modules. This example demonstrates a  connect in 4-bit mode    */
/* with datalines on port A4-A7 while RS, E and RW are going to Port B     */
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

void ByteSplit(char byte, int bit[8]) {
  int i, j;
  j=0;
  for(i=128; i>0; i=i/2) {
    if ((byte & i) != 0) bit[j] = 1;
    if ((byte & i) == 0) bit[j] = 0;
    if (j == 7) break;
    else j++;
  }
}

LcdInit() {

  BitWrPortI(PBDR, &PBDRShadow, 0, RSADDR);    // Set command mode
  BitWrPortI(PBDR, &PBDRShadow, 0, RWADDR);    // Set LCD write mode

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(5);

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, 0, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);
  }

LcdWrite(int mode, char hex) {
  int bits[8];

  // First we split the byte into its bits, then we send the first an second half
  ByteSplit(hex, bits);

  BitWrPortI(PBDR, &PBDRShadow, mode, RSADDR); // Set command or data mode
  BitWrPortI(PBDR, &PBDRShadow, 0, RWADDR);    // Set LCD write mode

  BitWrPortI(PADR, &PADRShadow, bits[3], 4);   // Set port A-4
  BitWrPortI(PADR, &PADRShadow, bits[2], 5);   // Set port A-5
  BitWrPortI(PADR, &PADRShadow, bits[1], 6);   // Set port A-6
  BitWrPortI(PADR, &PADRShadow, bits[0], 7);   // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, bits[7], 4);   // Set port A-4
  BitWrPortI(PADR, &PADRShadow, bits[6], 5);   // Set port A-5
  BitWrPortI(PADR, &PADRShadow, bits[5], 6);   // Set port A-6
  BitWrPortI(PADR, &PADRShadow, bits[4], 7);   // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data lower 4 bit
  MsDelay(1);                                  // Wait 3 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission lower 4 bit
  MsDelay(1);
}

void main() {
  void brdInit();                              // Enable development board
  WrPortI(SPCR, NULL, 0x84);                   // Set Rabbit port A to output
  WrPortI(PADR, &PADRShadow, 0x0);             // Zero out all bits of port A
  WrPortI(PBDDR, &PBDDRShadow, 0xFF);          // Set port B to output

  LcdInit();
  LcdWrite(0, 0x28);                           // Send cmd 4bit, set 2 lines, 5x7 font
  LcdWrite(0, 0x06);                           // Send cmd "Entry mode, increment move"
  LcdWrite(0, 0x10);                           // Send cmd "display and cursor shift"
  LcdWrite(0, 0x0E);                           // Send cmd "display and cursor on"
  LcdWrite(0, 0x01);                           // Send cmd "LCD clear, jump to zero"

  LcdWrite(1, 0x48);                           // Send data char 'H'
  LcdWrite(1, 0x69);                           // Send data char 'i'
}