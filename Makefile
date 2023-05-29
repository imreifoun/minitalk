# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areifoun <areifoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:25:35 by areifoun          #+#    #+#              #
#    Updated: 2023/02/26 12:44:27 by areifoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

server = server 

client = client

CFLAGS = -Wall -Wextra -Werror

SRC= functions.c\
		client.c\
		server.c\

OBJ= ${SRC:.c=.o}

HEADER= minitalk.h

all: $(server) $(client)


$(server): functions.o server.o
	cc $(CFLAGS) $^ -o $@
	
$(client):functions.o client.o
	cc $(CFLAGS) $^ -o $@	

%.o: %.c $(HEADER)
	cc $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJ)
	
fclean: clean
	@rm -rf $(client) $(server)
	
re: fclean all
