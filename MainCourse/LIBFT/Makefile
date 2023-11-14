NAME := libft.a
SRCS_DIR := ./
SRCS := ft_strlcpy.c ft_calloc.c ft_putnbr_fd.c ft_strdup.c ft_tolower.c ft_strlcat.c ft_isprint.c ft_isdigit.c ft_memchr.c ft_substr.c ft_putendl_fd.c ft_memcmp.c ft_strncmp.c ft_striteri.c ft_memset.c ft_putchar_fd.c ft_split.c ft_strnstr.c ft_bzero.c ft_atoi.c ft_isalpha.c ft_strjoin.c ft_memmove.c ft_isascii.c ft_strlen.c ft_strrchr.c ft_toupper.c ft_isalnum.c ft_strmapi.c ft_strtrim.c ft_itoa.c ft_strchr.c ft_memcpy.c ft_putstr_fd.c
# OBJS := ft_lstlast.o ft_lstiter.o ft_lstsize.o ft_lstadd_back.o ft_lstadd_front.o ft_lstclear.o ft_lstdelone.o ft_lstmap.o ft_lstnew.o ft_strlcpy.o ft_calloc.o ft_putnbr_fd.o ft_strdup.o ft_tolower.o ft_strlcat.o ft_isprint.o ft_isdigit.o ft_memchr.o ft_substr.o ft_putendl_fd.o ft_memcmp.o ft_strncmp.o ft_striteri.o ft_memset.o ft_putchar_fd.o ft_split.o ft_strnstr.o ft_bzero.o ft_atoi.o ft_isalpha.o ft_strjoin.o ft_memmove.o ft_isascii.o ft_strlen.o ft_strrchr.o ft_toupper.o ft_isalnum.o ft_strmapi.o ft_strtrim.o ft_itoa.o ft_strchr.o ft_memcpy.o ft_putstr_fd.o
B_SRCS := ft_lstlast.c ft_lstiter.c ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstmap.c ft_lstnew.c
FLAGS := -Wall -Werror -Wextra

OBJS = ${SRCS:.c=.o}
B_OBJS = ${B_SRCS:.c=.o}


all: $(NAME)

%.o : %.c
	gcc $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS) 
	ar crs libft.a $(OBJS) 

bonus : ${B_OBJS} 
	ar crs libft.a $(B_OBJS)

clean:
	rm -f $(OBJS) ${B_OBJS} 

fclean: clean
	rm -f $(NAME)

re: fclean all