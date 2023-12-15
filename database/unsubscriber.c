/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** unsubscriber
*/

#include "../include/teams_database.h"

void init_file_paths(char *user_file, char *temp_file, const char *user_uuid)
{
    snprintf(user_file, 256, "database/Users/%s.txt", user_uuid);
    snprintf(temp_file, 256, "database/Users/%s.tmp", user_uuid);
}

void replace_original_file(const char *user_file, const char *temp_file)
{
    if (remove(user_file) != 0) {
        perror("Error removing original user file");
    }

    if (rename(temp_file, user_file) != 0) {
        perror("Error renaming temp file");
    }
}

void unsubscribe_team(const char *user_uuid, const char *team_uuid)
{
    char user_file[256], temp_file[256];
    init_file_paths(user_file, temp_file, user_uuid);

    FILE *file = fopen(user_file, "r");
    if (file == NULL) {
        perror("Error opening user file");
        return;
    }
    FILE *temp = fopen(temp_file, "w");
    if (temp == NULL) {
        perror("Error opening temp file");
        fclose(file);
        return;
    }
    process_lines(file, temp, team_uuid);
    fclose(file);
    fclose(temp);
    replace_original_file(user_file, temp_file);
}
