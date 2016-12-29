CC = gcc
EXEC = bin/Sortie
OBJPATH = obj/
DEBUG = yes
SRC= $(wildcard *.c)
OBJ= ${OBJPATH}$(SRC:.c=.o)

ifeq ($(DEBUG),yes)
	CFLAGS = -W -Wall 
	LDFLAGS= -g 
else
	CFLAGS =
	LDFLAGS=
endif


all: $(EXEC)

$(EXEC): ${OBJ}
	$(CC) $^ -o $(EXEC) $(LDFLAGS)

${OBJPATH}%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clear mrproper

clear:
	rm -f ${OBJPATH}*.o

mrproper: clear
	rm -f $(EXEC)
