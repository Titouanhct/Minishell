/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** list_to_array
*/

#include "my.h"
#include "stdlib.h"
#include "stdio.h"
#include "sh.h"

static info_t *fill_data(char **line)
{
    info_t *data = malloc(sizeof(info_t));
    int last;

    if (!line[0])
        return NULL;
    else
        data->left = my_strdup(line[0]);
    last = my_strlen(data->left) - 1;
    if (data->left[last] == '=')
        data->left[last] = '\0';
    if (!line[1])
        data->right = my_strdup("");
    else
        data->right = my_strdup(line[1]);
    return data;
}

list_t *array_to_list(char **array)
{
    list_t *list = create_list();
    char **line;

    for (int i = 0; array[i]; i++) {
        line = my_str_to_word_array(array[i], "=");
        pushback(list, fill_data(line));
        destroy_array(line);
    }
    destroy_array(array);
    return list;
}

char **list_to_array(list_t *list)
{
    char **array = malloc(sizeof(char *) * (list->size + 1));
    int i = 0;
    info_t *data;
    char *temp;

    for (node_t *cur = list->head; cur; cur = cur->next) {
        data = cur->data;
        temp = my_strcatdup(data->left, "=");
        if (data->right)
            array[i] = my_strcatdup(temp, data->right);
        else
            array[i] = my_strdup(temp);
        i++;
        free(temp);
    }
    array[i] = NULL;
    free_list(list);
    return array;
}
