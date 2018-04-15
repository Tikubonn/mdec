
all:
	make auto.lib
	
clean:
	rm -f compiled/make_mdec.o
	rm -f compiled/free_mdec.o
	rm -f compiled/is_equal_mdec.o
	rm -f compiled/is_unequal_mdec.o
	rm -f compiled/is_lesser_mdec.o
	rm -f compiled/is_lesser_or_equal_mdec.o
	rm -f compiled/is_greater_mdec.o
	rm -f compiled/is_greater_or_equal_mdec.o
	rm -f compiled/add_mdec.o
	rm -f compiled/sub_mdec.o
	rm -f compiled/mul_mdec.o
	rm -f compiled/div_mdec.o
	rm -f compiled/abs_mdec.o
	rm -f compiled/cast_mdec.o
	rm -f compiled/compaction_mdec.o
	rm -f compiled/copy_mdec.o

auto.lib: compiled/make_mdec.o compiled/free_mdec.o compiled/is_equal_mdec.o compiled/is_unequal_mdec.o compiled/is_lesser_mdec.o compiled/is_lesser_or_equal_mdec.o compiled/is_greater_mdec.o compiled/is_greater_or_equal_mdec.o compiled/add_mdec.o compiled/sub_mdec.o compiled/mul_mdec.o compiled/div_mdec.o compiled/abs_mdec.o compiled/cast_mdec.o compiled/compaction_mdec.o compiled/copy_mdec.o
	ar r auto.lib compiled/make_mdec.o compiled/free_mdec.o compiled/is_equal_mdec.o compiled/is_unequal_mdec.o compiled/is_lesser_mdec.o compiled/is_lesser_or_equal_mdec.o compiled/is_greater_mdec.o compiled/is_greater_or_equal_mdec.o compiled/add_mdec.o compiled/sub_mdec.o compiled/mul_mdec.o compiled/div_mdec.o compiled/abs_mdec.o compiled/cast_mdec.o compiled/compaction_mdec.o compiled/copy_mdec.o

compiled/make_mdec.o: src/make_mdec.c
	$(CC) $(CFLAGS) -c src/make_mdec.c -o compiled/make_mdec.o

compiled/free_mdec.o: src/free_mdec.c
	$(CC) $(CFLAGS) -c src/free_mdec.c -o compiled/free_mdec.o

compiled/is_equal_mdec.o: src/is_equal_mdec.c
	$(CC) $(CFLAGS) -c src/is_equal_mdec.c -o compiled/is_equal_mdec.o

compiled/is_unequal_mdec.o: src/is_unequal_mdec.c
	$(CC) $(CFLAGS) -c src/is_unequal_mdec.c -o compiled/is_unequal_mdec.o

compiled/is_lesser_mdec.o: src/is_lesser_mdec.c
	$(CC) $(CFLAGS) -c src/is_lesser_mdec.c -o compiled/is_lesser_mdec.o

compiled/is_lesser_or_equal_mdec.o: src/is_lesser_or_equal_mdec.c
	$(CC) $(CFLAGS) -c src/is_lesser_or_equal_mdec.c -o compiled/is_lesser_or_equal_mdec.o

compiled/is_greater_mdec.o: src/is_greater_mdec.c
	$(CC) $(CFLAGS) -c src/is_greater_mdec.c -o compiled/is_greater_mdec.o

compiled/is_greater_or_equal_mdec.o: src/is_greater_or_equal_mdec.c
	$(CC) $(CFLAGS) -c src/is_greater_or_equal_mdec.c -o compiled/is_greater_or_equal_mdec.o

compiled/add_mdec.o: src/add_mdec.c
	$(CC) $(CFLAGS) -c src/add_mdec.c -o compiled/add_mdec.o

compiled/sub_mdec.o: src/sub_mdec.c
	$(CC) $(CFLAGS) -c src/sub_mdec.c -o compiled/sub_mdec.o

compiled/mul_mdec.o: src/mul_mdec.c
	$(CC) $(CFLAGS) -c src/mul_mdec.c -o compiled/mul_mdec.o

compiled/div_mdec.o: src/div_mdec.c
	$(CC) $(CFLAGS) -c src/div_mdec.c -o compiled/div_mdec.o

compiled/abs_mdec.o: src/abs_mdec.c
	$(CC) $(CFLAGS) -c src/abs_mdec.c -o compiled/abs_mdec.o

compiled/cast_mdec.o: src/cast_mdec.c
	$(CC) $(CFLAGS) -c src/cast_mdec.c -o compiled/cast_mdec.o

compiled/compaction_mdec.o: src/compaction_mdec.c
	$(CC) $(CFLAGS) -c src/compaction_mdec.c -o compiled/compaction_mdec.o

compiled/copy_mdec.o: src/copy_mdec.c
	$(CC) $(CFLAGS) -c src/copy_mdec.c -o compiled/copy_mdec.o
