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
NAME_BONUS = checker
NAME_PUSH_SWAP_LIB = libpush_swap.a

COMPILER			=	cc
FLAGS				=	-Wall -Wextra -Werror -g
AR					=	ar rcs

# external
EXTERNAL_DIR		=	./external
FT_PRINTF			=	$(EXTERNAL_DIR)/ft_printf/ft_printf.a
INCLUDES			=	-I$(EXTERNAL_DIR)/ft_printf/src

# src
SRC_DIR				=	./src
SRC_BONUS_DIR		=	./src_bonus
SRC_MAIN			=	$(SRC_DIR)/push_swap.c
SOURCES_COMMON 		=	$(wildcard $(SRC_DIR)/common/*.c)
SOURCES_BONUS		=	$(wildcard $(SRC_BONUS_DIR)/*.c)


# build
BUILD_DIR 			=	./build
OBJ_MAIN			=	$(SRC_MAIN:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJS_COMMON			= 	$(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_COMMON:%.c=%.o)))
OBJS_BONUS			=	$(addprefix $(BUILD_DIR)/, $(notdir $(SOURCES_BONUS:%.c=%.o)))

# lib
PUSH_SWAP_LIB		=	$(BUILD_DIR)/lib_push_swap.a

all: 					$(NAME)

$(NAME):				$(PUSH_SWAP_LIB) $(FT_PRINTF) $(OBJ_MAIN)
	@$(COMPILER) $(FLAGS) $(INCLUDES) $(OBJ_MAIN) $(PUSH_SWAP_LIB) $(FT_PRINTF) -o $(NAME)
	@echo "$(GREEN)push_swap compiled$(DEF_COLOR)"

$(NAME_BONUS):			$(PUSH_SWAP_LIB) $(FT_PRINTF) $(OBJS_BONUS)
	@$(COMPILER) $(FLAGS) $(INCLUDES) $(OBJS_BONUS) $(PUSH_SWAP_LIB) $(FT_PRINTF) -o $(NAME_BONUS)
	@echo "$(GREEN)checker compiled$(DEF_COLOR)"

$(PUSH_SWAP_LIB):		$(OBJS_COMMON)
	@$(AR) $(PUSH_SWAP_LIB) $(OBJS_COMMON)
	@echo "$(GREEN)push_swap lib compiled$(DEF_COLOR)"

$(FT_PRINTF):
	@cd $(EXTERNAL_DIR)/ft_printf && make
	@echo "$(GREEN)ft_printf compiled$(DEF_COLOR)"

$(BUILD_DIR)/%.o:		$(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o:		$(SRC_DIR)/common/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o:		$(SRC_BONUS_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(COMPILER) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus:					$(NAME_BONUS)

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
