# ------------------------------ Sources ------------------------------

# Files
SRC			=	src/get_next_line.c src/get_next_line_utils.c \
				src/main.c src/draw.c \
				src/draw2.c src/game_physics_functions.c \
				src/game_physics_functions_2.c src/get_functions.c \
				src/graphic_management.c src/ini_functions.c \
				src/io.c src/map_checker_utils.c src/map_checker_utils_2.c \
				src/map_checker.c src/map_reading.c \

OBJS		=	$(SRC:.c=.o)

LIBFT		=	cd libft && make

FT_PRINTF	=  	cd ft_printf && make

LIB			=	libft/libft.a

PRINTF		=	ft_printf/libftprintf.a

# ------------------------------ Constant strings ------------------------------

GCC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -g3 -fsanitize=address

LBX			=	-lmlx -framework OpenGL -framework AppKit -lz 

INCLUDE		=	-I include

NAME		=	so_long

# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m

BOLD_CYAN	=	\033[1;36m

BOLD_YELLOW	=	\033[1;33m

BOLD_GREEN	=	\033[1;32m

NO_COLOR	=	\033[0m

# ------------------------------ Messages ------------------------------

COMP_START	=	echo "\n🚧 $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

READY	=	echo "\n📟 $(BOLD_GREEN)$(NAME) is ready!\n"

CLEANED		=	echo "\n💧 $(BOLD_YELLOW)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n🧼 $(BOLD_YELLOW)Fclean: $(NO_COLOR)Removed the executables \n"

# ------------------------------ Rules ------------------------------

.c.o:
	@$(GCC) $(FLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(COMP_START)
	@$(LIBFT)
	@$(FT_PRINTF)
	@$(GCC) $(FLAGS) $(LBX) $(OBJS) $(LIB) $(PRINTF) -o $(NAME)
	@$(READY)

clean:
	@rm -rf $(OBJS)
	@cd libft && make clean
	@cd ft_printf && make clean
	@$(CLEANED)

fclean: clean
	@rm -rf $(NAME)
	@cd libft && make fclean
	@cd ft_printf && make fclean
	@$(FCLEANED)

re:	fclean all

.PHONY: all so_long mandatory bonus clean fclean re libft