CC = cc 
FLAGS = -Wall -Wextra -Werror
NAME_SERVER = server
NAME_CLIENT = client

LIBFT_DIR = libft 
FT_PRINTF_DIR = ft_printf 
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME): server.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -o $@ $^

$(CLIENT_NAME): client.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(FLAGS) -o $@ $^

server.o: server.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

client.o: client.c minitalk.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(FT_PRINTF_DIR)
	rm -f server.o client.o

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) fclean -C $(FT_PRINTF_DIR)
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re