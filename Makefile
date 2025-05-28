# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/05/27 17:36:38 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME= push_swap

# Object files
CFILES= ./push_swap.c \
		./parsing.c   \
		./push.c      \
		./swap.c      \
		./sort_three.c  \
		./sort_four.c   \
		./sort_five.c   \
		./sort_big.c    \
		./rotate.c      \
		./reverse_rotate.c  \
		./utils_sort_small.c  \
		./utils_sort_big.c    \
		./utils_list.c        \

# .h files
HFILES= ./includes/push_swap.h \

# Libft files
LIBFT= ./libft
LIBFT_A= $(LIBFT)/libft.a

# .c bonus files
#BFILES= 

# Object files
OFILES= $(CFILES:.c=.o)

# Bonus object files
#BOFILES= $(BFILES:.c=.o)

# Compiler
CC=@cc

# Flags for compiler
CCFLAGS=-Wall      \
        -Wextra    \
        -Werror    \
		-g         \
		-I.        \
		-I$(LIBFT) \

# Command used to clean target
RM = rm -rf

#
# Compilation and linking
#
all: $(NAME)

$(NAME): $(LIBFT_A) $(OFILES) 
	@ echo 'Building binary: $@'
	$(CC) $(CCFLAGS) $(OFILES) $(LIBFT_A) -o $@
	@ echo 'Finished building binary: $@'

$(OFILES): %.o:%.c
	@ echo 'Building target: $@'
	@ $(CC) $(CCFLAGS) -c $< -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

clean:
	@ $(RM) $(OFILES)
	@ $(MAKE) -C $(LIBFT) clean

fclean: clean
	@ $(RM) $(NAME)
	@ $(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY= all clean fclean re 




