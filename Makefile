CC     = cc
HDR    = inc/common.h inc/defines.h inc/libft.h
CFLAGS = -Wall -Wextra -Werror -Iinc -c
AR     = ar rusc
RM     = rm -rf 
NAME   = libftprintf.a
OBJD   = OBJ
LIBFTP = libft
LIBFT  = $(LIBFTP)/libft.a
SRCS   = src/ft_printf.c src/init_specifier.c src/print_arg.c	\
		 src/utils.c src/c_specifier.c src/di_specifier.c		\
		 src/p_specifier.c src/u_specifier.c src/s_specifier.c 	\
		 src/x_specifier.c src/padding.c src/xp_out_hex.c		\
		 src/no_specifier.c src/percent_specifier.c				\
		 src/utils2.c
OBJ    = $(patsubst src/%.c,$(OBJD)/%.o,$(SRCS))

$(OBJD)/%.o : src/%.c $(HDR)
	$(CC) $(CFLAGS) $<  -o $@

all : $(NAME)

bonus : all

$(NAME) : $(LIBFT) $(OBJD) $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(LIBFT) :
	make -C $(LIBFTP) all
	cp $(LIBFT) $(NAME)

$(OBJD) :
	mkdir -p $(OBJD)


clean :
	make -C $(LIBFTP) clean
	$(RM) $(OBJD)

fclean : clean
	make -C $(LIBFTP) fclean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
