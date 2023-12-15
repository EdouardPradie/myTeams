/*
** EPITECH PROJECT, 2023
** teams
** File description:
** command
*/

#include "../../../include/teams_server.h"
#include "../../../include/teams_database.h"

static void error_message(char **tab, client_t *cli, int idx)
{
    if (idx == 1)
        dprintf(cli->sock, "client_error_unknown_team %s", tab[idx]);
    if (idx == 2)
        dprintf(cli->sock, "client_error_unknown_channel %s", tab[idx]);
    if (idx == 3)
        dprintf(cli->sock, "client_error_unknown_thread %s", tab[idx]);
}

void use_func(char **tab, client_t *cli)
{
    char *dest = strdup("Teams");
    DIR *dir;
    int idx = 1;
    if (cli->username == NULL) {
        dprintf(cli->sock, "client_error_unauthorized");
        return;
    }   while (tab[idx] != NULL) {
        dest = strcat(dest, "/");
        dest = strcat(dest, tab[idx]);
        idx += 1;
    } dir = opendir(dest);
    if (dir != NULL) {
        closedir(dir);
        free(cli->position);
        cli->position = strdup(dest);
        free(dest);
        dprintf(cli->sock, "cd %s %d", cli->position, cli->position_idx);
        cli->position_idx = idx - 1;
        return;
    } error_message(tab, cli, (idx - 1)); free(dest);    closedir(dir);
}

char *slask_to_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == '/')
            str[i] = ' ';
    }
    return str;
}

static int create_mess(char **tab, client_t *cli)
{
    char *uuid = NULL;
    if (cli->position_idx >= 0 && cli->position_idx <= 2 && tab && tab[0] &&
    tab[1] && tab[2] && !tab[3]) {
        uuid = create_tct(cli->position, tab[1], tab[2]);
        if (cli->position_idx == 0) {
            server_event_team_created(uuid, tab[1], cli->uuid);
            dprintf(cli->sock, "client_event_team_created %s \
            %s %s", uuid, tab[1], cli->uuid);
        }   if (cli->position_idx == 1) {
            server_event_channel_created(cli->position, uuid, tab[1]);
            dprintf(cli->sock, "client_event_channel_created %s \
            %s %s", uuid, tab[1], tab[2]);
        }   if (cli->position_idx == 2) {
            server_event_thread_created(uuid, cli->position, cli->uuid, \
            tab[1], tab[2]);
            dprintf(cli->sock, "client_event_thread_created %s \
            %s %i %s %s", uuid, cli->uuid, 156, tab[1], tab[2]);
        }  free(uuid);  return 0;
    } return 1;
}

void create_func(char **tab, client_t *cli)
{
    char *uuid = NULL;
    char *tmp = NULL;

    if (cli->username == NULL) {
        dprintf(cli->sock, "client_error_unauthorized");
        return;
    }
    if (cli->position_idx == 3 && tab && tab[0] && tab[1] && !tab[2]) {
        uuid = create_comment(cli->position, tab[1]);
        server_event_reply_created(uuid, cli->uuid, tab[1]);
        tmp = strdup(cli->position);
        dprintf(cli->sock, "client_event_thread_reply_received %s \
        %s", slask_to_space(tmp), tab[1]);
        free(tmp);  free(uuid);
        return;
    }
    if (create_mess(tab, cli) == 1) {
        return;
    }
}
