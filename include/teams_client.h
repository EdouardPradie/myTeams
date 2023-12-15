/*
** EPITECH PROJECT, 2023
** include
** File description:
** teams
*/

#ifndef TEAMS_CLIENT_H_
    #define TEAMS_CLIENT_H_
    #include <arpa/inet.h>
    #include <errno.h>
    #include <netinet/in.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include "../libs/myteams/logging_client.h"

    #define TIMEOUT  1
    #define OUT_SIZE 1024
    #define CMD_SIZE 1024
    #define SUCCESS 0
    #define FAILURE 84
    #define ERROR -1
    #define MAX_PORT 65535
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

int error_handling(int argc, char *const *argv);
int launch_client(char *host, int port, int *client_socket);
int ask_cmd(char *const *argv);
int pf_print(char **cmd);
void free_arr(char **arr);

char **my_str_to_word_array(char const *str);

int my_cd(char **cmd);
int pclient_event_logged_in(char **cmd);
int pclient_event_logged_out(char **cmd);
int pclient_event_private_message_received(char **cmd);
int pclient_event_thread_reply_received(char **cmd);
int pclient_event_team_created(char **cmd);
int pclient_event_channel_created(char **cmd);
int pclient_event_thread_created(char **cmd);
int pclient_print_users(char **cmd);
int pclient_print_teams(char **cmd);
int pclient_team_print_channels(char **cmd);
int pclient_channel_print_threads(char **cmd);
int pclient_thread_print_replies(char **cmd);
int pclient_private_message_print_messages(char **cmd);
int pclient_error_already_exist(char **cmd);
int pclient_print_user(char **cmd);
int pclient_print_team(char **cmd);
int pclient_print_channel(char **cmd);
int pclient_print_thread(char **cmd);
int pclient_print_team_created(char **cmd);
int pclient_print_channel_created(char **cmd);
int pclient_print_thread_created(char **cmd);
int pclient_print_reply_created(char **cmd);
int pclient_print_subscribed(char **cmd);
int pclient_print_unsubscribed(char **cmd);
int pclient_error_unknown_team(char **cmd);
int pclient_error_unknown_channel(char **cmd);
int pclient_error_unknown_thread(char **cmd);
int pclient_error_unknown_user(char **cmd);
int pclient_error_unauthorized(char **cmd);

#endif
