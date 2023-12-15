/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database_utils
*/

#include "../include/teams_database.h"

void remove_newline(char *str)
{
    char *newline = strchr(str, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
}
