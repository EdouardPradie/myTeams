/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** data_user
*/

#include "../../include/teams_server.h"

int len_name_data(char *variable)
{
    int result = 0;

    while (variable[result] != '=') {
        result += 1;
    }
    return result;
}

static char **equal_separator(char *variable)
{
    char **array = malloc(sizeof(char *) * 3);
    int len_name = len_name_data(variable) + 1;
    int len_block = strlen(variable) - len_name + 1;
    int idx = 0;

    array[0] = malloc(sizeof(char) * len_name);
    array[1] = malloc(sizeof(char) * len_block);
    while (variable[idx] != '=') {
        array[0][idx] = variable[idx];
        idx += 1;
    }
    array[0][idx] = '\0';
    idx += 1;
    for (int i = 0; variable[idx + i] != '\0'; i += 1) {
        array[1][i] = variable[idx + i];
    }
    array[1][len_block - 1] = '\0';
    array[2] = NULL;
    return array;
}

static data_user_t *create_node_from_user_info(char *variable)
{
    data_user_t *node = malloc(sizeof(data_user_t));
    char **array = equal_separator(variable);

    if (!node) {
        return NULL;
    }
    node->name = malloc(sizeof(char) * (strlen(array[0]) + 1));
    node->data = malloc(sizeof(char) * (strlen(array[1]) + 1));
    strcpy(node->name, array[0]);
    if (array[1] == NULL) {
        strcpy(node->data, "\0");
    } else {
        strcpy(node->data, array[1]);
    }
    free_arr(array);
    node->next = NULL;
    return node;
}

static data_user_t *add_node(data_user_t *head, data_user_t *node)
{
    data_user_t *tmp = head;

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

data_user_t *array_to_lc(char **array)
{
    data_user_t *head = NULL;
    data_user_t *node = NULL;

    for (int i = 0; array != NULL && array[i] != NULL; i += 1) {
        node = create_node_from_user_info(array[i]);
        if (!node) {
            return NULL;
        }
        head = add_node(head, node);
    }
    return head;
}
