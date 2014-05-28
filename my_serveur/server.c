/*
** server.c for server.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr  8 18:33:44 2010 anta-m-bayang aidara
** Last update Sun Apr 18 19:19:52 2010 anta-m-bayang aidara
*/

#include	"serveur.h"
#include	<errno.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<time.h>
#include	<signal.h>

static int	check_result(int response)
{
  if (response == EXIT)
    return (EXIT);
  else if (response == FAILED)
    {
      my_putstr(ERROR);
      return (FAILED);
    }
  my_putstr(SUCCEES);
  return (SUCCEED);
}

static int	exec_command(int cs, char **cmd, t_sock_in sin)
{
  int		i;

  i = 0;
  while (cmds[i].cmd != NULL)
    {
      if (strcmp(cmds[i].cmd, cmd[0]) == 0)
	return (cmds[i].func(cs, cmd, sin));
      i++;
    }
  my_putstr(ERR_UNCMD);
  return (FAILED);
}	

int		process_clt(int cs, t_sock_in sin)
{
  int		res;
  char		*cmd;
  char		**args;
  char		swap[BUFSIZ];

  (void)sin;
  dup2(cs, STDIN_FILENO);  
  dup2(cs, STDOUT_FILENO);
  while (99)
    {
      if ((res = read(cs, swap, BUFSIZ)) > 0)
	{
	  swap[res] = '\0';
	  cmd = epur_command(swap);
	  args = str_split(cmd, " ");
	  res = exec_command(cs, args, sin);
	  if (check_result(res) == EXIT)
	    return (EXIT);
	}
    }
  return (SUCCEED);
}

int	loop(int cs, int ss, pid_t pid, socklen_t len, t_sock_in sin)
{
  errno = 0;
  while (99)
    {
      cs = accept(ss, (t_sock *)&sin, &len);
      if (cs != -1 && errno != EINTR)
	{
	  pid = fork();
	  if (pid == -1)
	    return (error(ERR_FORK));
	  else if (pid == 0)
	    {
	      close(ss);
	      process_clt(cs, sin);
	      return (SUCCEED);
	    }
	  close(cs);
	}
    }
  return (SUCCEED);
}

int		server(int port)
{
  int		ss;
  int		cs;
  pid_t		pid;
  socklen_t	len;
  t_sock_in	sin;

  if ((ss = new_socket(port, &sin)) == FAILED)
    return (FAILED);
  len = sizeof (t_sock_in);
  signal(SIGCHLD, &sigchld);
  loop(cs, ss, pid, len, sin);
  close(ss);
  return (SUCCEED);
}
