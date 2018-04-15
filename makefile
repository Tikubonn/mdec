
export ROOTDIR = $(CURDIR)
export CC = gcc
export CFLAGS = -g3 -I$(CURDIR) -L$(CURDIR) -I$(MINT_INCLUDE) -L$(MINT_LIBRARY)

all:
	make -C manual
	make -C auto
	make -C debug
	make dist/mdec.dll
	make dist/mdec.lib
	make test
	
clean:
	make -C manual clean
	make -C auto clean
	make -C debug clean

tmp = $(shell mktemp -d)

dist/mdec.dll: debug/debug.lib auto/auto.lib manual/manual.lib
	cd $(tmp) && \
ar xv $(ROOTDIR)/manual/manual.lib && \
ar xv $(ROOTDIR)/auto/auto.lib && \
ar xv $(ROOTDIR)/debug/debug.lib && \
$(CC) $(CFLAGS) -shared *.o -lmint -o $(ROOTDIR)/dist/mdec.dll

dist/mdec.lib: debug/debug.lib auto/auto.lib manual/manual.lib
	cd $(tmp) && \
ar xv $(ROOTDIR)/manual/manual.lib && \
ar xv $(ROOTDIR)/auto/auto.lib && \
ar xv $(ROOTDIR)/debug/debug.lib && \
ar r $(ROOTDIR)/dist/mdec.lib *.o

test: test.c dist/mdec.lib
	$(CC) $(CFLAGS) test.c dist/mdec.lib -lmint -o test.exe
