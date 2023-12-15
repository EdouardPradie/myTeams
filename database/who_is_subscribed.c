/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database_check_if_subscribe
*/

#include "../include/teams_database.h"

int is_subscribed_line(const char *line, const char *team_uuid)
{
    return strncmp(line, "subscribed=", 11) == 0 && \
strstr(line + 11, team_uuid) != NULL;
}

int is_subscribed_to_team(FILE *file, const char *team_uuid)
{
    char line[1024];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (is_subscribed_line(line, team_uuid)) {
            return 1;
        }
    }
    return 0;
}

void print_user_without_extension(const char *user_file_name)
{
    char user_name[256];
    strncpy(user_name, user_file_name, strlen(user_file_name) - 4);
    user_name[strlen(user_file_name) - 4] = '\0';
    printf("\t%s\n", user_name);
}

void process_user_file(const char *user_file_name, const char *team_uuid)
{
    char user_file[256];
    snprintf(user_file, sizeof(user_file), "database/Users/%s", \
user_file_name);

    FILE *file = fopen(user_file, "r");
    if (file == NULL) {
        perror("Error opening user file");
        return;
    }

    if (is_subscribed_to_team(file, team_uuid)) {
        print_user_without_extension(user_file_name);
    }

    fclose(file);
}

void list_users_subscribed_to_team(const char *team_uuid)
{
    DIR *dir = opendir("database/Users");
    struct dirent *entry;
    if (dir == NULL) {
        perror("Error opening Users directory");
        return;
    }

    printf("Users subscribed to team %s:\n", team_uuid);

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] != '.') {
            process_user_file(entry->d_name, team_uuid);
        }
    }
    closedir(dir);
}
