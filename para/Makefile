CXX = g++
CXXFLAGS = -std=c++11 -Wall 
OPENCV_LIBS = $(shell pkg-config --libs opencv4)
OPENCV_CFLAGS = $(shell pkg-config --cflags opencv4)

TARGET = paralelo
SRC = paralelo.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(OPENCV_CFLAGS) $(OPENCV_LIBS)

.PHONY: clean run_threads

clean:
	rm -f $(TARGET)

run_threads:
	./$(TARGET) $(filter-out $@,$(MAKECMDGOALS))

%:
	@:
