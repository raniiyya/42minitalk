# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdavurov <rdavurov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/12 12:04:45 by rdavurov          #+#    #+#              #
#    Updated: 2024/04/20 23:28:35 by rdavurov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -fr

SRC = ft_printf_char.c \
ft_printf_str.c \
ft_printf_num.c \
ft_printf_pt.c \
ft_printf_undec.c \
ft_printf_hex.c \
ft_printf.c

OSRC = $(SRC:.c=.o)
TARGET = libftprintf.a

all: $(TARGET)

$(TARGET): $(OSRC)
		$(AR) $(TARGET) $(OSRC)

clean:
		rm -f $(OSRC)
		
fclean: clean
		rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re