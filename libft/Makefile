# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanukya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 10:01:03 by amanukya          #+#    #+#              #
#    Updated: 2016/01/04 13:53:51 by amanukya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC       = clang
NAME     = libft.a
CFLAGS   = -Wextra -Wall -Werror -g
INC      = -I ./includes/

LISTDIR  = sources
SRCDIR   = sources
OBJDIR   = obj
INCDIR   = includes

FILES    = $(SRCDIR)/ft_isalpha.c \
		   $(SRCDIR)/ft_isdigit.c \
		   $(SRCDIR)/ft_isalnum.c \
		   $(SRCDIR)/ft_isascii.c \
		   $(SRCDIR)/ft_isprint.c \
		   $(SRCDIR)/ft_toupper.c \
		   $(SRCDIR)/ft_tolower.c \
		   $(SRCDIR)/ft_memset.c \
		   $(SRCDIR)/ft_bzero.c \
		   $(SRCDIR)/ft_memcpy.c \
		   $(SRCDIR)/ft_memccpy.c \
		   $(SRCDIR)/ft_memmove.c \
		   $(SRCDIR)/ft_memchr.c \
		   $(SRCDIR)/ft_memcmp.c \
		   $(SRCDIR)/ft_memalloc.c \
		   $(SRCDIR)/ft_memdel.c \
		   $(SRCDIR)/ft_strlen.c \
		   $(SRCDIR)/ft_strdup.c \
		   $(SRCDIR)/ft_strcpy.c \
		   $(SRCDIR)/ft_strncpy.c \
		   $(SRCDIR)/ft_strcat.c \
		   $(SRCDIR)/ft_strncat.c \
		   $(SRCDIR)/ft_strlcat.c \
		   $(SRCDIR)/ft_strchr.c \
		   $(SRCDIR)/ft_strrchr.c \
		   $(SRCDIR)/ft_strstr.c \
		   $(SRCDIR)/ft_strnstr.c \
		   $(SRCDIR)/ft_strcmp.c \
		   $(SRCDIR)/ft_strncmp.c \
		   $(SRCDIR)/ft_atoi.c \
		   $(SRCDIR)/ft_strnew.c \
		   $(SRCDIR)/ft_strdel.c \
		   $(SRCDIR)/ft_strclr.c \
		   $(SRCDIR)/ft_striter.c \
		   $(SRCDIR)/ft_striteri.c \
		   $(SRCDIR)/ft_strmap.c \
		   $(SRCDIR)/ft_strmapi.c \
		   $(SRCDIR)/ft_strequ.c \
		   $(SRCDIR)/ft_strnequ.c \
		   $(SRCDIR)/ft_strsub.c \
		   $(SRCDIR)/ft_strtrim.c \
		   $(SRCDIR)/ft_strsplit.c \
		   $(SRCDIR)/ft_itoa.c \
		   $(SRCDIR)/ft_strjoin.c \
		   $(SRCDIR)/ft_putchar.c \
		   $(SRCDIR)/ft_putstr.c \
		   $(SRCDIR)/ft_putendl.c \
		   $(SRCDIR)/ft_putnbr.c \
		   $(SRCDIR)/ft_putchar.c \
		   $(SRCDIR)/ft_putstr_fd.c \
		   $(SRCDIR)/ft_putchar_fd.c \
		   $(SRCDIR)/ft_putendl_fd.c \
		   $(SRCDIR)/ft_putnbr_fd.c \
		   $(SRCDIR)/ft_lstnew.c \
		   $(SRCDIR)/ft_lstdelone.c \
		   $(SRCDIR)/ft_lstdel.c \
		   $(SRCDIR)/ft_lstadd.c \
		   $(SRCDIR)/ft_lstiter.c \
		   $(SRCDIR)/ft_lstmap.c \
		   $(SRCDIR)/ft_tablen.c \
		   $(SRCDIR)/ft_delete_tab.c \
		   $(SRCDIR)/get_next_line.c

OBJ     = $(addprefix $(OBJDIR)/, $(FILES:.c=.o))

.SILENT:

$(addprefix $(OBJDIR)/, %.o) : %.c $(INCDIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INC)


$(NAME) : $(OBJDIR) $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	/bin/rm	-fr $(OBJDIR)

fclean : clean
	/bin/rm -fr $(NAME)

re : fclean all

all : $(NAME)

$(OBJDIR) :
	/bin/mkdir $(OBJDIR); \
		for DIR in $(LISTDIR); \
		do \
		/bin/mkdir $(OBJDIR)/$$DIR; \
		done

.PHONY:	clean fclean re debug
