# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: averheij <averheij@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 12:19:16 by averheij       #+#    #+#                 #
#    Updated: 2019/11/22 10:39:41 by averheij      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME        =   libftprintf.a
CFILES      =   ft_printf.c ft_conv_csp%n.c ft_conv_diu.c ft_conv_l_diu.c\
	ft_conv_ll_diu.c ft_conv_xx.c ft_conv_ll_xx.c ft_util_gen.c\
	ft_util_cs.c ft_util_diu.c ft_util_l_diu.c ft_util_ll_diu.c\
	ft_util_xx.c ft_util_ll_xx.c
OFILES      =   $(CFILES:.c=.o)
BONUS_CFILES=	
BONUS_OFILES=	$(BONUS_CFILES:.c=.o)
LIBFT_PATH	=	./libft/
LIBFT_CFILES	=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c ft_strlen.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_calloc.c\
	ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c\
	ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_lstnew_bonus.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
	ft_lstlast_bonus.c ft_lstsize_bonus.c ft_lstdelone_bonus.c\
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
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
