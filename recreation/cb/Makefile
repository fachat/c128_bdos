
FILE=~/8bit/xa65/xagit/xa/file65
#FILE=file65
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

ORIG=CB
SRC=${ORIG}*.S??
TRG=cb

all: ${TRG}

${TRG}: ${SRC}
	${XA} -P "$@".lst -O PETSCII -R -bt 36862 -bb 39201 -o "$@".o65 "$<"
	${FILE} "$@".o65
	${RELOC} -v -X -o "$@" -bb 39201 "$@".o65
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 ${TRG}.hex "${ORIG}"*.hex
clean:
	rm -f ${TRG}.o65 ${TRG} ${TRG}.hex *.lst
