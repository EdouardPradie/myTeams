/*
** EPITECH PROJECT, 2023
** main
** File description:
** teams
*/

#include "../../../include/teams_server.h"
#include "../../../include/teams_database.h"

int main(const int argc, char *const *argv)
{
    unsubscribe_team("TEST@6969", "TEAMTEST@32");
    if (err_teams(argc, argv) == ERROR)
        return FAILURE;
    parse_teams(argv[1]);
    return SUCCESS;
}
