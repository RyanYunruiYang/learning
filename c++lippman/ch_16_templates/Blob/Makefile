CXX = g++
CXXFLAGS = -std=c++11

TARGET = main
OBJECTS = main.o Blob.o
SOURCES = main.cpp Blob.cpp 

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

main.o: main.cpp Blob.h 
	$(CXX) $(CXXFLAGS) -c main.cpp

Blob.o: Blob.cpp Blob.h
	$(CXX) $(CXXFLAGS) -c Blob.cpp

clean:
	rm -f $(TARGET) $(OBJECTS)