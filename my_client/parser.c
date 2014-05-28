/*
** parser.c for parser.c in /home/aidara_b/c/my_ftp
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:57:58 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:23:57 2010 anta-m-bayang aidara
*/

#include	"client.h"
#include	<stdlib.h>
#include	<stdio.h>

char		*prompt = NULL;

static int	init_prompt(void)
{
  char		*s;

  s = get_prompt();
  if (s == NULL)
    {
      prompt = strdup(PROMPT);
      return (FAILED);
    }
  prompt = strdup(s);
  return (SUCCEED);
}

static int	check_port(char **av, int *port)
{
  int		i;

  i = 0;
  if (av == NULL)
    return (FAILED);
  while (av[2][i] != '\0')
    {
      if ((av[2][i] > '9' && av[2][i] < 0) && av[2][i] != '-')
	{
	  printf(ERR_WPORT, av[2]);
	  fflush(stdout);
	  return (FAILED);
	}
      i++;
    }
  *port = atoi(av[2]);
  return (SUCCEED);
}

int		parser(char **av)
{
  int		port;

  if (check_port(av, &port) == FAILED)
    return (FAILED);
  init_prompt();
  client(port, av[1]);
  return (SUCCEED);
}
