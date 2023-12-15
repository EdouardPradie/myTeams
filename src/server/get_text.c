/*
** EPITECH PROJECT, 2023
** myteams
** File description:
** get_text
*/

#include "../../include/teams_server.h"

char *get_text(const int sock)
{
    int len = 0;
    char *res = malloc(sizeof(char) * 100);

    if (res == NULL)
        return NULL;
    len = read(sock, res, 100);
    if (len == 0)
        return NULL;
    res[len] = '\0';
    return res;
}

node_t *get_all_user(void)
{
    DIR *doc = opendir("Users");
    struct dirent *dir;
    node_t *head = NULL;
    char *tmp = NULL;

    while ((dir = readdir(doc)) != NULL) {
        if (dir->d_name[0] != '.') {
            tmp = malloc(sizeof(char) * (6 + strlen(dir->d_name) + 1));
            strcpy(tmp, "Users/");
            strcat(tmp, dir->d_name);
            tmp[6 + strlen(dir->d_name)] = '\0';
            head = add_node_to_list(head, create_node_from_str(tmp));
            free(tmp);
        }
    }
    return head;
}
