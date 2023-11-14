#Macros
CC = g++
FLAGS = -Wall -std=c++11

#Pattern Rule
%.o: %.c
	$(CC) $(FLAGS) -c $<

all: game

clean:
	rm -f game *.o

game: main.o background.o targets.o extraFunc.o
	$(CC) $(FLAGS) $< background.o targets.o extraFunc.o -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: background.h targets.h extra.h

background.o: background.h

targets.o: targets.h extra.h

extraFunc.o: extra.h