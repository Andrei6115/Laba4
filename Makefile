NAME = laba4.a

CC = gcc

SRC = linnkedList.c		\
	  workWithList.c		\

HEADER = linnkedList.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

bonus: re

$(NAME): $(OBJ) $(HEADER)
		 @ar -r $(NAME) $(OBJ)

%.o : %.c
		 @$(CC) -c $< -o $@

clean:
		 @rm -rf $(OBJ)

fclean:	 clean
		 @rm -rf $(NAME)

re:		 fclean all