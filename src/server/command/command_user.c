/*
** EPITECH PROJECT, 2023
** teams
** File description:
** command
*/

#include "../../../include/teams_server.h"

void userj_func(char **tab, client_t *cli)
{
    tab = tab;
    dprintf(cli->sock, "client_print_user %s %s %d", \
    cli->uuid, cli->username, cli->status);
}
