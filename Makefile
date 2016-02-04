# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanukya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 09:52:27 by amanukya          #+#    #+#              #
#    Updated: 2016/02/04 08:44:08 by ddela-cr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

NAMEBASE    =   $(shell basename $(NAME))

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

SRCDIR		=	srcs/

OBJDIR		=	objs/

INCDIR		=	includes/

LIBFT_DIR	=	libft/

MLX_DIR		=	minilibx_macos/

MLX_LIB		=	minilibx_macos/libmlx.a

LIBFT_LIB	=	libft/libft.a

FRAMEWORK 	= 	-framework OpenGL -framework AppKit

SRCBASE		= 	\
				colors.c													\
				ft_change_z.c												\
				ft_draw.c													\
				ft_get_data.c												\
				ft_get_vect.c												\
				ft_move.c													\
				ft_pixel_by_pixel.c											\
				ft_rotate.c													\
				ft_zoom.c													\
				main.c

INCBASE		=	\
				fdf.h														\
				libft.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

.SILENT:

all:	begin	$(NAME)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(FRAMEWORK)
	echo -en "\r\033[38;5;22m☑️  MAKE   $(NAMEBASE)\033[0m\033[K"
	echo "\r\033[38;5;184m👥  GROUP MEMBER(S):\033[0m\033[K"
	echo "\r\033[38;5;15m`cat auteur | sed s/^/\ \ \ \ /g`\033[0m\033[K"


begin:
	@mkdir -p $(OBJDIR)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

$(OBJDIR)%.o:	$(SRCDIR)%.c $(INCS)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	$(CC) $(FLAGS) -c $< -o $@ -I $(LIBFT_DIR)/$(INCDIR) -I $(MLX_DIR) -I $(INCDIR)

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJDIR)
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

fclean:		clean
	printf "\r\033[38;5;11m⌛  FCLEAN $(NAMEBASE) please wait ...\033[0m\033[K"
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	if [[ `rm $(NAME) &> /dev/null 2>&1; echo $$?` == "0" ]]; then			\
		echo -en "\r\033[38;5;124m🔘  FCLEAN $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re:			fclean all


.PHONY:	begin fclean clean re
