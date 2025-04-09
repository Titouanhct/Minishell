/*
** EPITECH PROJECT, 2024
** my_getnbr.c
** File description:
** ..
*/

#include "my.h"

static int check_up(long int nbr, int count)
{
    if (count % 2 == 1){
        nbr = nbr * (-1);
    }
    if ((nbr < -2147483648) || (nbr > 2147483647)) {
        return 0;
    }
    return nbr;
}

int my_getnbr(char const *str)
{
    int i = 0;
    long int nbr = 0;
    int count = 0;

    while (str[i] < 48 || str[i] > 57) {
        if (str[i] == '-') {
            count++;
            i++;
            continue;
        }
        if (str[i] != '+') {
            return 0;
        }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        nbr = (nbr * 10 + str[i] -48);
        i++;
    }
    return (check_up(nbr, count));
}
