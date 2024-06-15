GCC = g++
CFLAGS = -std=c++11

main: main.o TextQuery.o QueryResult.o
	$(GCC) $(CFLAGS) -o main main.o TextQuery.o QueryResult.o

main.o: main.cpp TextQuery.o QueryResult.o
	$(GCC) $(CFLAGS) -c main.cpp

TextQuery.o: TextQuery.cpp TextQuery.h QueryResult.h
	$(GCC) $(CFLAGS) -c TextQuery.cpp

QueryResult.o: QueryResult.cpp QueryResult.h
	$(GCC) $(CFLAGS) -c QueryResult.cpp

clean:
	rm -f main main.o TextQuery.o QueryResult.o