# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 11:38:53 by tmckinno          #+#    #+#              #
#    Updated: 2017/08/13 14:19:06 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

ECHO	= @echo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
SRCDIR	= srcs
OBJDIR	= build
INCLUDE	= -I includes
SRC		= clct_log.c \
			clct_mem.c \
			clct_ref.c \
			clct_region.c \
			clct_hash.c \
			clct_manip.c \
			clct_create.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_ctrim.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isws.c \
			ft_itoa.c \
			ft_lstadd.c \
			ft_lstapp.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstlen.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstpop.c \
			ft_lstpush.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putnstr.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strlen_d.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnew_d.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			get_next_line.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJ		= $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	= all clean fclean re deps


all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ):  | build

build:
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
