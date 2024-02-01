# Folders and Names
NAME		= zombie
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .

SRCS		= Zombie.cpp main.cpp

# Compiler options
CC			= c++
CFLAGS		= -g -Wall -Wextra -Werror -std=c++98

###################################################
# The rest is done by the MakeFile automatically, #
# you should not have to modify it				  #
###################################################

all: $(NAME)

$(NAME): $(SRCSDIR)/$(SRCS)
	@echo "Assembling $@"
	@$(CC) $(CFLAGS) -o $@ $^

clean:

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test