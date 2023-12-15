/*
** EPITECH PROJECT, 2023
** test
** File description:
** teams
*/

#include "../../../include/teams_server.h"

int parse_teams(char *port)
{
    server_t *my_serv = malloc(sizeof(server_t));

    if (!my_serv)
        return FAILURE;
    my_serv->port = atoi(port);
    my_serv->path = malloc(sizeof(char) * 2);
    my_serv->path[0] = '.';
    my_serv->path[1] = '\0';
    my_serv = get_server(my_serv);
    if (!my_serv)
        return FAILURE;
    return init_client(my_serv);
}
