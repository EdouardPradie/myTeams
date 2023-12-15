/*
** EPITECH PROJECT, 2023
** teams
** File description:
** simple_command
*/

#include "../../../include/teams_server.h"
#include "../../../include/teams_database.h"

void dele_func(char **tab, client_t *cli)
{
    int tmp;

    if (cli->username == NULL) {
        return;
    }
    tmp = remove(tab[1]);
    if (tmp == 0){
        dprintf(cli->sock, "250 Requested file action okay, completed.");
    } else {
        dprintf(cli->sock, "530 Requested file action is not okay.");
    }
}

void print_users(char *str, client_t *cli)
{
    char *name = malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
    char *uuid = malloc(sizeof(char) * (MAX_NAME_LENGTH + 1));
    int i = 0;
    int j = 0;

    for (; str[i] != '@' && str[i] != '\0'; i += 1)
        name[i] = str[i];
    i += 1;
    name[i] = '\0';
    for (; str[i] != '.' && str[i] != '\0'; i += 1, j += 1)
        uuid[j] = str[i];
    uuid[j] = '\0';
    dprintf(cli->sock, "client_print_users %s %s %d\n", name, uuid, 1);
    free(name);
    free(uuid);
}

void users_func(char **tab, client_t *cli)
{
    DIR *doc = opendir("Users");
    struct dirent *dir;

    if (cli->username == NULL) {
        return;
    }
    while ((dir = readdir(doc)) != NULL) {
        if (dir->d_name[0] != '.') {
            print_users(dir->d_name, cli);
        }
    }
    (void)tab;
}

void no_user_condition(char *login_name, client_t *cli,
    char *login_tmp, node_t *user_infohead)
{
    create_user(login_name);
    search_func(login_name, cli);
    free(login_tmp);
    free_node(user_infohead);
}

void help_func(char **tab, client_t *cli)
{
    dprintf(cli->sock, "200 Help message.\n\
    On how to use the server or the meaning of a particular\n\
    non-standard command.  This reply is useful only to the\n\
    human user.\n");
    (void)tab;
}
