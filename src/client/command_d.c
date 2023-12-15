/*
** EPITECH PROJECT, 2023
** command_b
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_print_team(char **cmd)
{
    return client_print_team(cmd[1], cmd[2], cmd[3]);
}

int pclient_print_channel(char **cmd)
{
    return client_print_channel(cmd[1], cmd[2], cmd[3]);
}

int pclient_print_thread(char **cmd)
{
    return client_print_thread(cmd[1], cmd[2],\
    strtoul(cmd[3], NULL, 0), cmd[4], cmd[5]);
}

int pclient_print_team_created(char **cmd)
{
    return client_print_team_created(cmd[1], cmd[2], cmd[3]);
}

int pclient_print_channel_created(char **cmd)
{
    return client_print_channel_created(cmd[1], cmd[2], cmd[3]);
}
