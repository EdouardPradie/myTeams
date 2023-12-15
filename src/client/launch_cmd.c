/*
** EPITECH PROJECT, 2023
** launch_cmd
** File description:
** teams
*/

#include "../../include/teams_client.h"

static int read_client(int client_socket, int idx)
{
    char buffer[OUT_SIZE];
    sleep(TIMEOUT);
    int n = read(client_socket, buffer, OUT_SIZE);

    if (n == -1) {
        perror("read");
        return -1;
    }
    buffer[n] = '\0';
    pf_print(my_str_to_word_array(buffer));
    if (idx == 1)
        return -1;
    return idx;
}

static int send_client(int client_socket, int idx)
{
    int i = 0;
    unsigned long size = CMD_SIZE;
    char *cmd = malloc(sizeof(char) * (size));
    int res = getline(&cmd, &size, stdin);

    if (res == -1) {
        return -1;
    }
    while (cmd[i] != '\n')
        i += 1;
    cmd[i] = '\0';
    write(client_socket, strcat(cmd, "\r\n"), (strlen(cmd) + 2));
    if (strcmp(cmd ,"/logout\r\n") == 0) {
        return 1;
    }
    return idx;
}

int launch_cmd(int client_socket, int idx)
{
    fd_set fds;

    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    FD_SET(client_socket, &fds);
    if (select(client_socket + 1, &fds, NULL, NULL, NULL) == -1) {
        if (errno != EINTR) {
            perror("select()");
        }
        return -1;
    }
    if (FD_ISSET(client_socket, &fds))
        return read_client(client_socket, idx);
    if (FD_ISSET(STDIN_FILENO, &fds))
        return send_client(client_socket, idx);
    return idx;
}

int ask_cmd(char *const *argv)
{
    char *host = argv[1];
    int port = atoi(argv[2]);
    int client_socket;
    int res = 0;

    if (launch_client(host, port, &client_socket) != 1) {
        return FAILURE;
    }
    while (res != -1) {
        res = launch_cmd(client_socket, res);
    }
    close(client_socket);
    return 0;
}
