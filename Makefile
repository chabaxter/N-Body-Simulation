CC = g++
CFLAGS = -std=c++11 -c -g -Og -Wall -Werror -pedantic
OBJ = main.o Universe.o CelestialBody.o
DEPS = main.cpp Universe.cpp Universe.h CelestialoBody.cpp CelestialBody.h
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
EXE = NBody

all: $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	rm $(OBJ) $(EXE)
