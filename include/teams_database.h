/*
** EPITECH PROJECT, 2023
** B-NWP-400-BDX-4-1-myteams-guillaume.lebreton
** File description:
** teams_database
*/

#ifndef TEAMS_DATABASE_H
    #define TEAMS_DATABASE_H

    #include <uuid/uuid.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <dirent.h>
    #include "../libs/myteams/logging_server.h"

char *read_file_content(const char *file_path);
char *get_user_info(const char *user_uuid);
char *generate_uuid(void);
char *create_tct(char *position, const char *name, const char *description);
char *create_comment(char *position, char *comment_body);
void create_user(const char *user_name);
void user_details(const char *user_uuid);
void subscribe_team(const char *user_uuid, const char *team_uuid);
void list_users_subscribed_to_team(const char *team_uuid);
void unsubscribe_team(const char *user_uuid, const char *team_uuid);
void remove_newline(char *str);
void process_lines(FILE *file, FILE *temp, const char *team_uuid);
void replace_original_file(const char *user_file, const char *temp_file);
void write_modified_line(FILE *temp, const char *team_uuid, char *line, \
int *first_team);
void init_file_paths(char *user_file, char *temp_file, const char *user_uuid);
void append_team(char *new_subscribed, const char *team, int *first_team);
void unsubscribe_team(const char *user_uuid, const char *team_uuid);
void remove_newline(char *str);



#endif /* !TEAMS_DATABASE_H_ */
