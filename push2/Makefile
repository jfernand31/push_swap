# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/02 19:45:19 by jfernand          #+#    #+#              #
#    Updated: 2025/06/03 20:03:44 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the project
NAME= push_swap

# Object files
CFILES= \
	srcs/func_push.c        \
	srcs/func_rotate.c      \
	srcs/func_rv_rotate.c   \
	srcs/func_swap.c        \
	srcs/main.c             \
	srcs/parsing.c          \
	srcs/push_swap.c        \
	srcs/sort_big.c         \
	srcs/sort_five_or_less.c\
	srcs/sort_three.c       \
	srcs/utils_list.c       \
	srcs/utils_parsing.c    \
	srcs/utils_more_list.c  \
	srcs/utils_op_list.c    \
	srcs/optimize_op.c      \
	srcs/utils_sort_big.c

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




