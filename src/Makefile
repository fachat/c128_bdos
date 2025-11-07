
D64=bdos.d64

DISTFILES=\
	install/install_me \
	install/install_mich \
	load/loader \
	bd/bd+ \
	pr/pr_a \
	pr/pr_b \
	pr/pr_c \
	pr/pe_a \
	pr/pe_b \
	pr/pe_c \
	cb/cb \
	cd/cd \
	vb/vb \
	vd/vd \
	prg1/prg1 \
	prg2/prg2 \
	s-floprw/s-floprw \
	s-rwabs/s-rwabs

DIRS=bd  cb  cd  install  load  pr  prg1  prg2  s-floprw  s-rwabs  vb  vd

all:
	for i in ${DIRS}; do make -C $$i || return 1; done

clean:
	for i in ${DIRS}; do make -C $$i clean; done

dist: all ${D64}
	c1541 -format bdos,15 d64 ${D64}
	for i in ${DISTFILES}; do c1541 -attach ${D64} -write $$i; done

${D64}:
	rm -f $@
	c1541 -format bdos,15 d64 $@
	
