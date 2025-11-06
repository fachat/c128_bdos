
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

all: bd+

bd+: bda*.a65 *.S??
	${XA} -P "$@".lst -O PETSCII -bt 40958 -bb 4352 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 4352 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

comp: bd+
	kdiff3 bd+.hex "BD+ 1.45HA.hex"

# lint the sources so that they can be edited in modern editors
resrc:
	for i in *.S??; do echo $$i; xa -E -U -P - "$$i" | cut -c 40- > ../../src/bd/"$$i"; done

clean:
	rm -f bd+.o65 bd+ bd+.hex *.lst
