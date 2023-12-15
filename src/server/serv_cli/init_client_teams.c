/*
** EPITECH PROJECT, 2023
** init_client
** File description:
** teams
*/

#include "../../../include/teams_server.h"

static void event_client(server_t *my_serv, client_t *cli)
{
    char *line = NULL;

    if (FD_ISSET(cli->sock, &my_serv->rfds)) {
        line = get_text(cli->sock);
        if (line != NULL)
            parse_event_client(cli, line);
    }
}

void handle_ctrl_c(int sig)
{
    (void)sig;
    exit(0);
}

static client_t * cli_accept(server_t *my_serv, client_t *cli)
{
    int new_socket = 0;
    struct sockaddr_in client;
    int client_size = sizeof(client);

    if (FD_ISSET(my_serv->sock, &my_serv->rfds)) {
        if ((new_socket = accept(my_serv->sock,
        (struct sockaddr *) &client, (socklen_t *)&client_size)) == -1) {
            perror("accept()");
            exit(84);
        }
        cli = add_cli(cli, create_new_client(new_socket, client));
        dprintf(new_socket, "220 Welcome To Summoner's Rift");
    }
    return cli;
}

static int get_client(server_t *my_serv, client_t *cli)
{
    struct timeval tv;

    FD_ZERO(&my_serv->rfds);
    FD_SET(my_serv->sock, &my_serv->rfds);
    my_serv->max_fd = my_serv->sock;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    for (client_t *tmpcli = cli; tmpcli != NULL ; tmpcli = tmpcli->next) {
        if (tmpcli->sock > 0)
            FD_SET(tmpcli->sock, &my_serv->rfds);
        if (tmpcli->sock > my_serv->max_fd)
            my_serv->max_fd = tmpcli->sock;
    }
    int sel = select(my_serv->max_fd + 1, &my_serv->rfds, NULL, NULL, &tv);
    if (sel < 0) {
        if (errno == EINTR)
            return -1;
    }
    return sel;
}

int init_client(server_t *my_serv)
{
    client_t *my_cli = NULL;
    int sel = 0;

    signal(SIGINT, handle_ctrl_c);
    if (chdir(realpath("database", NULL)) == -1) {
        close(my_serv->sock);
        return 84;
    }
    while (1) {
        if ((sel = get_client(my_serv, my_cli)) == 0 && sel == -1)
            continue;
        if ((my_cli = cli_accept(my_serv, my_cli)) == NULL)
            continue;
        for (client_t *tmpcli = my_cli; tmpcli != NULL; tmpcli = tmpcli->next) {
            event_client(my_serv, tmpcli);
        }
        my_cli = did_quit(my_cli);
    }
    free_serv(my_serv);
    return 0;
}
