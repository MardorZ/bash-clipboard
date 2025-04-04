# Makefile for bash-clipboard

CXX = g++
CXXFLAGS = -Wall -Wextra -O2
TARGET = bash-clipboard
SRC = bash-clipboard/bashclipboard.cpp  # <--- updated path

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

install: $(TARGET)
	sudo mv $(TARGET) /usr/local/bin/clipboard

clean:
	rm -f $(TARGET)
