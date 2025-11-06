
FILE=~/8bit/xa65/xagit/xa/file65
#FILE=file65
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

ORIG=VD
SRC=${ORIG}*.S??
TRG=vd

all: ${TRG}

${TRG}: ${SRC}
	${XA} -P "$@".lst -O PETSCII -R -bt 34814 -bb 36317 -o "$@".o65 "$<"
	${FILE} "$@".o65
	${RELOC} -v -X -o "$@" -bb 36317 "$@".o65
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 ${TRG}.hex "${ORIG}"*.hex

# lint the sources so that they can be edited in modern editors
resrc:
	mkdir -p ../../src/${TRG}
	for i in ${ORIG}*.S??; do echo $$i; xa -E -U -P - "$$i" | cut -c 40- > ../../src/${TRG}/"$$i"; done

clean:
	rm -f ${TRG}.o65 ${TRG} ${TRG}.hex *.lst
