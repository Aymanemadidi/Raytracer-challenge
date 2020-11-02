SRCS =	main.c\
		tuple_oper.c\
		tuple_oper1.c\
		utils.c\
		vec_point.c\

CFLAGS := -Wall -Werror -Wextra

OBJS := ${SRCS:c=o} 
PROGS := ${SRCS:.c=}

.PHONY: all

all: ${PROGS}

${PROGS} : % : %.o Makefile
	${CC} $< -o $@

clean:
	rm -f ${PROGS} ${OBJS}

%.o: %.c Makefile
	${CC} ${CFLAGS} -c $<