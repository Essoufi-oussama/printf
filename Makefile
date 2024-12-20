NAME= libftprintf.a
srcs= ft_printf.c ft_put_big_hexa.c ft_put_hex.c ft_putnbr.c \
	ft_putnbr_u.c ft_putstr.c ft_putchar.c
objs=$(srcs:.c=.o)
flags = -Wall -Wextra -Werror

all : $(NAME)

libftprintf.a: $(objs)
	ar -rc $@ $^

%.o: %.c ft_printf.h 
	cc $(flags) -c $<

clean: 
	rm -f $(objs) 

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean 