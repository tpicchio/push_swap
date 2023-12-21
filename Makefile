NAME        	:= push_swap
BONUS			:= checker

FLAGS			:= -Wall -Wextra -Werror
CC          	:= cc
RM				:= rm -f

LIBFT_PATH		:= ./libft
LIBFT			:= $(LIBFT_PATH)/libft.a

SRCS_DIR		:= src
SRCS	        := \
					ft_push_swap.c \
					ft_check_token.c \
					ft_error.c \
					ft_last_rotate.c \
					ft_lis.c \
					main.c \
					ft_moves_p.c \
					ft_moves_r.c \
					ft_moves_s.c \
					ft_obm_score_utils.c \
					ft_obm_score.c \
					ft_push_best.c \
					ft_set_index.c \
					ft_set_list.c \
					ft_set_obm_dist_utils.c \
					ft_set_obm_dist.c \
					ft_set_swap.c \
					ft_split_input_into_token.c
SRCS        	:= $(SRCS:%=$(SRCS_DIR)/%)

CHECKER			:= \
					src/ft_error.c \
					src/ft_split_input_into_token.c \
					src/ft_check_token.c \
					src/ft_set_list.c \
					src/ft_moves_p.c \
					src/ft_moves_r.c \
					src/ft_moves_s.c \
					src/bonus/ft_parse_moves.c \
					src/bonus/ft_stacks_are_cool.c \
					src/bonus/ft_checker.c \

$(NAME):		$(LIBFT)
				$(CC) $(FLAGS) -Iinclude $(SRCS) $(LIBFT) -o $(NAME)
				${info }
				${info ${BOLD}Creating  -> ${RED}$(NAME)${NO_COLOR}}

$(LIBFT):
				make -C $(LIBFT_PATH) all

all:			$(NAME)

re:				fclean all

clean:
				make -C $(LIBFT_PATH) clean
				${info }
				${info ${BOLD}${YELLOW}Cleaning in progress...${NO_COLOR}}
				${info }

fclean:			clean
				make -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)
				$(RM) $(BONUS)
				${info ${BOLD}${YELLOW}Removing  -> ${RED}$(NAME)${NO_COLOR}}
				${info ${BOLD}${YELLOW}Removing  -> ${BLUE}$(BONUS)${NO_COLOR}}
				${info }

bonus:			$(LIBFT) $(BONUS)

$(BONUS):		$(LIBFT) $(CHECKER)
				$(CC) $(FLAGS) -Iinclude $(CHECKER) $(LIBFT) -o $(BONUS)
				${info }
				${info ${BOLD}Creating  -> ${BLUE}checker${NO_COLOR}}
				${info }

.PHONY:			all clean fclean re libft bonus

.SILENT:

RED 			:= ${shell tput setaf 1}
YELLOW			:= ${shell tput setaf 3}
BLUE			:= ${shell tput setaf 4}
NO_COLOR		:= ${shell tput sgr0}
BOLD			:= ${shell tput bold}