/*
** error.c for error.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 18:12:03 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:12:08 2010 anta-m-bayang aidara
*/

#include	"serveur.h"
#include	<sys/types.h>
#include	<sys/uio.h>
#include	<unistd.h>

int		error(char *msg)
{
  if (msg == NULL)
    return (FAILED);
  xwrite(2, msg, strlen(msg));
  return (FAILED);
}
