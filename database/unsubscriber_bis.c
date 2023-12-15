/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** unsubscriber_bis
*/

#include "../include/teams_database.h"

void write_modified_line(FILE *temp, const char *team_uuid, char *line, \
int *first_team)
{
    if (strcmp(line, team_uuid) != 0) {
        if (!(*first_team)) {
            fprintf(temp, ",");
        }
        *first_team = 0;
        fprintf(temp, "%s", line);
    }
}

void process_subscribed_line(FILE *temp, char *line, const char *team_uuid)
{
    fprintf(temp, "subscribed=");
    int first_team = 1;
    char *token = strtok(line + 11, ",");
    while (token != NULL) {
        write_modified_line(temp, team_uuid, token, &first_team);
        token = strtok(NULL, ",");
    }
    fprintf(temp, "\n");
}

void process_lines(FILE *file, FILE *temp, const char *team_uuid)
{
    char line[1024];
    int subscribed_written = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        remove_newline(line);

        if (strncmp(line, "subscribed=", 11) == 0 && !subscribed_written) {
            process_subscribed_line(temp, line, team_uuid);
            subscribed_written = 1;
        } else {
            fprintf(temp, "%s\n", line);
        }
    }
}
