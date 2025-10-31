
#
#
# cat anl1_asc | sed -e 's/{/\xe4/g' -e 's/|/\xf6/g' -e 's/}/\xfc/g' -e 's/~/\xdf/g' | iconv -f latin1 -t utf8 > anleitung_pt1.txt 
#

all:
	for i in 1 2 3 4 5 6; do cat anl$${i}_asc \
		| sed -e 's/{/\xe4/g' -e 's/|/\xf6/g' -e 's/}/\xfc/g' -e 's/~/\xdf/g' \
		| iconv -f latin1 -t utf8 \
		> anleitung_pt$${i}.txt \
	; done

