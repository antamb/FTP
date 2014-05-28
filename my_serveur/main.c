/*
** main.c for main.c in /home/aidara_b/c/my_ftp/serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:23:29 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:12:31 2010 anta-m-bayang aidara
*/

#include	"serveur.h"

int		main(int ac, char **av)
{
  if (ac == 2)
    parser(av);
  else if (ac > 2)
    error(ERR_MARGS);
  else if (ac < 2)
    error(ERR_FARGS);
  return (SUCCEED);
}
