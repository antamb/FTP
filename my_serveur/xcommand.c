/*
** xcommand.c for xcommand.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Fri Apr  9 14:49:04 2010 anta-m-bayang aidara
** Last update Sun Apr 18 18:56:17 2010 anta-m-bayang aidara
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/mman.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	"serveur.h"

int		xquit(int cs, char **cmd, t_sock_in sin)
{
  (void)cmd;
  (void)sin;
  close(cs);
  return (EXIT);
}

int		xcd(int cs, char **cmd, t_sock_in sin)
{
  (void)cs;
  (void)sin;
  cmd[1] = cmd[1] == NULL ? "." : cmd[1];
  if (check_path(cmd[1]) == FAILED)
    return (FAILED);
  if (chdir(cmd[1]) == -1)
    return (FAILED);
  return (SUCCEED);
}

int		xpwd(int cs, char **cmd, t_sock_in sin)
{
  char		*path;
  char		buf[BUFSIZ];

  (void)cs;
  (void)cmd;
  (void)sin;
  bzero(buf, sizeof(buf));
  path = getwd(buf);
  my_putstr(path);
  my_putstr("\n");
  return (SUCCEED);
}

int		xget(int cs, char **cmd, t_sock_in sin)
{
  char		c;
  char		*line;
  FILE		*stream;
  char		buf[BUFSIZ];

  (void)cs;
  (void)sin;
  c = FLAG;
  if (wait_client(cs) == FAILED)
    return (FAILED);
  if (check_path(cmd[1]) == FAILED)
    return (FAILED);
  if ((stream = fopen(cmd[1], "r")) == NULL)
    return (FAILED);
  while ((line = fgets(buf, BUFSIZ, stream)))
    {
      my_putstr(line);    
      if (check_line(line) == FAILED)
	{
	  xwrite(cs, &c, 1);
	  xwrite(cs, "\n", 1);
	}      
    }
  fclose(stream);
  return (SUCCEED);
}

int		xls(int cs, char **cmd, t_sock_in sin)
{
  DIR		*dir;
  t_list	*list;
  struct dirent	*dirent;

  (void)cs;
  (void)sin;
  list = NULL;
  cmd[1] = cmd[1] == NULL ? "." : cmd[1];  
  if (check_path(cmd[1]) == FAILED)
    return (FAILED);
  if ((dir = opendir(cmd[1])) == NULL)
    return (FAILED);
  while ((dirent = readdir(dir)) != NULL)
    {
      if (dirent->d_name[0] != '.')
	add_element(&list, dirent->d_name);
    }
  show_list(list);
  free_list(&list);
  closedir(dir);
  return (SUCCEED);
}

