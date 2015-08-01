all: challenge-problem-2 random-numbers

challenge-problem-2: challenge-problem-2.c
	gcc -O3 -std=c99 -o challenge-problem-2 challenge-problem-2.c

random-numbers: random-numbers.c
	gcc -O3 -std=c99 -o random-numbers random-numbers.c

run: challenge-problem-2
	./challenge-problem-2

