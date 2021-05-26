# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-hou <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2019/11/28 18:16:52 by rvan-hou       #+#    #+#                 #
#    Updated: 2019/12/15 13:58:13 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = printf.h

FLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c \
		getnumbers.c \
		libft_utils.c  \
		printchar.c \
		printstring.c \
		printdigit.c \
		ll_printdigit.c \
		printdigit_utils.c \
		ll_printdigit_utils.c \
		printunsigned_int.c \
		printunsigned_int_utils.c \
		ll_printunsigned_int.c \
		ft_printpercent.c \
		printhex.c \
		printhex_utils.c \
		ll_printhex.c \
		printptr.c \
		setptr.c \

BONUS_SRC = ft_printf_bonus.c \
			getnumbers_bonus.c \
			libft_utils_bonus.c  \
			printchar_bonus.c \
			printstring_bonus.c \
			printdigit_bonus.c \
			ll_printdigit_bonus.c \
			printdigit_utils_bonus.c \
			ll_printdigit_utils_bonus.c \
			printunsigned_int_bonus.c \
			printunsigned_int_utils_bonus.c \
			ll_printunsigned_int_bonus.c \
			ft_printpercent_bonus.c \
			printhex_bonus.c \
			printhex_utils_bonus.c \
			ll_printhex_bonus.c \
			printptr_bonus.c \
			setptr_bonus.c \

REG_OBJ = $(SRC:.c=.o)

BONUS_OBJ = $(BONUS_SRC:.c=.o)

ifdef WITH_BONUS
OBJ = $(REG_OBJ) $(BONUS_OBJ)
else
OBJ = $(REG_OBJ)
endif

all: $(NAME)

$(NAME): $(OBJ)
	gcc -c $(SRC)
	ar -rc $(NAME) $?

%.o:%.c $(HEADER)
	gcc $(FLAGS) -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	/bin/rm -f $(REG_OBJ) $(BONUS_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
