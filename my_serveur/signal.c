/*
** signal.c for signal.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 20:31:15 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:16:56 2010 anta-m-bayang aidara
*/

#include	"serveur.h"
#include	<sys/time.h>
#include	<sys/wait.h>
#include	<sys/resource.h>

void		sigchld(int sig)
{
  int		status;

  (void)sig;
  while (waitpid(0, &status, WNOHANG) != -1);
}
