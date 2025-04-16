# NAME = mintalk.h

# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# RM = rm -f

# SRCS = server.c client.c

# LIBFT_DIR	=	./libft
# LIBFT_NAME	=	libft.a
# LIBFT		=	$(LIBFT_DIR)/$(LIBFT_NAME)


# all: $(NAME)
# $(NAME): $(SRCS)
# 	$(CC) $(CFLAGS) -c $(SRCS)
# 	$(CC) $(CFLAGS) -o server server.o
# 	$(CC) $(CFLAGS) -o client client.o
# 	$(CC) $(CFLAGS) -c $(LIBFT)
# 	$(CC) $(CFLAGS) -o server server.o $(LIBFT)
# 	$(CC) $(CFLAGS) -o client client.o $(LIBFT)
# 	@echo "Compiling with libft..."
# 	@echo "Compilation complete. Executables: server, client"

# clean:
# 	$(RM) server.o client.o
# 	@echo "Object files cleaned"

# fclean: clean
# 	$(RM) server client
# 	@echo "Executables cleaned"

# re: fclean all
# 	@echo "Recompiled all files"
	
# .PHONY: all clean fclean re


# Project name
NAME_SERVER = server
NAME_CLIENT = client

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Libft setup
LIBFT_DIR = ./libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

# Source and object files
SRCS_SERVER = server.c
SRCS_CLIENT = client.c
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Default target
all: $(LIBFT) $(NAME_SERVER) $(NAME_CLIENT)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME_SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER) $(LIBFT)

$(NAME_CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT) $(LIBFT)

clean:
	$(RM) $(OBJS_SERVER) $(OBJS_CLIENT)
	make -C $(LIBFT_DIR) clean
	@echo "🧹 Object files cleaned."

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	make -C $(LIBFT_DIR) fclean
	@echo "🚮 Executables cleaned."

re: fclean all

.PHONY: all clean fclean re
