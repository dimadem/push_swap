# Colors

DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED			=	\033[0;91m
GREEN		=	\033[0;92m
YELLOW		=	\033[0;93m
BLUE		=	\033[0;94m
MAGENTA		=	\033[0;95m
CYAN		=	\033[0;96m
WHITE		=	\033[0;97m

NAME = push_swap

COMPILER			=	cc
FLAGS				=	-Wall -Wextra -Werror -g
AR					=	ar rcs

# external
EXTERNAL_DIR		=	./external
FT_PRINTF			=	$(EXTERNAL_DIR)/ft_printf/ft_printf.a
INCLUDES			=	-I$(EXTERNAL_DIR)/ft_printf/src

# src
SRC_DIR				=	./src
SOURCES				=	$(wildcard $(SRC_DIR)/*.c)

# build
BUILD_DIR 			=	./build
OBJS 				= 	$(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES:%.c=%.o)))
OBJS_BONUS			=	$(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_BONUS:%.c=%.o)))



all: 					$(NAME)

$(NAME):	$(FT_PRINTF) $(OBJS)
	@echo "$(WHITE)Building push_swap$(DEF_COLOR)"
	@$(COMPILER) $(FLAGS) $(INCLUDES) $(OBJS) -o $(NAME) $(FT_PRINTF)
	@file $(NAME)
	@echo "$(GREEN)push_swap ready$(DEF_COLOR)"

$(OBJS):	$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_BONUS):	$(BUILD_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

$(FT_PRINTF):
	@cd $(EXTERNAL_DIR)/ft_printf && make

clean:
	@echo "$(RED)Cleaning process"
	@cd $(EXTERNAL_DIR)/ft_printf && make clean
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN)Cleaning process done$(DEF_COLOR)"

fclean:		clean
	@echo "$(RED)Full cleaning process"
	@cd $(EXTERNAL_DIR)/ft_printf && make fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Full cleaning process done$(DEF_COLOR)"

re:		fclean all
	@echo "$(CYAN)cleaned and rebuilt everything for push_swap!$(DEF_COLOR)"


.PHONY:		all clean fclean re
