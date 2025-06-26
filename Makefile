# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgalizio <jgalizio@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/20 14:34:08 by jgalizio          #+#    #+#              #
#    Updated: 2025/03/11 17:45:01 by jgalizio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
NAME_BONUS		= checker
RM				= rm -rf
CFLAGS			= -Wall -Werror -Wextra -I ./libft -g

BASE_DIR		= ./srcs_mandatory
BONUS_DIR		= ./srcs_bonus
LIBFT_DIR		= ./libft
BUILD_DIR		= ./.build
BUILD_BONUS_DIR	= $(BUILD_DIR)/bonus
BUILD_BASE_DIR	= $(BUILD_DIR)/mandatory

BASE_TARGET		= $(BUILD_BASE_DIR)/.mandatory
BONUS_TARGET	= $(BUILD_BONUS_DIR)/.bonus
LIBFT			= $(LIBFT_DIR)/libft.a
BASE_HEADERS	= $(BASE_DIR)/pswap.h
BONUS_HEADERS	= $(BONUS_DIR)/pswap_bonus.h
LIBFT_HEADERS	= $(LIBFT_DIR)/libft.h

BASE_SRCS		= $(addprefix $(BASE_DIR)/,\
					main.c \
					cleanup.c \
					misc_utils.c \
					op_manager.c \
					ops_push.c \
					ops_rev_rotate.c \
					ops_rotate.c \
					ops_swap.c \
					parse_and_init.c \
					sort_algo_init.c \
					sort_algo_phase_i.c \
					sort_algo_phase_ii.c \
					sort_algo_phase_iii.c \
					sort_algo_utils.c \
					sort_opti_i.c \
					sort_opti_ii.c \
					sort_utils.c \
					stack_utils.c \
					)

BONUS_SRCS		= $(addprefix $(BONUS_DIR)/,\
					cleanup_bonus.c \
					main_bonus.c \
					misc_utils_bonus.c \
					op_manager_bonus.c \
					ops_push_bonus.c \
					ops_rev_rotate_bonus.c \
					ops_rotate_bonus.c \
					ops_swap_bonus.c \
					parse_and_init_bonus.c \
					sort_algo_init_bonus.c \
					sort_algo_utils_bonus.c \
					sort_utils_bonus.c \
					stack_utils_bonus.c \
					)

BASE_OBJS		= $(BASE_SRCS:$(BASE_DIR)/%.c=$(BUILD_BASE_DIR)/%.o)
BONUS_OBJS		= $(BONUS_SRCS:$(BONUS_DIR)/%.c=$(BUILD_BONUS_DIR)/%.o)

all: $(NAME)

$(NAME): $(BASE_TARGET)

bonus: $(BONUS_TARGET)

$(BASE_TARGET): $(BASE_OBJS) $(LIBFT)
	@echo "Creating binary..."
	@$(CC) $(CFLAGS) $(BASE_OBJS) $(LIBFT) -o $(NAME)
	@touch $(BASE_TARGET)
	@rm -f $(BONUS_TARGET)
	@echo "Done! :D"

$(BONUS_TARGET): $(BONUS_OBJS) $(LIBFT)
	@echo "Creating bonus..."
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(NAME_BONUS)
	@touch $(BONUS_TARGET)
	@rm -f $(BASE_TARGET)
	@echo "Done! :D"

$(BUILD_BASE_DIR)/%.o: $(BASE_DIR)/%.c $(BASE_HEADERS) $(LIBFT)
	@echo "compiling $@..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_HEADERS) $(LIBFT)
	@echo "compiling $@..."
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT): $(LIBFT_HEADERS)
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory
	@echo "Done! :D"

clean:
	@echo "Cleaning objects..."
	@$(RM) $(BASE_OBJS) $(BONUS_OBJS) $(BASE_TARGET) $(BONUS_TARGET)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "Done! :D"

fclean: clean
	@echo "Cleaning all..."
	@$(RM) $(BUILD_DIR)
	@$(RM) $(NAME)
	@echo "Done! :D"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean bonus fclean re rebonus
