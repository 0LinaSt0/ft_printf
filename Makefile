SRCS_LIB		= $(addprefix libft/, ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlen.c \
				ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c \
				ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_substr.c ft_putchar_fd.c ft_putstr_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c)

SRCS_PRINT		= ft_printf.c remember_required_part.c type_sign.c type_str.c type_pointer0.c type_pointer1.c type_int.c\
				type_int_without_precis.c type_int_with_precis.c helping_functions.c

OBJS		= ${SRCS_LIB:.c=.o} ${SRCS_PRINT:.c=.o}

HDRS		= libft/libft.h ft_printf.h

GCC			= gcc -Wall -Wextra -Werror

NAME		= libftprintf.a

all:		${NAME}

%.o:		%.c ${HDRS}
			${GCC} -c -o $@ $<

$(NAME): 	${OBJS}
			ar rcs ${NAME} ${OBJS}


re:			fclean all


clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

.PHONY:		all re clean fclean
