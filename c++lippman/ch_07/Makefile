CC = g++
CFLAGS = -Wall -g -std=c++11

main: main.o Screen.o Window_mgr.o
	$(CC) $(CFLAGS) -o main main.o Screen.o Window_mgr.o

main.o: main.cpp Screen.h Window_mgr.h
	$(CC) $(CFLAGS) -c main.cpp

Screen.o: Screen.cpp Screen.h
	$(CC) $(CFLAGS) -c Screen.cpp

Window_mgr.o: Window_mgr.cpp Window_mgr.h
	$(CC) $(CFLAGS) -c Window_mgr.cpp

clean:
	rm -f *.o main