/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database_teams
*/

#include "../include/teams_database.h"


long find_subscribed_line(FILE *file)
{
    char line[1024];
    long line_pos = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strncmp(line, "subscribed=", 11) == 0) {
            return line_pos;
        }
        line_pos = ftell(file);
    }
    return -1;
}

void update_subscribed_line(FILE *file, long line_pos, const char *team_uuid)
{
    char line[1024];
    fseek(file, line_pos, SEEK_SET);
    fgets(line, sizeof(line), file);
    char *newline = strchr(line, '\n');
    if (newline != NULL)
        *newline = '\0';
    fseek(file, line_pos, SEEK_SET);
    fprintf(file, "%s,%s\n", line, team_uuid);
    fseek(file, 0, SEEK_END);
    fprintf(file, "\n");
}

void subscribe_team(const char *user_uuid, const char *team_uuid)
{
    char user_file[256];
    snprintf(user_file, sizeof(user_file), "database/Users/%s.txt", user_uuid);

    FILE *file = fopen(user_file, "r+");
    if (file == NULL) {
        perror("Error opening user file");
        return;
    }
    long line_pos = find_subscribed_line(file);
    if (line_pos == -1) {
        fseek(file, 0, SEEK_END);
        fprintf(file, "subscribed=%s\n", team_uuid);
    } else {
        update_subscribed_line(file, line_pos, team_uuid);
    }
    fclose(file);
}
