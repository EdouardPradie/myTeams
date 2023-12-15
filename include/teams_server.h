/*
** EPITECH PROJECT, 2023
** include
** File description:
** teams
*/

#ifndef TEAMS_SERVER_H_
    #define TEAMS_SERVER_H_
    #include <string.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <ctype.h>
    #include <netdb.h>
    #include <fcntl.h>
    #include <sys/socket.h>
    #include <sys/wait.h>
    #include <dirent.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <errno.h>
    #include <signal.h>
    #include <sys/stat.h>
    #include "../libs/myteams/logging_server.h"
    #include "../libs/myteams/logging_client.h"

    #define TCP "TCP"
    #define SUCCESS 0
    #define FAILURE 84
    #define ERROR -1
    #define MAX_PORT 65535
    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

typedef struct server_s {
    int port;
    char *path;
    int sock;
    socklen_t sock_size;
    int max_fd;
    fd_set rfds;
    struct protoent *proto;
    struct sockaddr_in sockaddin;
} server_t;

typedef struct node_s {
    char **array;
    struct node_s *next;
} node_t;

typedef struct client_s {
    int sock;
    char *ip;
    char *username;
    int mod;
    char *position;
    int position_idx;
    int status;
    int res;
    char *uuid;
    struct client_s *prev;
    struct client_s *next;
} client_t;

typedef struct data_user_s {
    char *name;
    char *data;
    struct data_user_s *next;
} data_user_t;

int err_teams(int argc, char *const *argv);
server_t *get_server(server_t *my_serv);
int init_client(server_t *my_serv);
char **my_str_to_word_array(char const *str);
void client(char **tab, client_t *cli);
void parse_event_client(client_t *cli, char *line);
int parse_teams(char *port);
char *get_text(const int sock);
void no_user_condition(char *login_name, client_t *cli, char *login_tmp, \
    node_t *user_infohead);
void search_func(char *login_name, client_t *cli);
void set_userinfo(client_t *cli, char **user);

node_t *get_all_user(void);
node_t *add_node_to_list(node_t *head, node_t *node);
node_t *create_node_from_str(char *file);

client_t *create_new_client(int new_socket, struct sockaddr_in client);
client_t * add_cli(client_t *cli, client_t *node);
client_t *did_quit(client_t *cli);

data_user_t *array_to_lc(char **array);

void free_serv(server_t *my_serv);
void free_arr(char **arr);
void free_node(node_t *node);
void data_free(data_user_t *head);

void use_func(char **tab, client_t *cli);
void user_func(char **tab, client_t *cli);
void quit_func(char **tab, client_t *cli);
void users_func(char **tab, client_t *cli);
void help_func(char **tab, client_t *cli);
void userj_func(char **tab, client_t *cli);
void create_func(char **tab, client_t *cli);

#endif
