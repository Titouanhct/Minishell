/*
** EPITECH PROJECT, 2025
** shell1
** File description:
** word_array_tok
*/

#include <my.h>
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

int check_delim(char *str, int x, char *delim, int before)
{
    for (int i = 0; delim[i] != '\0'; i++) {
        if (str[x] == delim[i] && before != 1)
            return 1;
    }
    return 0;
}

int get_len(char *str, char *delim)
{
    int before = 0;
    int len = 1;

    for (int x = 0; str[x] != '\0'; x++){
        if (check_delim(str, x, delim, before) == 1) {
            len++;
            before = 1;
        } else
            before = 0;
    }
    return len;
}

char **word_array_tok(char *str, char *delim)
{
    char *tmp;
    char *strToken;
    char **tab = NULL;
    int x = 0;

    if (!str || !delim)
        return tab;
    tmp = my_strdup(str);
    tab = malloc(sizeof(char *) * (get_len(tmp, delim) + 1));
    strToken = strtok(tmp, delim);
    while (strToken != NULL) {
        tab[x] = my_strdup(strToken);
        x++;
        strToken = strtok(NULL, delim);
    }
    tab[x] = NULL;
    free(tmp);
    return tab;
}
