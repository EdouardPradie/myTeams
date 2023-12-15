/*
** EPITECH PROJECT, 2023
** command_a
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_error_unknown_team(char **cmd)
{
    return client_error_unknown_team(cmd[1]);
}

int pclient_error_unknown_channel(char **cmd)
{
    return client_error_unknown_channel(cmd[1]);
}

int pclient_error_unknown_thread(char **cmd)
{
    return client_error_unknown_thread(cmd[1]);
}

int pclient_error_unknown_user(char **cmd)
{
    return client_error_unknown_user(cmd[1]);
}

int pclient_error_unauthorized(char **cmd)
{
    cmd = cmd;
    return client_error_unauthorized();
}
