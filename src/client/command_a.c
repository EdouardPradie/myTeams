/*
** EPITECH PROJECT, 2023
** command_a
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_event_logged_in(char **cmd)
{
    return client_event_logged_in(cmd[1], cmd[2]);
}

int pclient_event_logged_out(char **cmd)
{
    return client_event_logged_out(cmd[1], cmd[2]);
}

int pclient_event_private_message_received(char **cmd)
{
    return client_event_private_message_received(cmd[1], cmd[2]);
}

int pclient_event_thread_reply_received(char **cmd)
{
    return client_event_thread_reply_received(cmd[1], cmd[2], cmd[3], cmd[4]);
}

int pclient_event_team_created(char **cmd)
{
    return client_event_team_created(cmd[1], cmd[2], cmd[3]);
}
