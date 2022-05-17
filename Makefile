exec = rsh
src = $(wildcard src/*.c)
obj = $(src:.c=.o)
flags = -g -Wall -std=c99 -I include

$(exec): $(objects)
	gcc $(src) $(objects) $(flags) -o bin/$(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@
