NAME = mintalk.h

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f

SRCS = server.c client.c

all: $(NAME)
$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)
	$(CC) $(CFLAGS) -o server server.o
	$(CC) $(CFLAGS) -o client client.o
	@echo "Compilation complete. Executables: server, client"

clean:
	$(RM) server.o client.o
	@echo "Object files cleaned"

fclean: clean
	$(RM) server client
	@echo "Executables cleaned"

re: fclean all
	@echo "Recompiled all files"
	
.PHONY: all clean fclean re
