/*
** socket.c for socket.c in /home/aidara_b/c/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 20:37:19 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:24:43 2010 anta-m-bayang aidara
*/

#include	"client.h"
#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/types.h>

int		new_socket(int port, struct sockaddr_in *sin, \
				   char *machin)
{
  int		s;

  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (error(ERR_SOCKT));
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = inet_addr(machin);
  return (s);
}
