/*
** socket.c for socket.c in /home/aidara_b/c/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 20:37:19 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:17:50 2010 anta-m-bayang aidara
*/

#include	"serveur.h"
#include	<sys/types.h>
#include	<sys/socket.h>

int		new_socket(int port, struct sockaddr_in *sin)
{
  int		s;
  
  if ((s = socket(PF_INET, SOCK_STREAM, 0)) == -1)
    return (error(ERR_SOCKT));
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  sin->sin_addr.s_addr = INADDR_ANY;
  if (bind(s, (struct sockaddr *)sin, sizeof(*sin)) == -1)
    return (error(ERR_SBIND));
  listen(s, QUEUE);
  return (s);
}
