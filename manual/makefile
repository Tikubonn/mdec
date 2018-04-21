
all:
	make manual.lib 
	
clean:
	rm -f compiled/init_mdec.o
	rm -f compiled/copy_mdec_manually.o
	rm -f compiled/commonize_mdec_manually.o
	rm -f compiled/is_equal_mdec_manually.o
	rm -f compiled/is_unequal_mdec_manually.o
	rm -f compiled/is_lesser_mdec_manually.o
	rm -f compiled/is_lesser_or_equal_mdec_manually.o
	rm -f compiled/is_greater_mdec_manually.o
	rm -f compiled/is_greater_or_equal_mdec_manually.o
	rm -f compiled/is_positive_mdec.o compiled/is_negative_mdec.o
	rm -f compiled/is_zero_mdec.o 
	rm -f compiled/add_mdec_manually.o
	rm -f compiled/sub_mdec_manually.o
	rm -f compiled/mul_mdec_manually.o
	rm -f compiled/div_mdec_manually.o
	rm -f compiled/abs_mdec_manually.o	
	rm -f compiled/compacted_mdec_manually.o	
	rm -f compiled/cast_mdec_manually.o	

manual.lib: compiled/init_mdec.o compiled/copy_mdec_manually.o compiled/commonize_mdec_manually.o compiled/is_equal_mdec_manually.o compiled/is_unequal_mdec_manually.o compiled/is_lesser_mdec_manually.o compiled/is_lesser_or_equal_mdec_manually.o compiled/is_greater_mdec_manually.o compiled/is_greater_or_equal_mdec_manually.o compiled/is_positive_mdec.o compiled/is_negative_mdec.o compiled/is_zero_mdec.o compiled/add_mdec_manually.o compiled/sub_mdec_manually.o compiled/mul_mdec_manually.o compiled/div_mdec_manually.o compiled/abs_mdec_manually.o compiled/compacted_mdec_manually.o compiled/cast_mdec_manually.o
	ar r manual.lib compiled/init_mdec.o compiled/copy_mdec_manually.o compiled/commonize_mdec_manually.o compiled/is_equal_mdec_manually.o compiled/is_unequal_mdec_manually.o compiled/is_lesser_mdec_manually.o compiled/is_lesser_or_equal_mdec_manually.o compiled/is_greater_mdec_manually.o compiled/is_greater_or_equal_mdec_manually.o compiled/is_positive_mdec.o compiled/is_negative_mdec.o compiled/is_zero_mdec.o compiled/add_mdec_manually.o compiled/sub_mdec_manually.o compiled/mul_mdec_manually.o compiled/div_mdec_manually.o compiled/abs_mdec_manually.o compiled/compacted_mdec_manually.o compiled/cast_mdec_manually.o

compiled/init_mdec.o: src/init_mdec.c
	$(CC) $(CFLAGS) -c src/init_mdec.c -o compiled/init_mdec.o

compiled/copy_mdec_manually.o: src/copy_mdec_manually.c
	$(CC) $(CFLAGS) -c src/copy_mdec_manually.c -o compiled/copy_mdec_manually.o

compiled/commonize_mdec_manually.o: src/commonize_mdec_manually.c
	$(CC) $(CFLAGS) -c src/commonize_mdec_manually.c -o compiled/commonize_mdec_manually.o

compiled/is_equal_mdec_manually.o: src/is_equal_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_equal_mdec_manually.c -o compiled/is_equal_mdec_manually.o
	
compiled/is_unequal_mdec_manually.o: src/is_unequal_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_unequal_mdec_manually.c -o compiled/is_unequal_mdec_manually.o
	
compiled/is_lesser_mdec_manually.o: src/is_lesser_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_lesser_mdec_manually.c -o compiled/is_lesser_mdec_manually.o
	
compiled/is_lesser_or_equal_mdec_manually.o: src/is_lesser_or_equal_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_lesser_or_equal_mdec_manually.c -o compiled/is_lesser_or_equal_mdec_manually.o
	
compiled/is_greater_mdec_manually.o: src/is_greater_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_greater_mdec_manually.c -o compiled/is_greater_mdec_manually.o
	
compiled/is_greater_or_equal_mdec_manually.o: src/is_greater_or_equal_mdec_manually.c
	$(CC) $(CFLAGS) -c src/is_greater_or_equal_mdec_manually.c -o compiled/is_greater_or_equal_mdec_manually.o
	
compiled/is_positive_mdec.o: src/is_positive_mdec.c
	$(CC) $(CFLAGS) -c src/is_positive_mdec.c -o compiled/is_positive_mdec.o

compiled/is_negative_mdec.o: src/is_negative_mdec.c
	$(CC) $(CFLAGS) -c src/is_negative_mdec.c -o compiled/is_negative_mdec.o

compiled/is_zero_mdec.o: src/is_zero_mdec.c
	$(CC) $(CFLAGS) -c src/is_zero_mdec.c -o compiled/is_zero_mdec.o

compiled/add_mdec_manually.o: src/add_mdec_manually.c
	$(CC) $(CFLAGS) -c src/add_mdec_manually.c -o compiled/add_mdec_manually.o

compiled/sub_mdec_manually.o: src/sub_mdec_manually.c
	$(CC) $(CFLAGS) -c src/sub_mdec_manually.c -o compiled/sub_mdec_manually.o

compiled/mul_mdec_manually.o: src/mul_mdec_manually.c
	$(CC) $(CFLAGS) -c src/mul_mdec_manually.c -o compiled/mul_mdec_manually.o

compiled/div_mdec_manually.o: src/div_mdec_manually.c
	$(CC) $(CFLAGS) -c src/div_mdec_manually.c -o compiled/div_mdec_manually.o

compiled/abs_mdec_manually.o: src/abs_mdec_manually.c
	$(CC) $(CFLAGS) -c src/abs_mdec_manually.c -o compiled/abs_mdec_manually.o

compiled/compacted_mdec_manually.o: src/compacted_mdec_manually.c
	$(CC) $(CFLAGS) -c src/compacted_mdec_manually.c -o compiled/compacted_mdec_manually.o

compiled/cast_mdec_manually.o: src/cast_mdec_manually.c
	$(CC) $(CFLAGS) -c src/cast_mdec_manually.c -o compiled/cast_mdec_manually.o
