/*
** EPITECH PROJECT, 2025
** minishell1
** File description:
** destroy_array
*/

#include "unistd.h"
#include "stdlib.h"

void destroy_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}
