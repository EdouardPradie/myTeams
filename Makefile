##
## EPITECH PROJECT, 2023
## task01
## File description:
## D10
##

SRC_SERV_INIT	=	src/server/init_serv/main.c			\
				src/server/init_serv/parse_teams.c		\
				src/server/init_serv/init_serv_teams.c	\
				src/server/init_serv/error_handling.c

SRC_COMMAND	=	src/server/command/command.c		\
			src/server/command/simple_command.c	\
			src/server/command/command_creat.c	\
			src/server/command/command_user.c

SRC_SERV_CLI	=	src/server/serv_cli/client_teams.c		\
				src/server/serv_cli/creat_new_client.c	\
				src/server/serv_cli/init_client_teams.c

SRC_SERV_M	=	src/server/free.c		\
			src/server/data_user.c	\
			src/server/node.c		\
			src/server/pos.c		\
			src/server/get_text.c

SRC_DATABASE	=	database/database.c	\
					database/database_reader.c	\
					database/database_users.c	\
					database/database_teams.c	\
					database/who_is_subscribed.c \
					database/unsubscriber.c		\
					database/unsubscriber_bis.c		\
					database/create_user.c		\
					database/database_utils.c

SRC = $(SRC_SERV_M) $(SRC_SERV_CLI) $(SRC_SERV_INIT) $(SRC_COMMAND)\
 $(SRC_DATABASE)

OBJ     =       $(SRC:.c=.o)

NAME	=	./myteams_server

CFLAGS		+=	-Werror -Wextra -Wall -W -Wpedantic
LDFLAGS	+=	-L./libs/myteams -lmyteams -luuid
CPPFLAGS	+=	-I include/ -g

all:	$(NAME) client

client:
	make -C src/client/
	mv src/client/myteams_cli .

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)

dbg:		CFLAGS += -ggdb3
dbg:		$(OBJ)
		gcc -o $(NAME) $(SRC) $(CFLAGS) $(CPPFLAGS)

clean:
	make clean -C src/client/ -f Makefile -s
	rm -f $(OBJ)
	find -name *.o -delete

fclean: clean
	make fclean -C src/client/ -f Makefile -s
	rm -f $(NAME)
	rm -f myteams_cli

re:	fclean all

.PHONY: re fclean clean all
