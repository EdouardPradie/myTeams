/*
** EPITECH PROJECT, 2023
** command_b
** File description:
** teams
*/

#include "../../include/teams_client.h"
#include "../../libs/myteams/logging_client.h"

int pclient_channel_print_threads(char **cmd)
{
    return client_channel_print_threads(cmd[1], cmd[2], \
    strtoul(cmd[3], NULL, 0), cmd[4], cmd[5]);
}

int pclient_thread_print_replies(char **cmd)
{
    return client_thread_print_replies(cmd[1], cmd[2],\
    strtoul(cmd[3], NULL, 0), cmd[4]);
}

int pclient_private_message_print_messages(char **cmd)
{
    return client_private_message_print_messages(cmd[1],\
    strtoul(cmd[2], NULL, 0), cmd[3]);
}

int pclient_error_already_exist(char **cmd)
{
    cmd = cmd;
    return client_error_already_exist();
}

int pclient_print_user(char **cmd)
{
    return client_print_user(cmd[1], cmd[2], atoi(cmd[3]));
}
