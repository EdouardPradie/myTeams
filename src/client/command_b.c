/*
** EPITECH PROJECT, 2023
** command_b
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_event_channel_created(char **cmd)
{
    return client_event_channel_created(cmd[2], cmd[3], cmd[4]);
}

int pclient_event_thread_created(char **cmd)
{
    return client_event_thread_created(cmd[1], cmd[2],\
    strtoul(cmd[3], NULL, 0), cmd[4], cmd[5]);
}

int pclient_print_users(char **cmd)
{
    return client_print_users(cmd[1], cmd[2], atoi(cmd[3]));
}

int pclient_print_teams(char **cmd)
{
    return client_print_teams(cmd[1], cmd[2], cmd[3]);
}

int pclient_team_print_channels(char **cmd)
{
    return client_team_print_channels(cmd[1], cmd[2], cmd[3]);
}
