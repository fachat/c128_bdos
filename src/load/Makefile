
FILE=~/8bit/xa65/xagit/xa/file65
#FILE=file65
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

ORIG=loader
SRC=${ORIG}*.a65
TRG=loader

all: ${TRG}

${TRG}: ${SRC}
	${XA} -I../bd -P "$@".lst -O PETSCII -R -bt 32766 -o "$@".o65 "$<"
	${FILE} "$@".o65
	${RELOC} -v -X -o "$@"  "$@".o65
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 ${TRG}.hex "${ORIG}"*.hex

clean:
	rm -f ${TRG}.o65 ${TRG} ${TRG}.hex *.lst
