/*
** parser.c for parser.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:42:07 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:15:28 2010 anta-m-bayang aidara
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"serveur.h"

char		*s_path = NULL;

static int	check_port(char **av, int *port)
{
  int		i;

  i = 0;
  if (av == NULL)
    return (FAILED);
  while (av[1][i] != '\0')
    {
      if (av[1][i] > '9' || av[1][i] < '0')
	{
	  printf(ERR_WPORT, av[1]);
	  fflush(stdout);
	  return (FAILED);
	}
      i++;
    }
  *port = atoi(av[1]);
  return (SUCCEED);
}

int		parser(char **av)
{
  int		port;
  char		buf[BUFSIZ];

  if (check_port(av, &port) == FAILED)
    return (FAILED);
  if ((s_path = getwd(buf)) == NULL)
    error(ERR_GPATH);
  server(port);
  return (SUCCEED);
}
