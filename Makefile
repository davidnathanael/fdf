# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amanukya <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/16 09:52:27 by amanukya          #+#    #+#              #
#    Updated: 2016/01/29 15:37:02 by ddela-cr         ###   ########.fr        #
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

SRCBASE		= 	main.c\
				ft_change_z.c												\
				ft_draw.c													\
				ft_get_data.c												\
				ft_get_vect.c												\
				ft_image_pixel_put.c										\
				ft_move.c													\
				ft_pixel_by_pixel.c											\
				ft_rotate.c													\
				ft_zoom.c													\

INCBASE		=	fdf.h\
				get_next_line.h												\
				libft.h

SRCS		=	$(addprefix $(SRCDIR), $(SRCBASE))

INCS		=	$(addprefix $(INCDIR), $(INCBASE))

OBJS		=	$(addprefix $(OBJDIR), $(SRCBASE:.c=.o))

all:	begin	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(FRAMEWORK)


begin:
	@mkdir -p $(OBJDIR)
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)

$(OBJDIR)%.o:	$(SRCDIR)%.c $(INCS)
	$(CC) $(FLAGS) -c $< -o $@ -I $(LIBFT_DIR)/$(INCDIR) -I $(MLX_DIR) -I $(INCDIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJDIR)

fclean:		clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)

re:			fclean all


.PHONY:	begin fclean clean re
