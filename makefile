#Macros
CC = g++
FLAGS = -Wall -g -std=c++11

#Pattern Rule
%.o: %.c
	$(CC) $(FLAGS) -c $<

all: game

clean:
	rm -f game *.o

game: main.o background.o targets.o extraFunc.o reticle.o music.o sound.o soundBuffer.o clock.o coverArt.o gameover.o score.o highScore.o highScoreManager.o getName.o
	$(CC) $(FLAGS) $< background.o targets.o extraFunc.o reticle.o music.o sound.o soundBuffer.o clock.o coverArt.o gameover.o score.o highScore.o highScoreManager.o getName.o -o $@ -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

main.o: background.h targets.h extra.h music.h sound.h soundBuffer.h clock.h coverArt.h gameover.h reticle.h score.h 

background.o: background.h

reticle.o: reticle.h

targets.o: targets.h extra.h

extraFunc.o: extra.h

music.o: music.h

# screen.o: screen.h

sound.o: sound.h

soundBuffer.o: soundBuffer.h

clock.o: clock.h

coverArt.o: coverArt.h

gameover.o: gameover.h

score.o: score.h

highScore.o: highScore.h

highScoreManager.o: highScoreManager.h

getName.o: getName.h
