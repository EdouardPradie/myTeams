/*
** EPITECH PROJECT, 2023
** teams
** File description:
** command
*/

#include "../../../include/teams_server.h"

void set_userinfo(client_t *cli, char **user)
{
    data_user_t *data = array_to_lc(user);
    data_user_t *tmp = data;

    cli->username = strdup(tmp->data);
    tmp = tmp->next;
    cli->uuid = strdup(tmp->data);
    free(data);
}

void search_func(char *login_name, client_t *cli)
{
    node_t *user_infohead = get_all_user();
    node_t *user_info = user_infohead;
    char *login_tmp = malloc(sizeof(char) * (6 + strlen(login_name) + 1));

    strcpy(login_tmp, "login=");
    strcat(login_tmp, login_name);
    while (user_info != NULL) {
        if (strcmp(user_info->array[0], login_tmp) == 0) {
            free(login_tmp);
            set_userinfo(cli, user_info->array);
            server_event_user_logged_in(cli->uuid);
            dprintf(cli->sock, "client_event_logged_in %s %s", \
            cli->uuid, cli->username);
            free_node(user_infohead);
            return;
        }
        user_info = user_info->next;
    }
    printf("%s\n", login_name);
    no_user_condition(login_name, cli, login_tmp, user_infohead);
}

void user_func(char **tab, client_t *cli)
{
    if (tab && tab[0] && !tab[1])
        return;
    if (tab == NULL || tab[0] == NULL || tab[1] == NULL || tab[1][0] != '"')
        return;
    if (cli->username != NULL)
        return;
    char *username = strdup(tab[1]);
    char *tmp = malloc(sizeof(char) * (strlen(tab[1]) - 2));
    for (int i = 1, j = 0; username[i] != '\0' && username[i] != '"';
    i += 1, j += 1)
        tmp[j] = username[i];
    search_func(tmp, cli);
    free(username);
    free(tmp);
}

void quit_func(char **tab, client_t *cli)
{
    if (tab[0]) {
        if (cli->username == NULL) {
            return;
        }
        dprintf(cli->sock, "client_event_logged_out %s %s", \
            cli->uuid, cli->username);
        server_event_user_logged_out(cli->uuid);
    }
}
