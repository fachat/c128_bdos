
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

#BSS=-bb 4352
BSS=

BIN=PR

all: ${BIN}.hex 

${BIN}.o65: PRA*.S?? *.S??
	${XA} -k -P "$@".lst -O PETSCII -bt 10238 ${BSS} -R -o "$@" "$<"

${BIN}: ${BIN}.o65
	${RELOC} -v -X ${BSS} -bb 25279 -o "$@" "$<"

${BIN}.hex:${BIN}
	hexdump -C "$<" > "$@"

${BIN}.a65: ${BIN}.o65.lst
	cat "$<" | cut -c 40- > "$@"

${BIN}.rec: ${BIN}.a65
	${XA} -k -P "$@".lst -bt 10238 ${BSS} -R -o "$@".o65 "$<"
	${RELOC} -v -X ${BSS} -bb 25279 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

clean:
	rm -f ${BIN}.o65 ${BIN} ${BIN}.hex
