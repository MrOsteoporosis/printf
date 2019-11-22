# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:19:16 by averheij       #+#    #+#                 #
#    Updated: 2019/11/22 11:03:14 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME        =   libftprintf.a
CFILES      =   ft_printf.c ft_conv_csp%n.c ft_conv_diu.c ft_conv_l_diu.c\
	ft_conv_ll_diu.c ft_conv_xx.c ft_conv_l_xx.c ft_conv_ll_xx.c ft_util_gen.c\
	ft_util_cs.c ft_util_diu.c ft_util_l_diu.c ft_util_ll_diu.c\
	ft_util_xx.c ft_util_l_xx.c ft_util_ll_xx.c
OFILES      =   $(CFILES:.c=.o)
BONUS_CFILES=	
BONUS_OFILES=	$(BONUS_CFILES:.c=.o)
LIBFT_PATH	=	./libft/
LIBFT_CFILES	=	ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c\
	ft_strlen.c
LIBFT_OFILES=	$(LIBFT_CFILES:.c=.o)
FLAGS       =   -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OFILES) $(LIBFT_OFILES:%=./libft/%)
	@echo "Compiling: $@"
	ar rc $(NAME) $(OFILES) $(LIBFT_OFILES:%=./libft/%);
	@echo "Done"

%.o: %.c
	@echo "Compiling: $<"
	@gcc -o $@ -c $< $(FLAGS) -I$(LIBFT_PATH)

clean:
	@echo "Cleaning: Objects"
	@rm -f $(OFILES)
	@rm -f $(LIBFT_OFILES:%=./libft/%)
	@rm -f $(BONUS_OFILES)

fclean: clean
	@echo "Cleaning: Libraries"
	@rm -f $(NAME)


re: fclean all

bonus: $(OFILES) $(BONUS_OFILES)
	ar rc $(NAME) $(OFILES) $(BONUS_OFILES)
	@echo "Done"
