##
## Makefile for Makefile in /home/aidara_b/c/my_ftp
## 
## Made by anta-m-bayang aidara
## Login   <aidara_b@epitech.net>
## 
## Started on  Tue Mar  2 11:01:13 2010 anta-m-bayang aidara
## Last update Sun Apr 18 19:35:53 2010 anta-m-bayang aidara
##

CC_FreeBSD	= cc

CC_sun4		= /usr/sfw/bin/gcc

CC_ia64-linux	= /usr/bin/gcc

CC		= gcc

SERVER		= ./my_serveur

CLIENT		= ./my_client

NAME1		= client

NAME2		= serveur

INCLUDE_S	= -I$(SERVER)/include/

INCLUDE_C	= -I$(CLIENT)/include/

OBJ_S		= $(CC) -c $(SERVER)/*.c $(INCLUDE_S)

OBJ_C		= $(CC) -c $(CLIENT)/*.c $(INCLUDE_C)

RM		= rm -f

LDFLAGS		= -L./lib -lmy_`uname -s`

CFLAGS		= -Werror -ansi -pedantic -ggdb3 -pipe -Wall -W 

all		:
		$(OBJ_S)
		mv *.o $(SERVER)
		$(CC) $(SERVER)/*.o $(LDFLAGS) $(INCLUDE_S) -o $(NAME2)
		$(OBJ_C)
		mv *.o $(CLIENT)
		$(CC) $(CLIENT)/*.o $(LDFLAGS) $(INCLUDE_C) -o $(NAME1)

clean		:
		cd $(CLIENT) && $(RM) *.o *~ *#
		cd $(SERVER) && $(RM) *.o *~ *#

fclean		:clean
		$(RM) $(NAME1) $(NAME2)

re		:fclean all
		cd $(CLIENT) && $(RM) *.o *~ *#
		cd $(SERVER) && $(RM) *.o *~ *#
