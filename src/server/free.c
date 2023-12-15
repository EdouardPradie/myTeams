/*
** EPITECH PROJECT, 2023
** teams
** File description:
** free
*/

#include "../../include/teams_server.h"

void free_serv(server_t *my_serv)
{
    close(my_serv->sock);
    free(my_serv->path);
    free(my_serv);
}

void free_arr(char **arr)
{
    for (int i = -1; arr[++i]; free(arr[i]));
    free(arr);
}

void free_node(node_t *head)
{
    node_t *node = NULL;

    for (int i = 0; head != NULL; i += 1) {
        node = head->next;
        free_arr(head->array);
        free(head);
        head = node;
    }
}

void data_free(data_user_t *head)
{
    data_user_t *node = NULL;

    for (int i = 0; head != NULL; i += 1) {
        node = head->next;
        free(head->name);
        free(head->data);
        free(head);
        head = node;
    }
}
