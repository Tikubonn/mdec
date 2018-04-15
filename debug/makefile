
all:
	make debug.lib
	
clean:
	rm -f compiled/print_mdec.o
	
debug.lib: compiled/print_mdec.o
	ar r debug.lib compiled/print_mdec.o
	
compiled/print_mdec.o: src/print_mdec.c
	$(CC) $(CFLAGS) -c src/print_mdec.c -o compiled/print_mdec.o
