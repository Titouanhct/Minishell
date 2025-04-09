##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## ..
##

NAME	=	mysh

SRC =  src/main.c
SRC += src/init_shell.c
SRC += src/main_loop.c
SRC += src/signal.c
SRC += src/exec_pipe.c
SRC += src/destroy_at_end.c
SRC += src/cmd/cmd_get.c
SRC += src/cmd/cmd_parser.c
SRC += src/cmd/cmd_valid.c
SRC += src/cmd/cmd_exec.c
SRC += src/exec_output.c
SRC += src/builtins/builtins_cd.c
SRC += src/builtins/builtins_check.c
SRC += src/builtins/builtins_env.c
SRC += src/builtins/builtins_exit.c
SRC += src/builtins/builtins_setenv.c
SRC += src/builtins/builtins_unsetenv.c

OBJ = $(SRC:.c=.o)

CFLAGS = -I./include/ -L lib/ -lmy -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/
	gcc $(OBJ) -o $(NAME) $(CFLAGS)

clean :
	make clean -C ./lib/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./lib/
	rm -f $(NAME)

re: fclean all
