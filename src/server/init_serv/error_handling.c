/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** error_handling
*/

#include "../../../include/teams_server.h"

static void search_help_flag(char *const *argv)
{
    while (*argv) {
        if (strcmp(*argv, "-help") == SUCCESS) {
            printf("USAGE: ./myteams_server port\n\
    port is the port number on which the server socket listens.");
            exit(SUCCESS);
        }
        argv++;
    }
}

int err_teams(int argc, char *const *argv)
{
    search_help_flag(argv);
    if (argc != 2) {
        printf("Error: Bad number of arguments, try './myteams_server \
-help'\n");
        return ERROR;
    }
    if (atoi(argv[1]) < 0 || atoi(argv[1]) > MAX_PORT) {
        printf("Invalid port\n");
        return ERROR;
    }
    return FAILURE;
}
