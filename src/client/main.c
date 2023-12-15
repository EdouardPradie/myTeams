/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** main
*/

#include "../../include/teams_client.h"

int main(int argc, char *argv[])
{
    if (error_handling(argc, argv) == ERROR)
        return FAILURE;
    ask_cmd(argv);
    return SUCCESS;
}
