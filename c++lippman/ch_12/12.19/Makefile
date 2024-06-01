CXX = g++
CXXFLAGS = -std=c++11

all: $(TARGET)

main: main.o StrBlob.o StrBlobPtr.o
	$(CXX) $(CXXFLAGS) -o main main.o StrBlob.o StrBlobPtr.o

main.o: main.cpp StrBlob.h StrBlobPtr.h
	$(CXX) $(CXXFLAGS) -c main.cpp

StrBlob.o: StrBlob.cpp StrBlob.h StrBlobPtr.h
	$(CXX) $(CXXFLAGS) -c StrBlob.cpp

StrBlobPtr.o: StrBlobPtr.cpp StrBlobPtr.h StrBlob.h
	$(CXX) $(CXXFLAGS) -c StrBlobPtr.cpp

clean:
	rm -f *.o