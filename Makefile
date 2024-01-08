SRCS = ft_printf.c\
		ft_put.c\
		ft_conversions.c\
		ft_extension.c
CFLAGS = -Wall -Wextra -Werror -static -c
INCLUDES = ./
NAME = libftprintf.a
CC = cc
OBJECTS = ${SRCS:.c=.o}
AR = ar
ARFLAGS = -rcs

${NAME}: ${SRCS}
	echo "Compiling LIBFT archive"
	make -C ./libft fclean all clean
	mv ./libft/libft.a libftprintf.a
	echo "Compiling .c Files into object files"
	${CC} ${CFLAGS} ${SRCS} -I ${INCLUDES}
	echo "Archiving all object files into a .a file"
	${AR} ${ARFLAGS} ${NAME} ${OBJECTS}

all: ${NAME}

clean:
	echo "rm -f ${OBJECTS}"
	rm -f ${OBJECTS}

fclean:	clean
	echo "rm -f ${NAME}"
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
