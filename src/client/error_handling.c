/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** error_handling
*/

#include "../../include/teams_client.h"

static void search_help_flag(char *const *argv)
{
    while (*argv) {
        if (strcmp(*argv, "-help") == SUCCESS) {
            printf("USAGE: ./myteams_cli ip port\n\
            ip   is the server ip address on which the server socket listens\n\
            port is the port number on which the server socket listens\n");
            exit(SUCCESS);
        }
        argv++;
    }
}

int error_handling(int argc, char *const *argv)
{
    search_help_flag(argv);
    if (argc != 3) {
        printf("Error: Bad number of arguments, try './myteams_cli -help'\n");
        return ERROR;
    }
    if (atoi(argv[2]) < 0 || atoi(argv[2]) > MAX_PORT) {
        printf("Invalid port\n");
        return ERROR;
    }
    return SUCCESS;
}
