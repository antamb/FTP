/*
** main.c for main.c in /home/aidara_b/c/my_ftp/client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:21:37 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:20:53 2010 anta-m-bayang aidara
*/

#include	"client.h"
#include	<unistd.h>

int		main(int ac, char **av)
{
  if (ac == 3)
    parser(av);
  else if (ac < 3)
    error(ERR_FARGS);
  else if (ac > 3)
    error(ERR_MARGS);
  return (0);
}
