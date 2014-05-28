/*
** wait_client.c for wait_client.c in /home/aidara_b/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr 15 23:35:26 2010 anta-m-bayang aidara
** Last update Fri Apr 16 11:57:15 2010 anta-m-bayang aidara
*/

#include	<stdlib.h>
#include	"serveur.h"

int		wait_client(int cs)
{
  int		res;
  char		*line;

  while ((line = get_next_line(cs)) != NULL)
    {
      if ((res = check_response(line)) != EXIT)
        return (res);
    }
  return (SUCCEED);
}
