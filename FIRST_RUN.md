# Running BDOS the first time

This instructions describe how to start BDOS for the first time, resp. re-configure it later.

BDOS uses an _autoload_ file that contains the information about the kernel, drivers, and shell to load, plus the parameters for them.
This must be created on the first run. 


## RUN ME

The _RUN ME_ program is the standard loader. It checks for the existence of the autoload file and uses it to load BDOS if it exists.
If the autoload file does not exist, it instead loads and runs the _INSTALL ME_ program that guides you through a few questions
to create the autoload file.

## INSTALL ME

runThe _INSTALL ME_ program ask a few questions about the setup.

### Hardware

This screen defines which drives should be used as default. It asks the questions for the PC drives A: and B: as well as for the Commodore disk drive.
This way you can define your default setup e.g. if you have a VC1571 for PC disks and a VC1541 for Commodore disks.

Using the keys "1" to "4" you can switch through the options. A "Y" confirms and gets you to the next page.

### Printer

Here you can define your printer. An IEC printer as well as a userport Centronics printer can be used.
Also there are options for conversions, e.g. if CBM PETSCII should be converted to ASCII or vice versa.

If IEC unit, the program also asks for the IEC address and secondary address (in case needed for printer-specific options).
You can just press enter to use the defaults resp. if you don't have a printer.

### Memory Map

This is a very important page. It defines which version of the program should be used, and what memory areas should be used for RAMDISK or BUFFER

#### Program options

There are three versions of the program: 
1. MENU+CLI: this contains both user interfaces, the command line and the Text Menu interface. It starts from the menu. You can switch to CLI with a menu option, and return with the "MENU" CLI command.
2. MENU: this contains only the menu interface
3. CLI: this only has the command line interface

You will notice that each program version uses different amounts of memory. The memory can be used for RAMDISK or BUFFER

#### RAM Disk

The RAM disk is defined as drive C: and is a PC type drive. You can use it to copy over files on a single drive setup (e.g. with a VC1571 only).
Depending on the program version, you can assign the different blocks of memory to RAM disk.

#### Buffer

The buffer is used to hold blocks of data while transferring them from one drive to another.
Depending on the program version you can assign memory blocks to the buffer.

Note that the buffer must be contiguous at the end of the program to count for the actual size. 
The actual size is printed at the bottom and updated as you change the configuration.

### Colors

This defines the fore- and background colours for the menu. The colours are the C64/C128 color memory values (e.g 0 for black and 5 for bright green).
You can just press enter to use the defaults.

### Creating autoload file

After those questions have been answered, the _autoload_ file is created, and if confirmed, BDOS is started.

