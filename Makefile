CC = cc
CFLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = 	push_swap.c \
		error_msg.c \
		utils.c \
		more_utils.c \
		malloc_func.c \
		sorting_func.c \
		s_operations.c \
		p_operations.c \
		r_operations.c \
		rr_operations.c \
		k_sort.c

NAME = push_swap

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "Executable push_swap created."

all: $(NAME)


$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) 
	$(MAKE) -C $(LIBFT_DIR) clean
	@echo "Object files from push_swap removed."


fclean:
	@rm -f $(OBJS)
	@rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "All generated push_swap files removed."

re: fclean all

.PHONY: all clean fclean re
