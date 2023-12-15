/*
** EPITECH PROJECT, 2023
** teams
** File description:
** creat_new_client
*/

#include "../../../include/teams_server.h"

client_t *create_new_client(int new_socket, struct sockaddr_in client)
{
    client_t *cli = malloc(sizeof(client_t));

    cli->sock = new_socket;
    cli->ip = inet_ntoa(client.sin_addr);
    cli->position = strdup("Teams/");
    cli->position_idx = 0;
    cli->res = 0;
    cli->status = 0;
    cli->username = NULL;
    cli->uuid = NULL;
    cli->prev = NULL;
    cli->next = NULL;
    return cli;
}

client_t *add_cli(client_t *cli, client_t *node)
{
    client_t *tmp = cli;

    if (cli == NULL) {
        cli = node;
    } else {
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
        node->prev = tmp;
    }
    return cli;
}

static void free_cli(client_t *cli)
{
    if (cli->username)
        free(cli->username);
    if (cli->uuid)
        free(cli->uuid);
    free(cli);
    cli = NULL;
}

static client_t *did_qt(client_t *cli)
{
    client_t *prev = cli->prev;
    client_t *next = cli->next;

    if (cli && cli->res == 1) {
        if (prev != NULL)
            prev->next = next;
        if (next != NULL)
            next->prev = prev;
        cli->res = 0;
        free_cli(cli);
    }
    return next;
}

client_t *did_quit(client_t *cli)
{
    client_t *tmp = cli;

    if (cli && cli->res == 1 && cli->prev == NULL &&
    cli->next == NULL) {
        free_cli(cli);
        return NULL;
    }
    if (cli && cli->res == 1 && cli->prev == NULL) {
        tmp = cli->next;
        free_cli(cli);
        return tmp;
    }
    while (tmp != NULL) {
        tmp = did_qt(tmp);
    }
    return cli;
}
