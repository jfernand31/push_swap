# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/13 19:06:00 by jfernand          #+#    #+#              #
#    Updated: 2025/06/13 19:06:00 by jfernand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                               Configuration                                 #
################################################################################

# Output binary
NAME     := push_swap

# Compiler
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g

# Directories
INC_DIR := includes
SRC_DIR := src
OBJ_DIR := obj

# Libft
LIBFT_DIR := libft
LIBFT_LIB := $(LIBFT_DIR)/libft.a

# Source files
SRC := \
	$(SRC_DIR)/func_push.c        \
	$(SRC_DIR)/func_rotate.c      \
	$(SRC_DIR)/func_rv_rotate.c   \
	$(SRC_DIR)/func_swap.c        \
	$(SRC_DIR)/main.c             \
	$(SRC_DIR)/parsing.c          \
	$(SRC_DIR)/push_swap.c        \
	$(SRC_DIR)/sort_big.c         \
	$(SRC_DIR)/sort_five_or_less.c\
	$(SRC_DIR)/sort_three.c       \
	$(SRC_DIR)/utils_list.c       \
	$(SRC_DIR)/utils_parsing.c    \
	$(SRC_DIR)/utils_more_list.c  \
	$(SRC_DIR)/utils_op_list.c    \
	$(SRC_DIR)/optimize_op.c      \
	$(SRC_DIR)/utils_sort_big.c

TOTAL := $(words $(SRC))


# Object files
OBJ      = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEP      = $(OBJ:.o=.d)
RM       = rm -rf

# Detect platform
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
    PLATFORM := linux
    CFLAGS += -DLINUX
else ifeq ($(UNAME_S),Darwin)
    PLATFORM := macos
    CFLAGS += -DMACOS
else ifneq (,$(findstring MINGW,$(UNAME_S)))
    PLATFORM := windows
    CFLAGS += -DWINDOWS
else
    PLATFORM := unknown
endif

################################################################################
#                                Compilation                                   #
################################################################################

# Default target
all: check deps $(NAME)
	@echo "Building for platform: $(PLATFORM)"

# Compile the program
$(NAME): $(LIBFT_LIB) $(OBJ)
	@echo "Linking $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJ) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -lft -I$(INC_DIR) -o $(NAME)
	@echo ""  # new line after progress bar

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@i=$(shell echo $(SRC) | tr ' ' '\n' | grep -n "^$<$$" | cut -d: -f1); \
	bar_width=10; \
	progress=$$((i * bar_width / $(TOTAL))); \
	dots=$$(printf "%*s" $$progress | tr ' ' '#'); \
	spaces=$$(printf "%*s" $$((bar_width - progress))); \
	printf "\r[%s%s]  %d/%d Compiling %s\n" "$$dots" "$$spaces" $$i $(TOTAL) $<;
	@$(CC) -MMD -MP $(CFLAGS) -I$(INC_DIR) -c $< -o $@ > /dev/null

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

# Submodule initialization
deps:
	@git submodule update --init --recursive

# Pull latest commits inside submodules
pull:
	@echo "Pulling latest submodule commits..."
	@git submodule foreach git pull origin main

# Update submodules to latest remote commits (tracked branch)
update:
	@echo "Updating submodules to latest remote commit..."
	@git submodule update --remote --merge

# Restore submodules to their committed state
restore:
	@read -p "⚠️ This will discard ALL submodule changes! Continue? (y/N) " ans; \
	if [ "$$ans" = "y" ] || [ "$$ans" = "Y" ]; then \
		echo "Restoring submodules..."; \
		git submodule foreach --recursive git reset --hard; \
		git submodule update --init --recursive; \
	else \
		echo "Restore canceled."; \
	fi

check:
	@echo "Checking for uncommitted changes in submodules..."
	@dirty=0; \
	git submodule foreach --quiet ' \
		status=$$(git status --porcelain); \
		if [ -n "$$status" ]; then \
			echo "Submodule $$path has uncommitted changes:"; \
			echo "$$status"; \
			exit 1; \
		fi' || dirty=1; \
	if [ $$dirty -eq 1 ]; then \
		echo "Please commit or stash submodule changes before building."; \
		exit 1; \
	else \
		echo "All submodules clean."; \
	fi

################################################################################
#                                 Clean Up                                     #
################################################################################

clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

################################################################################
#                                   Phony Targets                              #
################################################################################

.PHONY: all clean fclean re deps pull update restore check

-include $(DEP)