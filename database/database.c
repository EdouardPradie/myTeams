/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** database
*/

#include "../include/teams_database.h"

char *create_tct(char *position, const char *name, const char *description)
{
    char *uuid = strdup(position);
    uuid = strcat(uuid, "/");
    char *res = generate_uuid();
    uuid = strcat(uuid, res);
    char uuid_info[strlen(uuid) + strlen(res) + 6];
    char info[255];

    mkdir(uuid, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    snprintf(uuid_info, sizeof(uuid_info), "%s/%s.txt", uuid, res);
    FILE *file = fopen(uuid_info, "w+");
    snprintf(info, sizeof(info), "Name=%s\nDescription=%s\n", \
    name, description);
    fprintf(file, info);
    free(uuid);
    return res;
}

char *create_comment(char *position, char *comment_body)
{
    char *comment_uuid = strdup(position);
    comment_uuid = strcat(comment_uuid, "/");
    char *res = generate_uuid();
    comment_uuid = strcat(comment_uuid, res);
    FILE *file = fopen(comment_uuid, "w+");

    fprintf(file, comment_body);
    free(comment_uuid);
    return res;
}
