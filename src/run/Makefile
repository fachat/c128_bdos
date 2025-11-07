
TRG=run_me run_mich

all: ${TRG}

run_me: RUN?ME.lst
	petcat -w70 -l 0801 -o "$@" -- "$<"
	hexdump -C $@ > $@.hex

run_mich: RUN?MICH.lst
	petcat -w70 -l 0801 -o "$@" -- "$<"
	hexdump -C $@ > $@.hex

comp: ${TRG}
	kdiff3 run_me.hex "RUN ME".hex || true
	kdiff3 run_mich.hex "RUN MICH".hex || true

clean:
	rm -f ${TRG} run_me.hex run_mich.hex

