/*
** xlcommand.c for xlcommand.c in /home/aidara_b/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sun Apr 18 17:51:03 2010 anta-m-bayang aidara
** Last update Sun Apr 18 18:37:21 2010 anta-m-bayang aidara
*/

#include	<unistd.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<stdlib.h>
#include	"client.h"

int		lls(char **cmd)
{
  DIR           *dir;
  t_list        *list;
  struct dirent *dirent;

  list = NULL;
  if (cmd == NULL)
    return (FAILED);
  cmd[1] = cmd[1] == NULL ? "." : cmd[1];
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

int		lpwd(void)
{
  char          *path;
  char          buf[BUFSIZ];

  bzero(buf, sizeof(buf));
  path = getwd(buf);
  my_putstr(path);
  my_putstr("\n");
  return (SUCCEED);
}

int		lcd(char **cmd)
{
  if (cmd == NULL)
    return (FAILED);
  cmd[1] = cmd[1] == NULL ? "." : cmd[1];
  if (chdir(cmd[1]) == -1)
    return (FAILED);
  fflush(stdin);
  fflush(stdout);
  return (SUCCEED);
}
