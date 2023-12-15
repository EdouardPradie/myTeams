/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database_reader
*/

#include "../include/teams_database.h"


char *read_file_content(const char *file_path)
{
    FILE *file = fopen(file_path, "w+");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for file content");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0';
    fclose(file);
    return buffer;
}

char *get_user_info(const char *user_uuid)
{
    char user_path[256];
    snprintf(user_path, sizeof(user_path), \
"database/Users/%s.txt", user_uuid);

    return read_file_content(user_path);
}
