
RELOC=~/8bit/xa65/xagit/xa/reloc65
#RELOC=reloc65
XA=~/8bit/xa65/xagit/xa/xa
#XA=xa

#BSS=-bb 4352
BSS=

TRG=pr_a pr_b pr_c pe_a pe_b pe_c

all: ${TRG} 

pr_a: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=0 -Dfci=0 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

pr_b: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=0 -Dfci=1 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

pr_c: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=1 -Dfci=0 -Deng=0 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

pe_a: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=0 -Dfci=0 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

pe_b: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=0 -Dfci=1 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

pe_c: pra*.a65 *.a65
	${XA} -I../bd -k -Dfmn=1 -Dfci=0 -Deng=1 -P "$@".lst -O PETSCII -bt 10238 -R -o "$@".o65 "$<"
	${RELOC} -v -X -o "$@" "$@".o65
	hexdump -C "$@" > "$@".hex

%: %.o65
	${RELOC} -v -X ${BSS} -bb 25279 -o "$@" "$<"
	hexdump -C "$@" > "$@".hex

comp: ${TRG}
	kdiff3 pr_a.hex ../../recreation/pr/"PR  2.4A28_A.hex" || true
	kdiff3 pr_b.hex ../../recreation/pr/"PR  2.4B28_A.hex" || true
	kdiff3 pr_c.hex ../../recreation/pr/"PR  2.4C28_A.hex" || true
	kdiff3 pe_a.hex ../../recreation/pr/"PE  2.4A28_A.hex" || true
	kdiff3 pe_b.hex ../../recreation/pr/"PE  2.4B28_A.hex" || true
	kdiff3 pe_c.hex ../../recreation/pr/"PE  2.4C28_A.hex" || true

# lint the sources so that they can be edited in modern editors
resrc:
	for fmn in 0 1; do for fci in 0 1; do for eng in 0 1; do for prg in 0 1; do \
		for i in *.a65; do echo $$i; xa -Dfmn=$$fmn -Dfci=$$fci -Deng=$$eng -Dprg=$$prg -E -U -P - "$$i" | cut -c 40- > "$$i"-$$fmn$$fci$$eng$$prg; done \
	done; done; done; done

recmp:
	for n in PRA PR1 PR2 PR3 PR4 PRD "PRR " PRRE WP1 WP2 WP3 WP4 WPK WPU WPW; do \
		for fmn in 0 1; do for fci in 0 1; do for eng in 0 1; do for prg in 0 1; do \
			echo diff -ub "$$n"*.S??-$$fmn$$fci$$eng$$prg `echo $$n | tr A-Z a-z | tr -d " "`.a65-$$fmn$$fci$$eng$$prg; \
			diff -ub "$$n"*.S??-$$fmn$$fci$$eng$$prg `echo $$n | tr A-Z a-z | tr -d " "`.a65-$$fmn$$fci$$eng$$prg; \
	done; done; done; done; done

clean:
	rm -f *.o65 ${TRG} P?_?.hex *.lst

