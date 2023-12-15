/*
** EPITECH PROJECT, 2023
** teams
** File description:
** pos
*/

#include "../../include/teams_server.h"

int my_isalphanum(char c)
{
    if (c != ' ' && c != '\r' && c != '\t' && c != '\n' && c != '\0'){
        return (1);
    }
    return (0);
}

int get_nb_words(char const *str)
{
    int i = 0;
    int nb_words = 0;

    while (str[i] != '\0') {
        if (my_isalphanum(str[i]) == 1 &&
            my_isalphanum(str[i + 1]) == 0){
            nb_words += 1;
            }
        i += 1;
    }
    return (nb_words);
}

int my_lenword(char const *str, int total)
{
    int idx = 0;

    while (my_isalphanum(str[total]) != 1 && str[total] != '\0') {
        total += 1;
    }
    while (my_isalphanum(str[total]) != 0 && str[total] != '\0'){
        idx += 1;
        total += 1;
    }
    return idx;
}

char **my_str_to_word_array(char const *str)
{
    char **dest = NULL;
    int total = 0;
    int s = 0;
    int nb_words = get_nb_words(str);

    dest = malloc(sizeof(char *) * (nb_words + 1));
    dest[nb_words] = NULL;
    for (int j = 0; j != nb_words; j += 1) {
        s = my_lenword(str, total);
        dest[j] = malloc(sizeof(char) * (s + 1));
        for (int f = 0; f != s; f += 1){
            dest[j][f] = str[total + f];
        }
        dest[j][s] = '\0';
        total += (s + 1);
        if (str[total - 1] == '\0')
            return dest;
    }
    return dest;
}
