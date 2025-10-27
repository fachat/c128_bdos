
TRG=install_me install_mich

all: ${TRG}

install_me: INSTALL?ME.lst
	petcat -w70 -l 0801 -o "$@" -- "$<"
	hexdump -C $@ > $@.hex

install_mich: INSTALL?MICH.lst
	petcat -w70 -l 0801 -o "$@" -- "$<"
	hexdump -C $@ > $@.hex

comp: ${TRG}
	kdiff3 install_me.hex "INSTALL ME".hex || true
	kdiff3 install_mich.hex "INSTALL MICH".hex || true

clean:
	rm -f ${TRG} install_me.hex install_mich.hex

