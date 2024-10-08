
# **************************************************************************** #
# 								  COMMANDS									   #
# **************************************************************************** #

NAME		= cub3D
CC			= @clang
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -Lminilibx-linux -lmlx -L/lib/x86_64-linux-gnu -lX11 -lXext -lXrandr -lXi -lm -Iminilibx-linux -o
HEAD		= includes/cub3D.h
MK			= @mkdir -p
RM			= @rm -rf
FILE		= $(shell ls -lR src/ | grep -F .c | wc -l)
CMP			= 1
CLEAR 		= @clear
BONUS 		= 0

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

# INITS
INT_DIR		:= inits
SRC_INT		:= init_data.c
INT			:= $(SRC_INT:%=$(INT_DIR)/%)

# MOVEMENT
MVT_DIR		:= movement
SRC_MVT		:= movement2.c movement.c keypresses.c
MVT			:= $(SRC_MVT:%=$(MVT_DIR)/%)		

# PARSING
PRS_DIR		:= parsing
SRC_PRS		:= parse_file.c parse_rgb.c parse_map.c parse_textures.c
PRS			:= $(SRC_PRS:%=$(PRS_DIR)/%)

# RAYCASTING
RC_DIR		:= raycasting
SRC_RC		:= raycasting.c rendering.c
RC			:= $(SRC_RC:%=$(RC_DIR)/%)	

# UTILS
UTL_DIR		:= utils
SRC_UTL		:= extension_utils.c frees.c init_utils.c list_utils.c parse_utils.c map_utils.c
UTL			:= $(SRC_UTL:%=$(UTL_DIR)/%)

# BONUS
BUS_DIR     := ../bonus
SRC_BUS     := minimap.c
BUS         := $(SRC_BUS:%=$(BUS_DIR)/%)

# ALL SOURCES
SRCS_DIR	:= src
ALL_SRCS	:= $(CUBE) $(INT) $(MVT) $(PRS) $(RC) $(UTL) $(BUS)
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

all: $(LIBFT) $(NAME)

$(OBJS_DIR)/%.o: %.c $(HEAD)
	$(MK) $(@D)
	@printf "\r$(FAINT)$(SPINK)Compiling $(RESET)$(GREEN)$<$(BLUE) [$(SPINK)$(CMP)$(BLUE)/$(SPINK)$(FILE)$(BLUE)]$(RESET)                       \r"
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) -c $< -o $@
	@$(eval CMP=$(shell echo $$(($(CMP)+1))))

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -DBONUS=$(BONUS) $(OBJS) -o $@ $(LIBFT) $(LFLAGS) $(NAME) $(MLX)
	@printf "\r"
	$(CMPLT)

$(MLX): minilibx-linux
	@printf "$(LBLUE)$(FADE)CLONING AND COMPILING MLX\n$(RESET)\n"
	@cd minilibx-linux && make
	@printf "\r\n\r\n\r$(INDI)$(BOLD)                           M L X  C O M P I L E D . . .$(RESET)                               \n\r"

	
minilibx-linux:
	@git clone https://github.com/42Paris/minilibx-linux.git $@

bonus:
	make all BONUS=1

clean:
	@rm -f $(LIBFT)
	@printf "\r\n\r$(BOLD)$(GREEN)ALL CLEAN!     \n\n$(RESET)"
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -rf $(NAME)
	@printf "\b\b$(FADE)$(RED)(MLX REMOVED!)$(PEACH)\n\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
