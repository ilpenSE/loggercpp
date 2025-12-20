CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I.
LDFLAGS := -L. -llogger
RPATH := -Wl,-rpath,'$$ORIGIN'

TARGET := app
SRC := main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(RPATH)

clean:
	rm -f $(TARGET)

.PHONY: all clean
