/*
** EPITECH PROJECT, 2025
** minishell2
** File description:
** parser
*/

#include "sh.h"
#include "ctype.h"

static char *get_args(char *str, int i, int base)
{
    char *tmp = malloc(sizeof(char) * ((i - base) + 2));
    int actual = base;
    int adding = 0;

    if (str[i] != ';' && str[i] != ' ')
        i++;
    while (actual < i) {
        if ((adding == 0 && str[actual] == ' ') || (actual + 1 == i &&
            str[actual] == ' ')) {
            actual++;
            continue;
        }
        tmp[adding] = str[actual];
        adding++;
        actual++;
    }
    tmp[adding] = '\0';
    return tmp;
}

int check_redirections(char **args, int i)
{
    for (int x = 0; args[i][x] != '\0'; x++) {
        if (args[i][x] == '>' && args[i + 1] != NULL) {
            write(2, "Ambiguous output redirect.\n", 27);
            return 84;
        }
        if (args[i][x] == '<' && i != 0) {
            write(2, "Ambiguous input redirect.\n", 27);
            return 84;
        }
    }
    return 0;
}

static int check_missing(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if ((my_strcmp(args[i], "<") == 0 || my_strcmp(args[i], "<<") == 0 ||
        my_strcmp(args[i], ">") == 0 || my_strcmp(args[i], ">>") == 0) &&
        (args[i + 1] == NULL || my_strcmp(args[i + 1], "|") == 0)) {
            write(2, "Missing name for redirect.\n", 28);
            return 84;
        }
    }
    return 0;
}

static int check_errors(char **args)
{
    int nb_out = 0;
    int nb_in = 0;

    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], "<") == 0 || my_strcmp(args[i], "<<") == 0)
            nb_in++;
        if (my_strcmp(args[i], ">") == 0 || my_strcmp(args[i], ">>") == 0)
            nb_out++;
    }
    if (nb_in > 1) {
        write(2, "Ambiguous input redirect.\n", 27);
        return 84;
    }
    if (nb_out > 1) {
        write(2, "Ambiguous output redirect.\n", 27);
        return 84;
    }
    if (check_missing(args) == 84)
        return 84;
    return 0;
}

static list_t *add_pipe(char *args)
{
    list_t *list = create_list();
    char **tab;

    if (list == NULL)
        return NULL;
    tab = my_str_to_word_array(args, "|");
    if (check_errors(tab) == 84)
        return NULL;
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == ' ')
            tab[i] = &tab[i][1];
        if (tab[i][my_strlen(tab[i]) == ' '])
            tab[i][my_strlen(tab[i])] = '\0';
        pushback(list, my_strdup(tab[i]));
    }
    return list;
}

static int put_in_list(char *str, int i, int base, shell_t *shell)
{
    data_cmd_t *data = malloc(sizeof(data_cmd_t));
    char *tmp;

    if (data == NULL)
        return 84;
    data->piped = false;
    tmp = get_args(str, i, base);
    for (int i = 0; tmp[i] != '\0'; i++) {
        if (tmp[i] == '|')
            data->piped = true;
    }
    if (data->piped == false){
        data->args = word_array_tok(tmp, " \n\t");
        if (check_errors(data->args) == 84)
            return 84;
    } else
        data->l_pipe = add_pipe(tmp);
    pushback(shell->l_commands, data);
    free(tmp);
    return 0;
}

int separate_commands(char *str, shell_t *shell)
{
    int base = 0;
    char *dupl = my_strdup(str);
    int r_value = 0;

    shell->l_commands = create_list();
    for (int i = 0; dupl[i] != '\0'; i++) {
        if (dupl[i] == ';' && i == 0)
            return 84;
        if ((dupl[i] == ';' && i - base > 0) || dupl[i + 1] == '\0') {
            r_value = put_in_list(dupl, i, base, shell);
            base = i + 1;
        }
        if (r_value == 84)
            return 84;
    }
    free(dupl);
    return 0;
}

int command_parser(char *buffer, shell_t *shell)
{
    data_cmd_t *data;

    if (buffer[my_strlen(buffer) -1] == '\n')
            buffer[my_strlen(buffer) - 1] = '\0';
    if (separate_commands(buffer, shell) == 84){
        free(buffer);
        return 84;
    }
    for (node_t *cur = shell->l_commands->head; cur; cur = cur->next) {
        data = cur->data;
        if (data->piped == true && data->l_pipe == NULL)
            return 84;
    }
    shell->commands = word_array_tok(buffer, " \n\t");
    free(buffer);
    return 0;
}
