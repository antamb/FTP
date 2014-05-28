/*
** xwrite.c for xwrite.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 18:14:46 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:18:54 2010 anta-m-bayang aidara
*/

#include	"serveur.h"
#include	<sys/types.h>
#include	<sys/uio.h>
#include	<unistd.h>

int		xwrite(int fd, char *str, size_t size)
{
  if (str == NULL)
    return (FAILED);
  if (write(fd, str, size) == -1)
    return (FAILED);
  return (SUCCEED);
}
