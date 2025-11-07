
# BDOS - the bridge to your PC

This is a recovery and re-creation of the BDOS project I did in 1988/1989,
where I created a program to read and write files to PC floppy disks
on a C128 with a VC1571 disk drive.

## Quickstart

To first run and install BDOS, you need the VICE emulator, and the _bdos.d64_ file included
in this repository. Then run the x128 emulator like so:

```
x128 -8 bdos.d64
```

The follow the instructions in these files:

* [FIRST RUN](FIRST_RUN.md) - how to start and configure it.
* [MENU](MENU.md) - what to expect from the Menu shell

Note that with the x128 emulator at this time,
the VC1571 emulation does not handle MFM (PC) disk images. So all testing with 
PC disks is restricted to the RAM disk on the emulator.

## Folders

The folders in this repository have the following content:

- orig: the original tgz and disk archives
- origsrc: the unpacked CPK files, the un-archiver, and the unpacked source files. Note that filenames that contain slashes (/) have the slash replaced with an underscore (\_)
- recreation: source files adapted and with Makefiles that build the original binaries; "bd" is the kernel, "pr" is the prompt = menu/cli.
- src: a newly formatted version of the source files, ready for xa and continued development
 
