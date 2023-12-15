/*
** EPITECH PROJECT, 2023
** init_serv
** File description:
** teams
*/

#include "../../../include/teams_server.h"

static server_t *get_init_server(server_t *my_serv)
{
    if (bind(my_serv->sock, (const struct sockaddr *)&my_serv->sockaddin,
        sizeof(my_serv->sockaddin)) == -1) {
        shutdown(my_serv->sock, 2);
        close(my_serv->sock);
        printf("Bad port.\n");
        return NULL;
    }
    if (listen(my_serv->sock, 42) == -1){
        close(my_serv->sock);
        return NULL;
    }
    return my_serv;
}

server_t *get_server(server_t *my_serv)
{
    my_serv->proto = getprotobyname(TCP);
    if (my_serv->proto == NULL)
        return NULL;
    my_serv->sock = socket(AF_INET, SOCK_STREAM, my_serv->proto->p_proto);
    if (my_serv->sock == -1)
        return NULL;
    my_serv->sockaddin.sin_family = AF_INET;
    my_serv->sockaddin.sin_port = htons(my_serv->port);
    my_serv->sockaddin.sin_addr.s_addr = INADDR_ANY;
    my_serv->sock_size = sizeof(my_serv->sockaddin);
    return get_init_server(my_serv);
}
