NAME = minitalk.a
FLAG = -Wall -Wextra -Werror
UTILS = $(shell find . -name "ft_*.c") 

all: $(NAME)
			gcc server.c $(NAME) -o server
			gcc client.c $(NAME) -o client
$(NAME):
			gcc $(FLAG) -c $(UTILS) 
			ar rc $(NAME) *.o

clean:
		rm -rf *.o
		rm -rf server
		rm -rf client

fclean: clean
		rm -rf $(NAME)

re: fclean all