## Rabbit 3000/4000 HD44780LCD.LIB V1.1

https://fpga.fm4dd.com/?rabbit

![ScreenShot](https://fpga.fm4dd.com/assets/images/rabbit/rcm3720-testprogram8.png)

 Frank4dd, @2009-01-09 public[at]frank4dd[dot]com

 This library has been written for HD44780-compatible LCD displays connected
 to Rabbit 3000 and 4000 Modules. It provides high-level functions to show
 data on them by having routines for initialization, character and string
 printing. LCD displays can connect in either 8-bit or 4-bit mode with their 
 datalines on port A while RS, E and RW are connected to Port B on B2, B3
 and B4. The library supports the the display sizes 16x2 and 20x4.

 HD44780-compatible identifies a group of character-based LCD displays with
 a Hitachi HD44780-like controller chip, providing  a parallel port. They are
 typically used to interface with embedded systems such as 8-bit single board
 computers with a Rabbit CPU from digi.com. They come in a variety of sizes
 and styles: Line sizes range from 8-chars to 40-chars wide, with one, two
 and four line versions available, and most of them have backlighting.

 This library was written and tested under Dynamic C Version 9.21 and 10.05
 with an RCM 3720 Ethernet development kit and a RCM 4010 development kit.
 These systems were formerly known as products made by Rabbit Semiconductor.

 For more information about those, see Digi's website for embedded solutions
 at http://www.digi.com/products/wireless-wired-embedded-solutions/

### License: 

I make the library and examples available under the terms of the
 LGPL version 3, which is particularly suited for libraries.

### Installation

* Dynamic C Version 9.xx: Place the library file into
 C:\DCRABBIT_9.21\Lib\Displays. Now add the library to Dynamic C's library
 inclusion list. This list is a text file C:\DCRABBIT_9.21\Lib.dir.

* Dynamic C Version 10.xx: This compiler version now
 automatically searches through the standard library path. Place the 
 library file into it, and next compile time it should be found.

### Additional documentation

http://fm4dd.com/electronics/rabbit/hd44780lcd-to-rabbit.shtm

http://fm4dd.com/electronics/rabbit/hd44780lcd-to-rabbit-rcm4010.shtm
