/*
** EPITECH PROJECT, 2024
** my_putchar.c
** File description:
** ..
*/

#include "my.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
