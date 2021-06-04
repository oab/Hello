all: hello1 hello2


# custom entry function can be selected with -Wl,-eNAME
# however we just use the standard _start in linux
hello1: hello1.c
	gcc -std=gnu11 -Wall -nostdlib -O3 -o $@ $<
	strip $@
	du -b $@

hello2: hello2.c
	gcc -std=gnu11 -Wall -O3 -o $@ $<
	strip $@
	du -b $@

.PHONY: clean

clean:
	rm -f hello1 hello2
