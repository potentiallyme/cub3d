
# **************************************************************************** #
# 								  COMMANDS									   #
# **************************************************************************** #

NAME		= cub3D
CC			= @clang
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -Llibft -lft -lreadline
HEAD		= includes/cub3D.h
MK			= @mkdir -p
RM			= @rm -rf
FILE		= $(shell ls -lR src/ | grep -F .c | wc -l)
CMP			= 1
CLEAR 		= @clear

# **************************************************************************** #
# 								LIBFT & MLX									   #
# **************************************************************************** #

LIBFT_PATH	= ./libft --no-print-directory
LIBFT		= ./libft/libft.a

MLX = minilibx-linux/libmlx_Linux.a
MLX_A = ./minilibx-linux/libmlx.a
MLX_PATH = minilibx-linux

# **************************************************************************** #
# 								  SOURCES 									   #
# **************************************************************************** #

# CUB3D
CUBE		:= cube.c

# ALL SOURCES
SRCS_DIR	:= src
ALL_SRCS	:= $(CUBE)
SRCS		:= $(ALL_SRCS:%=$(SRCS_DIR)/%)

# OBJECTS
OBJS_DIR	:=	.objs
OBJS		:=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

# **************************************************************************** #
# 								   COLORS									   #
# **************************************************************************** #

BOLD	= 	\e[1m
FAINT	=	\e[2m
ITA		=	\e[3m
BLINK	=	\e[5m
GREEN	=	\e[38;5;76m
RED		=	\e[38;5;196m
YELLOW	=	\e[38;5;227m
ORANGE	=	\e[38;5;208m
PURPLE	=	\e[38;5;201m
LBLUE	=	\e[38;5;45m
BLUE	=	\e[38;5;27m
INDI	=	\e[38;5;91m
SPINK	=	\e[38;5;225m
GREY	=	\e[38;5;254m
RESET	=	\e[00m

CMPLT	= @printf "\r                                \r\n$(BOLD)$(INDI)\r                   ░░ \n          $(INDI)       ▓█░░▒▒▒▒ \n   $(INDI)        ░░▒▒░░░░░░░░░░░░▒▒ \n     $(INDI)  ▒▒▒▒░░░░░░░░░░░░░░░░░░██▒▒ \n  $(INDI) ░░▓▓░░░░░░░░░░░░░░░░░░░░░░░░░░██░░ \n \
$(INDI)██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░▒▒$(SPINK)   ░▒▓▓▓▓▓▓▓▓▓▓▓▒░   ░▒▓▓▓▓▓▓▓▓▒░ \n \
$(INDI)▒▒░░  ░░░░░░░░░░░░░░░░░░░░░░░░░░  ░░▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░░░░▒▓▓▒░\n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░░░░░░░░░  ░░▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░   ░░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░  ░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░  ▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)   ░▒▓▓▓▓▓▓▓▓▓▓▓▒░   ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░    ░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░   ░░▒▓▓▒░ \n \
$(INDI)▒▒░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)             ░▒▓▓▒░  ░▒▓▓▒░░░░░▒▓▓▒░\n \
$(INDI)▓▓░░░░░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒$(SPINK)   ░▒▓▓▓▓▓▓▓▓▓▓▓▒░   ░▒▓▓▓▓▓▓▓▓▒░\n  $(INDI) ▒▒▒▒░░░░░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ \n  $(INDI)     ▓▓▒▒░░░░░░░░░░▒▒▒▒▒▒▒▒▒▒▓▓ \n     $(INDI)      ▒▒▒▒░░░░░░▒▒▒▒▒▒▓▓\n    $(INDI)           ░░▓▓░░▒▒▒▒ \n        $(INDI)           ▒▒ \n $(RESET)\n" 
                            
                            


# **************************************************************************** #
# 								     RULES									   #
# **************************************************************************** #

all: $(MLX) $(LIBFT) $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEAD)
	$(MK) $(@D)
	@printf "\r$(FAINT)$(SPINK)Compiling $(RESET)$(GREEN)$<$(BLUE) [$(SPINK)$(CMP)$(BLUE)/$(SPINK)$(FILE)$(BLUE)]$(RESET)                       \r"
	$(CC) $(CFLAGS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT) $(LFLAGS) -o $(NAME)
	@printf "\r"
	$(CMPLT)

$(MLX): minilibx-linux
	@printf "$(LBLUE)$(FADE)CLONING AND COMPILING MLX\n$(RESET)\n"
	@cd minilibx-linux && make
	@printf "\r\n\r\n\r$(INDI)$(BOLD)                           M L X  C O M P I L E D . . .$(RESET)                               \n\r"

	
minilibx-linux:
	@git clone https://github.com/42Paris/minilibx-linux.git $@

clean:
	@rm -f $(LIBFT)
	@printf "\r\n\r$(BOLD)$(GREEN)ALL CLEAN!     \n\n$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME) $(MLX) $(MLX_A)
	@printf "\b\b$(FADE)$(RED)(MLX REMOVED!)$(PEACH)\n\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
