##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## ..
##

NAME    =   libmy.a

SRC     =   my/my_compute_power_rec.c \
            my/my_compute_square_root.c \
            my/my_find_prime_sup.c \
            my/my_getnbr.c \
            my/my_isneg.c \
            my/my_is_prime.c \
            my/my_putchar.c \
            my/my_put_nbr.c \
            my/my_putstr.c \
            my/my_revstr.c \
            my/my_show_word_array.c \
            my/my_sort_int_array.c \
            my/my_strcapitalize.c \
            my/my_strcat.c \
            my/my_strcmp.c \
            my/my_strcpy.c \
            my/my_strdup.c \
            my/my_str_isalpha.c \
            my/my_str_islower.c \
            my/my_str_isnum.c \
            my/my_strlen.c \
            my/my_strlowcase.c \
            my/my_strncat.c \
            my/my_strncmp.c \
            my/my_strncpy.c \
            my/my_strstr.c \
            my/my_str_to_word_array.c \
            my/my_strupcase.c \
            my/my_swap.c \
            my/my_strcatdup.c \
            my/my_put_bignbr.c \
            my/mini_printf.c \
            my/my_str_isupper.c \
            my/my_catchar.c \
            my/my_cat.c \
            my/destroy_array.c \
            my/word_array_tok.c \
            my/free_list.c \
            my/list_to_array.c \
            list/create_list.c \
            list/pushback.c \
            list/pushfront.c \
            list/popback.c \
            list/popfront.c \
            list/destroy_node.c \
            list/my_apply_on_matching_nodes.c \
            list/my_apply_on_nodes.c \
            list/switch_nodes.c \
            list/my_rev_list.c

OBJ     = $(SRC:.c=.o)

INCLUDE = ../include/

LDFLAGS	= -L./ -lmy

CFLAGS	= $(INCLUDE:%=-I%) -Wall -Wextra -g

all: $(NAME)

$(NAME): $(OBJ)
	ar rc libmy.a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:     fclean all
