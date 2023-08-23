NAME	=	libft.a



SRC		=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
			ft_bzero.c ft_memcpy.c ft_toupper.c ft_memset.c ft_memmove.c ft_strchr.c ft_strlcat.c \
			ft_tolower.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
			ft_strlcpy.c ft_calloc.c ft_strdup.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
			ft_strmapi.c ft_split.c ft_printf.c ft_printf_str.c ft_printf_sinchar.c ft_printf_int.c \
			ft_printf_unsigned.c ft_printf_hex_lower.c ft_printf_hex_upper.c ft_printf_void.c \
			get_next_line.c

OBJS	=	${SRC:.c=.o}


CC		=	gcc

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra -g

all: ${NAME}

${NAME}: ${OBJS}
	ar -rc  ${NAME} ${OBJS}

clean:
	${RM}	${OBJS}

fclean: clean
	${RM}	${NAME}

re: fclean all
