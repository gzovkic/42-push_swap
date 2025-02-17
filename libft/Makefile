# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS_DIR = ./srcs
INC_DIR = ./includes
PRINTF_DIR = $(INC_DIR)/ft_printf
GET_NEXT_LINE_DIR = $(INC_DIR)/get_next_line

# Source Files
SRCS = 	$(SRCS_DIR)/ft_isalpha.c \
		$(SRCS_DIR)/ft_isdigit.c \
		$(SRCS_DIR)/ft_isalnum.c \
		$(SRCS_DIR)/ft_isascii.c \
		$(SRCS_DIR)/ft_isprint.c \
		$(SRCS_DIR)/ft_strlen.c \
		$(SRCS_DIR)/ft_memset.c \
		$(SRCS_DIR)/ft_bzero.c \
		$(SRCS_DIR)/ft_memcpy.c \
		$(SRCS_DIR)/ft_memmove.c \
		$(SRCS_DIR)/ft_strlcpy.c \
		$(SRCS_DIR)/ft_strlcat.c \
		$(SRCS_DIR)/ft_toupper.c \
		$(SRCS_DIR)/ft_tolower.c \
		$(SRCS_DIR)/ft_strchr.c \
		$(SRCS_DIR)/ft_strrchr.c \
		$(SRCS_DIR)/ft_strncmp.c \
		$(SRCS_DIR)/ft_memchr.c \
		$(SRCS_DIR)/ft_memcmp.c \
		$(SRCS_DIR)/ft_strnstr.c \
		$(SRCS_DIR)/ft_atoi.c \
		$(SRCS_DIR)/ft_calloc.c \
		$(SRCS_DIR)/ft_strdup.c \
		$(SRCS_DIR)/ft_substr.c \
		$(SRCS_DIR)/ft_strjoin.c \
		$(SRCS_DIR)/ft_strtrim.c \
		$(SRCS_DIR)/ft_split.c \
		$(SRCS_DIR)/ft_itoa.c \
		$(SRCS_DIR)/ft_strmapi.c \
		$(SRCS_DIR)/ft_striteri.c \
		$(SRCS_DIR)/ft_putchar_fd.c \
		$(SRCS_DIR)/ft_putstr_fd.c \
		$(SRCS_DIR)/ft_putendl_fd.c \
		$(SRCS_DIR)/ft_putnbr_fd.c \
		$(SRCS_DIR)/ft_lstnew_bonus.c \
		$(SRCS_DIR)/ft_lstsize_bonus.c \
		$(SRCS_DIR)/ft_lstlast_bonus.c \
		$(SRCS_DIR)/ft_lstdelone_bonus.c \
		$(SRCS_DIR)/ft_lstclear_bonus.c \
		$(SRCS_DIR)/ft_lstiter_bonus.c \
		$(SRCS_DIR)/ft_lstmap_bonus.c \
		$(SRCS_DIR)/ft_lstadd_back_bonus.c \
		$(SRCS_DIR)/ft_lstadd_front_bonus.c \
		$(PRINTF_DIR)/ft_printf.c \
		$(PRINTF_DIR)/ft_putnbr_rt.c \
		$(PRINTF_DIR)/ft_putptr_rt.c \
		$(PRINTF_DIR)/ft_puthex_rt_lowercase.c \
		$(PRINTF_DIR)/ft_puthex_rt_uppercase.c \
		$(PRINTF_DIR)/ft_putudc_rt.c \
		$(PRINTF_DIR)/ft_putchar_rt.c \
		$(PRINTF_DIR)/ft_putstr_rt.c \
		$(PRINTF_DIR)/ft_strlen_p.c \
		$(GET_NEXT_LINE_DIR)/get_next_line_bonus.c \
		$(GET_NEXT_LINE_DIR)/get_next_line_utils_bonus.c \
		$(GET_NEXT_LINE_DIR)/get_next_line.c \
		$(GET_NEXT_LINE_DIR)/get_next_line_utils.c

# Name of the library
NAME = libft.a

# Object Files
OBJS = $(SRCS:.c=.o)

# builds the library
all: $(NAME)

# rules to create the library
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Library $(NAME) created."

# turns .c files into .o files
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# clean objects files
clean:
	@rm -f $(OBJS)
	@if [ "$(MAKECMDGOALS)" != "fclean" ]; then echo "Object files from Libft removed."; fi

# clean object files and the library
fclean: clean
	@rm -f $(NAME)
	@echo "All generated Libft files removed."

# recompile everything
re: fclean all

.PHONY: all clean fclean re