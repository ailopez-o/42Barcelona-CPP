# Folders and Names
NAME		= Bureaucrat.out
SRCSDIR		= .
OBJSDIR		= objs
INCLUDES	= .

SRCS		= main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

# Compiler options
CC			= g++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

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