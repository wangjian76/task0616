CC=g++
CFLAGS=-Wall -Wextra -std=c++11 -O3 -DNDEBUG -DHAVEGETRUSAGE -DHAVEUNLOCKEDIO
DEP=@DEP@

BUILD_PATH=build/
SRC_PATH=src/
SRC      :=  $(wildcard src/*.cpp) \

OBJECTS := $(SRC:$(SRC_PATH)%.cpp=$(BUILD_PATH)%.o)

all: aiger amulet

aiger:
	gcc -O3 -DNDEBUG -c includes/aiger.c -o includes/aiger.o

$(BUILD_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

amulet: $(OBJECTS) aiger
	$(CC) $(CFLAGS)  -o  $@ $(OBJECTS) includes/aiger.o -lgmp

clean:
	rm -f amulet makefile includes/aiger.o \
	rm -rf build/
