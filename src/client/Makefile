##
## EPITECH PROJECT, 2023
## teams
## File description:
## Makefile
##

CC	=	gcc

SRC_MAIN	=	main.c

OBJ_MAIN	=	$(SRC_MAIN:.c=.o)

SRC	=	launch_client.c		\
		launch_cmd.c		\
		command_a.c			\
		command_b.c			\
		command_c.c			\
		command_d.c			\
		command_e.c			\
		command_error.c		\
		../server/pos.c 		\
		../server/free.c 		\
		error_handling.c

OBJ	=	$(SRC:.c=.o)

TESTS =		tests/test_basic.c

OBJ_TESTS	=	$(TESTS:.c=.o)

CFLAGS	+=	-Werror -Wextra -Wall -W -Wpedantic
CPPFLAGS	+=	-I./include
LDFLAGS	+=	-L../../libs/myteams -lmyteams -luuid

NAME	=	myteams_cli

EXE_TESTS	=	unit_tests

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJ_MAIN)
	$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS) $(CFLAGS) $(CPPFLAGS)

debug:	fclean
debug:	CFLAGS += -ggdb3
debug:	all

unit_tests: LDLIBS += -lcriterion
unit_tests: CFLAGS += --coverage

gcovr:
	gcovr --exclude tests
	gcovr --exclude tests --branches

unit_tests: $(OBJ) $(OBJ_TESTS)
	$(CC) -o $(EXE_TESTS) $(OBJ_TESTS) $(OBJ) $(CFLAGS) $(LDLIBS) $(CPPFLAGS)

tests_run: unit_tests
	./$(EXE_TESTS) --verbose

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)
	rm -f *.o
	find -name *.o -delete
	rm -f *.gc*
	find -name *.gc* -delete
	find -name *# -delete

fclean:	clean
	rm -f $(NAME)
	rm -f $(EXE_TESTS)
	rm -f $(OBJ_TESTS)
	find -name *.log -delete

re: fclean all

.PHONY: all clean fclean re tests_run unit_tests debug gcovr
