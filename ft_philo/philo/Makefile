# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysbai-jo <ysbai-jo@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 17:11:24 by ael-moha          #+#    #+#              #
#    Updated: 2024/11/23 16:46:47 by ysbai-jo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo 
CC = cc 
CFLAGS  =	-Wall -Wextra #-Werror 
CFLAGS += -g  -fsanitize=thread
# CFLAGS += -g -fsanitize=address
SRCS = ft_philo.c ft_errors.c ft_routine.c ft_parsing_utils.c ft_utils.c ft_utils2.c
OBJS = $(SRCS:.c=.o)

RM = rm -f
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(NAME): $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

clean:
	$(RM) $(OBJS)

fclean : clean 
	$(RM) $(NAME)

re : fclean all


clear: re  clean