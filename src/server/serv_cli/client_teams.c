/*
** EPITECH PROJECT, 2023
** teams
** File description:
** free
*/

#include "../../../include/teams_server.h"

static void point_function(char **tab, client_t *cli, int i)
{
    static void (*function[7])(char **tab, client_t *cli) = {
    &use_func, &user_func, &quit_func, &userj_func, &users_func, &help_func,
    &create_func};

    (*function[i])(tab, cli);
}

static int command(char **tab, client_t *cli)
{
    static const char *func[8] =
    {"/use", "/login", "/logout", "/user", "/users", "/help",
    "/create", NULL};

    for (int i = 0; func[i] != NULL ; i += 1) {
        if (strcasecmp(tab[0], func[i]) == 0) {
            point_function(tab, cli, i);
            return 0;
        }
    }
    return 1;
}

void client(char **tab, client_t *cli)
{
    if (tab == NULL || command(tab, cli) != 0) {
        dprintf(cli->sock, "500 Unknow command.\n");
        return;
    }
}

void parse_event_client(client_t *cli, char *line)
{
    char **tab = NULL;

    tab = my_str_to_word_array(line);
    if (tab == NULL) {
        dprintf(cli->sock, "500 Unknow command.\n");
        return;
    }
    client(tab, cli);
    free_arr(tab);
    free(line);
}
