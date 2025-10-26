
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

#BSS=-bb 4352
BSS=

TRG=PR_A PR_B PR_C PE_A PE_B PE_C

all: ${TRG} 

PR_A: PRA*.S?? *.S??
	${XA} -k -Dfmn=0 -Dfci=0 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 25279 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

PR_B: PRA*.S?? *.S??
	${XA} -k -Dfmn=0 -Dfci=1 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 20762 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

PR_C: PRA*.S?? *.S??
	${XA} -k -Dfmn=1 -Dfci=0 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 16553 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

PE_A: PRA*.S?? *.S??
	${XA} -k -Dfmn=0 -Dfci=0 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 24951 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

PE_B: PRA*.S?? *.S??
	${XA} -k -Dfmn=0 -Dfci=1 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 20514 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

PE_C: PRA*.S?? *.S??
	${XA} -k -Dfmn=1 -Dfci=0 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -bb 16351 -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

%: %.o65
	${RELOC} -v -X ${BSS} -bb 25279 -o "$@" "$<"
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 PR_A.hex "PR  2.4A28_A.hex" || true
	kdiff3 PR_B.hex "PR  2.4B28_A.hex" || true
	kdiff3 PR_C.hex "PR  2.4C28_A.hex" || true
	kdiff3 PE_A.hex "PE  2.4A28_A.hex" || true
	kdiff3 PE_B.hex "PE  2.4B28_A.hex" || true
	kdiff3 PE_C.hex "PE  2.4C28_A.hex" || true

clean:
	rm -f *.o65 ${TRG} P?_?.hex *.lst

