/*
** EPITECH PROJECT, 2023
** myteams
** File description:
** node
*/

#include "../../include/teams_server.h"

node_t *add_node_to_list(node_t *head, node_t *node)
{
    node_t *tmp = head;

    if (head == NULL) {
        head = node;
    } else {
        while (tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    return head;
}

node_t *free_node_and_return_null(node_t *node)
{
    free(node);
    return NULL;
}

node_t *create_node_from_str(char *filepath)
{
    struct stat info;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    node_t *node = malloc(sizeof(node_t));
    char *buff = NULL;
    if (fd == -1) {
        free_node_and_return_null(node);
    }
    node->next = NULL;
    stat(filepath, &info);
    size = info.st_size;
    if (size == 0){
        free_node_and_return_null(node);
    }
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    buff[size] = '\0';
    node->array = my_str_to_word_array(buff);
    return node;
}
