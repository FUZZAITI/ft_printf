NAME = libftprintf.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g3

FILES = ft_printf.c


OUTPUTS := $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OUTPUTS)
	ar rcs $@ $^ 

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clear: 
	rm -rf *.o	

fclear: clear 
	rm -rf $(NAME)