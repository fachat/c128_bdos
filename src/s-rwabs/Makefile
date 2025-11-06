
FILE=~/8bit/xa65/xagit/xa/file65
#FILE=file65
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

ORIG=s-rwabs
SRC=${ORIG}.a65
TRG=s-rwabs

all: ${TRG}

${TRG}: ${SRC}
	${XA} -P "$@".lst -O PETSCII -R -bt 32510 -o "$@".o65 "$<"
	${FILE} "$@".o65
	${RELOC} -v -X -o "$@"  "$@".o65
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 ${TRG}.hex ../../recreation/${ORIG}/"${ORIG}"*.hex

clean:
	rm -f ${TRG}.o65 ${TRG} ${TRG}.hex *.lst
