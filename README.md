# DCSD_LIGHTS
A simple project to light up the LEDs on the Apple DCSD cable arbitrarily.
The project is based on Mathieu Hautebas' DCSD_STATUS available on https://github.com/matteyeux/dcsd_status

The DCSD cable is a factory cable used most likely for testing at Foxconn for the Apple devices. The cable features a gray box with 3 LEDs labeled "Busy", "Pass" and "Fail". Orange, Red and Yellow when lit. Some extensive research has been carried out by `lululombard`. His research can be found on <a href = "https://github.com/lululombard/DCSD-reverse-engineering"> DCSD reverse engineering </a>

The cable can be controlled using LibFTDI as demonstrated in the program and in Mathieu and lululombard's examples.

### Prerequisites
Before compiling, install LIBFTDI on your Mac.

```bash
$ wget https://www.intra2net.com/en/developer/libftdi/download/libftdi1-1.4.tar.bz2
$ tar jxvf libftdi1-1.4.tar.bz2
$ cd libftdi1-1.4
$ cmake . && sudo make install
```
Or use Homebrew:
```bash
$ brew install libftdi
$ brew link libftdi
```
### Compiling
```bash
$ cd <path of the source>
$ make
```
### Usage
Once compiled and started, the program detects the connected DCSD Alex cable and initializes a "Christmas Light Pattern" which lights a random LED each second for a few seconds. 

After the Christmas Light Pattern procedure, you can specify the number of the LED you want to light up.
```
1 = Green LED
2 = Orange LED
3 = Red Led
4 = All on
```
### Credits
Special thanks to https://twitter.com/matteyeux and https://twitter.com/lululombard

### Contact me
Twitter: https://twitter.com/FCE365
