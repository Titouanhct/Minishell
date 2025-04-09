/*
** EPITECH PROJECT, 2024
** mini_printf.c
** File description:
** This fuction is a mini_printf.
*/

#include <stdarg.h>
#include "my.h"

void check(int i, va_list list, const char *format, ...)
{
    switch (format[i + 1]) {
    case 's' :
        my_putstr(va_arg(list, char *));
        break;
    case 'c' :
        my_putchar(va_arg(list, int));
        break;
    case '%' :
        my_putchar('%');
        break;
    case 'd' :
        my_put_nbr(va_arg(list, int));
        break;
    case 'i' :
        my_put_nbr(va_arg(list, int));
        break;
    }
}

int mini_printf(const char *format, ...)
{
    va_list list;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            check(i, list, format);
            i++;
        } else {
            my_putchar(format[i]);
        }
    }
    va_end(list);
    return 0;
}
