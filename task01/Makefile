##
## EPITECH PROJECT, 2022
## bs_strace
## File description:
## Makefile
##

NAME =		test

ASM =		nasm

LD =		gcc

SRC =		main.S

OBJ =	$(SRC:.S=.o)

LDFLAGS = 	-fno-builtin

CFLAGS = 	-f elf64

.S.o:
	$(ASM) $(CFLAGS) $< -o $@

$(NAME):	$(OBJ)
			$(LD) $(OBJ) -o $(NAME) $(LDFLAGS)

all:	$(NAME)

clean:
			rm - rf $(OBJ)
fclean :	clean
			rm - rf $(NAME)