/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database_users
*/

#include "../include/teams_database.h"

void print_user_details(const char *user_uuid, const char *user_name)
{
    printf("User details:\n");
    printf("UUID: %s\n", user_uuid);
    printf("Name: %s\n", user_name);
}

int process_user_entry(const char *user_uuid, struct dirent *entry)
{
    char *file_uuid = strchr(entry->d_name, '@');
    if (file_uuid != NULL && strncmp(user_uuid, file_uuid + 1, \
strlen(user_uuid)) == 0) {
        char user_name[256];
        strncpy(user_name, entry->d_name, file_uuid - entry->d_name);
        user_name[file_uuid - entry->d_name] = '\0';
        print_user_details(user_uuid, user_name);
        return 1;
    }
    return 0;
}

int find_user_in_directory(DIR *dir, const char *user_uuid)
{
    struct dirent *entry;
    int user_found = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && process_user_entry(user_uuid, entry)) {
            user_found = 1;
            break;
        }
    }
    return user_found;
}

void user_details(const char *user_uuid)
{
    DIR *dir;
    const char *users_dir = "database/Users/";
    dir = opendir(users_dir);
    if (dir == NULL) {
        perror("Error opening users directory");
        return;
    }
    int user_found = find_user_in_directory(dir, user_uuid);

    if (!user_found) {
        printf("User not found.\n");
    }
    closedir(dir);
}
