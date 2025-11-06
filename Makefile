
DIRS=recreation src

all:
	for i in ${DIRS}; do make -C $$i ; done

clean:
	for i in ${DIRS}; do make -C $$i clean; done

