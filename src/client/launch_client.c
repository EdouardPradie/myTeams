/*
** EPITECH PROJECT, 2023
** launch_client
** File description:
** teams
*/

#include "../../include/teams_client.h"

static int point_function_print(char **cmd, int i)
{
    static int (*function[30])(char **cmd) = {
        &pclient_event_logged_in, &pclient_event_logged_out,
        &pclient_event_private_message_received,
        &pclient_event_thread_reply_received, &pclient_event_team_created,
        &pclient_event_channel_created, &pclient_event_thread_created,
        &pclient_print_users, &pclient_print_teams,
        &pclient_team_print_channels,
        &pclient_channel_print_threads, &pclient_thread_print_replies,
        &pclient_private_message_print_messages, &pclient_error_already_exist,
        &pclient_print_user, &pclient_print_team, &pclient_print_channel,
        &pclient_print_thread, &pclient_print_team_created,
        &pclient_print_channel_created, &pclient_print_thread_created,
        &pclient_print_reply_created, &pclient_print_subscribed,
        &pclient_print_unsubscribed, &pclient_error_unknown_team,
        &pclient_error_unknown_channel, &pclient_error_unknown_thread,
        &pclient_error_unknown_user, &pclient_error_unauthorized, &my_cd};
    (*function[i])(cmd);
    free_arr(cmd);
    return 0;
}

int pf_print(char **cmd)
{
    static const char *func[31] =
    { "client_event_logged_in", "client_event_logged_out",
    "client_event_private_message_received",
    "client_event_thread_reply_received", "client_event_team_created",
    "client_event_channel_created", "client_event_thread_created",
    "client_print_users", "client_print_teams", "client_team_print_channels",
    "client_channel_print_threads", "client_thread_print_replies",
    "client_private_message_print_messages", "client_error_already_exist",
    "client_print_user", "client_print_team", "client_print_channel",
    "client_print_thread", "client_print_team_created",
    "client_print_channel_created", "client_print_thread_created",
    "client_print_reply_created", "client_print_subscribed",
    "client_print_unsubscribed", "client_error_unknown_team",
    "client_error_unknown_channel", "client_error_unknown_thread",
    "client_error_unknown_user", "client_error_unauthorized", "cd", NULL};
    for (int i = 0; func[i] != NULL ; i += 1) {
        if (strcasecmp(cmd[0], func[i]) == 0)
            return point_function_print(cmd, i);
    }
    free_arr(cmd); return 1;
}

int can_connected(char *host, int port, int *client_socket)
{
    struct sockaddr_in server_address;
    int connect_status;

    *client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (*client_socket == -1) {
        perror("socket");
        return 0;
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = inet_addr(host);
    connect_status = connect(*client_socket,
        (struct sockaddr *) &server_address, sizeof(server_address));
    if (connect_status == -1) {
        perror("connect");
        return 0;
    }
    return 1;
}

int launch_client(char *host, int port, int *client_socket)
{
    char buffer[OUT_SIZE];
    if (can_connected(host, port, client_socket) == 0)
        return 0;
    sleep(TIMEOUT);
    int n = read(*client_socket, buffer, OUT_SIZE);
    if (n == ERROR) {
        perror("read");
        return 0;
    }
    buffer[n] = '\0';
    if (chdir(realpath("database/Teams", NULL)) == -1) {
        close(*client_socket);
        exit(84);
    }
    if (pf_print(my_str_to_word_array(buffer)) == 1)
        return 1;
    return 0;
}
