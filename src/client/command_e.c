/*
** EPITECH PROJECT, 2023
** command_b
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_print_thread_created(char **cmd)
{
    return client_print_thread_created(cmd[1], cmd[2],\
    strtoul(cmd[3], NULL, 0), cmd[4], cmd[5]);
}

int pclient_print_reply_created(char **cmd)
{
    return client_print_reply_created(cmd[1], cmd[2],\
    strtoul(cmd[3], NULL, 0), cmd[4]);
}

int pclient_print_subscribed(char **cmd)
{
    return client_print_subscribed(cmd[1], cmd[2]);
}

int pclient_print_unsubscribed(char **cmd)
{
    return client_print_unsubscribed(cmd[1], cmd[2]);
}

int my_cd(char **cmd)
{
    int get_back = atoi(cmd[2]);

    while (get_back >= 0) {
        chdir("..");
        get_back -= 1;
    }
    printf("%s\n", cmd[1]);
    chdir(cmd[1]);
    return 0;
}
