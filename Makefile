CFLAGS = -std=c99 -g -Wall -Wshadow --pedantic -Wvla -Werror
GCC = gcc $(CFLAGS) $(TESTS)
EXEC = rpn
OBJS =  rpn.o stack.o calc.o
VALGRIND = valgrind --tool=memcheck --leak-check=yes --verbose

all: rpn

$(EXEC) : $(OBJS)
	$(GCC) $(OBJS) -o $(EXEC) 

test: $(EXEC)
	./$(EXEC) inputs/test1 > output1
	./$(EXEC) inputs/test2 > output2
	./$(EXEC) inputs/test3 > output3
	-./$(EXEC) inputs/test4 > output4
	-./$(EXEC) inputs/test5 > output5

memory: $(EXEC)
	$(VALGRIND) --log-file=log1 ./$(EXEC) inputs/test1
	$(VALGRIND) --log-file=log2 ./$(EXEC) inputs/test2
	$(VALGRIND) --log-file=log3 ./$(EXEC) inputs/test3
	-$(VALGRIND) --log-file=log4 ./$(EXEC) inputs/test4
	-$(VALGRIND) --log-file=log5 ./$(EXEC) inputs/test5

%.o : %.c
	$(GCC) -c $< 

clean:
	/bin/rm -f *.o
	/bin/rm -f $(EXEC)
	/bin/rm -f output? log?