# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldifino <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:12:19 by ldifino           #+#    #+#              #
#    Updated: 2023/04/06 15:42:23 by ldifino          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SCR = ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c ./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c ./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c ./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_striteri.c ./ft_strmapi.c ./ft_substr.c ./ft_strjoin.c ./ft_strtrim.c ./ft_itoa.c ./ft_split.c ./ft_printf.c ./ft_putchar.c ./ft_putstr.c ./ft_hexa.c ./ft_putnbr.c ./ft_uns_putnbr.c ./ft_void_hexa.c
SCRB = ./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c 
FLAGS = -Wall -Wextra -Werror
OBJ = $(SCR:%.c=%.o)
OBJB = $(SCRB:%.c=%.o)

all: $(NAME)
$(NAME):
		gcc -c $(FLAGS) $(SCR)
		ar rcs $(NAME) $(OBJ)
bonus :	$(OBJB)
		gcc -c $(FLAGS) $(SCRB)
		ar rcs $(NAME) $(OBJB)

clean:
		rm -f $(OBJ) $(OBJB)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

