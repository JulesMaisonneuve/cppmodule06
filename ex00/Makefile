NAME	= conversion
FILES	= main.cpp
OBJ		= $(FILES:%.cpp=%.o)
CC		= clang++
CFLAGS	= -Wall -Werror -Wextra -std=c++98
SHELL	= /bin/bash

RED		= "\033[0;31m"
GREEN	= "\033[0;32m"
YELLOW	= "\033[1;33m"
L_GRAY	= "\033[0;37m"
D_GRAY	= "\033[1;30m"
WHITE	= "\033[1;37m"

all: $(NAME)

$(NAME): $(OBJ)
	@echo -e $(L_GRAY)Building $@...; \
	$(CC) $(CFLAGS) $(OBJ) -o $@ && \
	echo -e $(GREEN)[OK]$(L_GRAY) || \
	echo -e $(RED)[FAIL]$(L_GRAY);

%.o: %.cpp
	@echo -e $(L_GRAY)Building $<...; \
	$(CC) $(CFLAGS) -c $< -o $@ && \
	echo -e $(GREEN)[OK]$(L_GRAY) || \
	echo -e $(RED)[FAIL]$(L_GRAY);

clean:
	@echo -ne $(YELLOW)
	rm -f $(OBJ)
	@echo -ne $(L_GRAY)

fclean: clean
	@echo -ne $(YELLOW)
	rm -f $(NAME)
	@echo -ne $(L_GRAY)

re: fclean all

.PHONY: all clean fclean re
