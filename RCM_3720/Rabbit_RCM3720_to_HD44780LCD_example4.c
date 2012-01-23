/***************************************************************************/
/* Rabbit_RCM3720_to_HD44780LCD_example4.c   http://www.frank4dd.com/howto */
/*                                                                         */
/* Written for a 16x2 HD44780 compatible LCD display on a Rabbit RCM3720   */
/* Ethernet Development Kit. All 8bits are connected but we are going to   */
/* send in 4bit mode. We are using port A, keeping the datalines on port   */
/* A0 - A3 to Low. RS, E and R/W are connected to Port B on B2, B3 and B4. */
/* Written and tested under Dynamic C Version 9.21       Frank4dd, @2008   */
/***************************************************************************/
#class auto

#define RSADDR       2                       // Register Select    port B bit 2
#define ENADDR       3                       // Enable signal      port B bit 3
#define RWADDR       4                       // Read/Write signal  port B bit 4
#define DISPLAYSIZE 16                       // The length of the LCD display

void ByteSplit(char byte, int bits[8]) {
  int i;
  int j;
  j=0;
  for(i=128; i>0; i=i/2) {
    if ((byte & i) != 0) bits[j] = 1;
    if ((byte & i) == 0) bits[j] = 0;
    if (j == 7) break;
    else j++;
  }
}

void SetPortAOut() {
  WrPortI(SPCR, NULL, 0x84);                 // Set Rabbit port A to output
  WrPortI(PADR, &PADRShadow, 0x0);           // Set all bits of port A to '1'
}

void MsDelay(unsigned long milliSeconds) {
  unsigned long ul0;
  ul0 = MS_TIMER;                            // get the current timer value
  while(MS_TIMER < ul0 + milliSeconds);
}

void pause(unsigned long seconds) {
  MsDelay(seconds*1000);                     // multiply sec with 1000 for ms
}

Lcd4bitInit() {

  BitWrPortI(PBDR, &PBDRShadow, 0, RSADDR);    // Set command mode
  BitWrPortI(PBDR, &PBDRShadow, 0, RWADDR);    // Set LCD write mode

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(5);

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, 1, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, 0, 4);         // Set port A-4
  BitWrPortI(PADR, &PADRShadow, 1, 5);         // Set port A-5
  BitWrPortI(PADR, &PADRShadow, 0, 6);         // Set port A-6
  BitWrPortI(PADR, &PADRShadow, 0, 7);         // Set port A-7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);    // Start sending data upper 4 bit
  MsDelay(1);                                  // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);    // Finish transmission upper 4 bit
  MsDelay(1);
}


LcdCommandWr(char hex) {
int cmdbits[8];

  BitWrPortI(PBDR, &PBDRShadow, 0, RSADDR);  // Set LCD command mode
  BitWrPortI(PBDR, &PBDRShadow, 0, RWADDR);  // Set LCD write mode

  // we need to split the 8 bits in half and transmit upper 4 bits,
  // then the lower 4 bits.
  ByteSplit(hex, cmdbits);

  BitWrPortI(PADR, &PADRShadow, cmdbits[3], 4);  // Set port A bit 4
  BitWrPortI(PADR, &PADRShadow, cmdbits[2], 5);  // Set port A bit 5
  BitWrPortI(PADR, &PADRShadow, cmdbits[1], 6);  // Set port A bit 6
  BitWrPortI(PADR, &PADRShadow, cmdbits[0], 7);  // Set port A bit 7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);  // Start sending data upper 4 bit
  MsDelay(1);                                // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);  // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, cmdbits[7], 4);  // Set port A bit 4
  BitWrPortI(PADR, &PADRShadow, cmdbits[6], 5);  // Set port A bit 5
  BitWrPortI(PADR, &PADRShadow, cmdbits[5], 6);  // Set port A bit 6
  BitWrPortI(PADR, &PADRShadow, cmdbits[4], 7);  // Set port A bit 7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);  // Start sending data lower 4 bit
  MsDelay(1);                                // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);  // Finish transmission lower 4 bit
  MsDelay(1);
}

void Lcd_Config() {
  LcdCommandWr(0x28);                       // keep 4bit, set 2 lines, 5x7 font
  LcdCommandWr(0x06);	                    // Set Entry mode, increment move
  LcdCommandWr(0x10);	                    // Display and cursor shift
  LcdCommandWr(0x0E);	                    // Switch display and cursor on
  LcdCommandWr(0x01);	                    // Clear the LCD and jump to zero
}

void Lcd_Clear() {
  LcdCommandWr(0x01);                        // Clear the LCD and jump to zero
}

void Lcd_solidCursor_On() {                  // Switch the LCD on
  LcdCommandWr(0x0E);                        // Cursor is a solid underline
}

void Lcd_noCursor_On() {
  LcdCommandWr(0x0C);                        // Switch the LCD on (no cursor)
}

void Lcd_blinkCursor_On() {                  // Switch the LCD on
  LcdCommandWr(0x0F);                        // Cursor is a blinking square
}

void Cursor_Home() {
  LcdCommandWr(0x03);                        // Cursor back to first position
}

void Lcd_Off() {
  LcdCommandWr(0x08);                        // Switch the LCD display off
}

#define ASCIITABLESIZE 96
char * AsciiCharLookup(char syschar) {
  char * lcdCode;
  char charTable[ASCIITABLESIZE][2];
  int i;

   charTable[0][0] = ' ';   charTable[0][1] = 0x20;
   charTable[1][0] = '!';   charTable[1][1] = 0x21;
   charTable[2][0] = '"';   charTable[2][1] = 0x22;
   charTable[3][0] = '#';   charTable[3][1] = 0x23;
   charTable[4][0] = '$';   charTable[4][1] = 0x24;
   charTable[5][0] = '%';   charTable[5][1] = 0x25;
   charTable[6][0] = '&';   charTable[6][1] = 0x26;
   charTable[7][0] = '\'';  charTable[7][1] = 0x27;
   charTable[8][0] = '(';   charTable[8][1] = 0x28;
   charTable[9][0] = ')';   charTable[9][1] = 0x29;
  charTable[10][0] = '*';  charTable[10][1] = 0x2A;
  charTable[11][0] = '+';  charTable[11][1] = 0x2B;
  charTable[12][0] = ',';  charTable[12][1] = 0x2C;
  charTable[13][0] = '-';  charTable[13][1] = 0x2D;
  charTable[14][0] = '.';  charTable[14][1] = 0x2E;
  charTable[15][0] = '/';  charTable[15][1] = 0x2F;
  charTable[16][0] = '0';  charTable[16][1] = 0x30;
  charTable[17][0] = '1';  charTable[17][1] = 0x31;
  charTable[18][0] = '2';  charTable[18][1] = 0x32;
  charTable[19][0] = '3';  charTable[19][1] = 0x33;
  charTable[20][0] = '4';  charTable[20][1] = 0x34;
  charTable[21][0] = '5';  charTable[21][1] = 0x35;
  charTable[22][0] = '6';  charTable[22][1] = 0x36;
  charTable[23][0] = '7';  charTable[23][1] = 0x37;
  charTable[24][0] = '8';  charTable[24][1] = 0x38;
  charTable[25][0] = '9';  charTable[25][1] = 0x39;
  charTable[26][0] = ':';  charTable[26][1] = 0x3A;
  charTable[27][0] = ';';  charTable[27][1] = 0x3B;
  charTable[28][0] = '<';  charTable[28][1] = 0x3C;
  charTable[29][0] = '=';  charTable[29][1] = 0x3D;
  charTable[30][0] = '>';  charTable[30][1] = 0x3E;
  charTable[31][0] = '?';  charTable[31][1] = 0x3F;
  charTable[32][0] = '@';  charTable[32][1] = 0x40;
  charTable[33][0] = 'A';  charTable[33][1] = 0x41;
  charTable[34][0] = 'B';  charTable[34][1] = 0x42;
  charTable[35][0] = 'C';  charTable[35][1] = 0x43;
  charTable[36][0] = 'D';  charTable[36][1] = 0x44;
  charTable[37][0] = 'E';  charTable[37][1] = 0x45;
  charTable[38][0] = 'F';  charTable[38][1] = 0x46;
  charTable[39][0] = 'G';  charTable[39][1] = 0x47;
  charTable[40][0] = 'H';  charTable[40][1] = 0x48;
  charTable[41][0] = 'I';  charTable[41][1] = 0x49;
  charTable[42][0] = 'J';  charTable[42][1] = 0x4A;
  charTable[43][0] = 'K';  charTable[43][1] = 0x4B;
  charTable[44][0] = 'L';  charTable[44][1] = 0x4C;
  charTable[45][0] = 'M';  charTable[45][1] = 0x4D;
  charTable[46][0] = 'N';  charTable[46][1] = 0x4E;
  charTable[47][0] = 'O';  charTable[47][1] = 0x4F;
  charTable[48][0] = 'P';  charTable[48][1] = 0x50;
  charTable[49][0] = 'Q';  charTable[49][1] = 0x51;
  charTable[50][0] = 'R';  charTable[50][1] = 0x52;
  charTable[51][0] = 'S';  charTable[51][1] = 0x53;
  charTable[52][0] = 'T';  charTable[52][1] = 0x54;
  charTable[53][0] = 'U';  charTable[53][1] = 0x55;
  charTable[54][0] = 'V';  charTable[54][1] = 0x56;
  charTable[55][0] = 'W';  charTable[55][1] = 0x57;
  charTable[56][0] = 'X';  charTable[56][1] = 0x58;
  charTable[57][0] = 'Y';  charTable[57][1] = 0x59;
  charTable[58][0] = 'Z';  charTable[58][1] = 0x5A;
  charTable[59][0] = '[';  charTable[59][1] = 0x5B;
  charTable[60][0] = ' ';  charTable[60][1] = 0x5C; // The Yen currency symbol
  charTable[61][0] = ']';  charTable[61][1] = 0x5D;
  charTable[62][0] = '^';  charTable[62][1] = 0x5E;
  charTable[63][0] = '_';  charTable[63][1] = 0x5F;
  charTable[64][0] = '\\'; charTable[64][1] = 0x60;
  charTable[65][0] = 'a';  charTable[65][1] = 0x61;
  charTable[66][0] = 'b';  charTable[66][1] = 0x62;
  charTable[67][0] = 'c';  charTable[67][1] = 0x63;
  charTable[68][0] = 'd';  charTable[68][1] = 0x64;
  charTable[69][0] = 'e';  charTable[69][1] = 0x65;
  charTable[70][0] = 'f';  charTable[70][1] = 0x66;
  charTable[71][0] = 'g';  charTable[71][1] = 0x67;
  charTable[72][0] = 'h';  charTable[72][1] = 0x68;
  charTable[73][0] = 'i';  charTable[73][1] = 0x69;
  charTable[74][0] = 'j';  charTable[74][1] = 0x6A;
  charTable[75][0] = 'k';  charTable[75][1] = 0x6B;
  charTable[76][0] = 'l';  charTable[76][1] = 0x6C;
  charTable[77][0] = 'm';  charTable[77][1] = 0x6D;
  charTable[78][0] = 'n';  charTable[78][1] = 0x6E;
  charTable[79][0] = 'o';  charTable[79][1] = 0x6F;
  charTable[80][0] = 'p';  charTable[80][1] = 0x70;
  charTable[81][0] = 'q';  charTable[81][1] = 0x71;
  charTable[82][0] = 'r';  charTable[82][1] = 0x72;
  charTable[83][0] = 's';  charTable[83][1] = 0x73;
  charTable[84][0] = 't';  charTable[84][1] = 0x74;
  charTable[85][0] = 'u';  charTable[85][1] = 0x75;
  charTable[86][0] = 'v';  charTable[86][1] = 0x76;
  charTable[87][0] = 'w';  charTable[87][1] = 0x77;
  charTable[88][0] = 'x';  charTable[88][1] = 0x78;
  charTable[89][0] = 'y';  charTable[89][1] = 0x79;
  charTable[90][0] = 'z';  charTable[90][1] = 0x7A;
  charTable[91][0] = '{';  charTable[91][1] = 0x7B;
  charTable[92][0] = '|';  charTable[92][1] = 0x7C;
  charTable[93][0] = '}';  charTable[93][1] = 0x7D;
  charTable[94][0] = ' ';  charTable[94][1] = 0x7E; // arrow pointing right
  charTable[95][0] = ' ';  charTable[95][1] = 0x7F; // arrow pointing left

  lcdCode = NULL;
  for(i=0;i<ASCIITABLESIZE;i++) {
    if(syschar==charTable[i][0]) break;
  }
  lcdCode = &charTable[i][1];
  return lcdCode;
}

void LcdPutChar(char displayChar) {
  char * lcdChar;
  int databits[8];
  lcdChar = AsciiCharLookup(displayChar);
  if(lcdChar==NULL) return;

  BitWrPortI(PBDR, &PBDRShadow, 1, RSADDR);  // Set LCD data mode
  BitWrPortI(PBDR, &PBDRShadow, 0, RWADDR);  // Set LCD write mode

  // we need to split the 8 bits in half and transmit upper 4 bits,
  // then the lower 4 bits.
  ByteSplit(*lcdChar, databits);

  BitWrPortI(PADR, &PADRShadow, databits[3], 4);  // Set port A bit 4
  BitWrPortI(PADR, &PADRShadow, databits[2], 5);  // Set port A bit 5
  BitWrPortI(PADR, &PADRShadow, databits[1], 6);  // Set port A bit 6
  BitWrPortI(PADR, &PADRShadow, databits[0], 7);  // Set port A bit 7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);  // Start sending data upper 4 bit
  MsDelay(1);                                // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);  // Finish transmission upper 4 bit
  MsDelay(1);

  BitWrPortI(PADR, &PADRShadow, databits[7], 4);  // Set port A bit 4
  BitWrPortI(PADR, &PADRShadow, databits[6], 5);  // Set port A bit 5
  BitWrPortI(PADR, &PADRShadow, databits[5], 6);  // Set port A bit 6
  BitWrPortI(PADR, &PADRShadow, databits[4], 7);  // Set port A bit 7

  MsDelay(1);
  BitWrPortI(PBDR, &PBDRShadow, 1, ENADDR);  // Start sending data lower 4 bit
  MsDelay(1);                                // Wait 1 ms for LCD to read
  BitWrPortI(PBDR, &PBDRShadow, 0, ENADDR);  // Finish transmission lower 4 bit
  MsDelay(1);
}

void LcdWriteStr(int line, char s[]) {
  int i;
  if (line == 1) LcdCommandWr(0x80);         // Set display address for line 1
  if (line == 2) LcdCommandWr(0xA8);         // Set display address for line 2
  for(i=0;i<=DISPLAYSIZE && s[i];i++)        // Send only max chars to display
    LcdPutChar(s[i]);                        // when the given string is longer
}

void main() {
  brdInit();                                 // Enable development board
  SetPortAOut();                             // Set port A as output port

  Lcd4bitInit();
  Lcd_Config();
  pause(5);

  LcdWriteStr(1,"Rabbit-RCM3720:");
  pause(5);

  LcdWriteStr(2,"[\"Hello World!\"]");
  pause(10);

  Lcd_Clear();
  Lcd_noCursor_On();
  LcdWriteStr(1,"LCD off in 5 sec");
  LcdCommandWr(0xA8);
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
