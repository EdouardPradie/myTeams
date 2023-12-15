/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** create_user
*/

#include "../include/teams_database.h"

char *generate_uuid(void)
{
    uuid_t uuid;
    uuid_generate_random(uuid);
    char str_full_uuid[37];
    uuid_unparse_lower(uuid, str_full_uuid);

    char *str_uuid = malloc(5);
    strncpy(str_uuid, str_full_uuid, 4);
    str_uuid[4] = '\0';
    return str_uuid;
}

void create_user(const char *user_name)
{
    char *user_uuid = generate_uuid();
    char file_name[256];
    snprintf(file_name, sizeof(file_name), "Users/%s@%s.txt", \
user_name, user_uuid);
    FILE *file = fopen(file_name, "w+");
    if (file == NULL) {
        perror("Error opening file");
        free(user_uuid);
        return;
    }
    fprintf(file, "login=%s\nuuid=%s\nsubscribed=", user_name,user_uuid);
    fclose(file);
    server_event_user_created(user_uuid, user_name);
    free(user_uuid);
}
