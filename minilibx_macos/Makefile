#
#

NOM=libmlx.a
NAMEBASE = libmlx
SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2

.SILENT:

all: $(NOM)
	echo "\033[38;5;44m☑️  ALL    $(NAMEBASE) is done\033[0m\033[K"

$(NOM):	$(OBJ)
	printf "\r\033[38;5;11m⌛  MAKE   $(NAMEBASE) please wait ...\033[0m\033[K"
	@ar -r $(NOM) $(OBJ)
	@ranlib $(NOM)

clean:
	printf "\r\033[38;5;11m⌛  CLEAN  $(NAMEBASE) please wait ...\033[0m\033[K"
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app
	if [[ `rm -R $(OBJDIR) &> /dev/null 2>&1; echo $$?` == "0" ]]; then		\
		echo -en "\r\033[38;5;124m🔘  CLEAN  $(NAMEBASE)\033[0m\033[K";		\
	else																	\
		printf "\r";														\
	fi

re: clean all
