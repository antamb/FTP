/*
** miscellaneous_ext.c for miscellaneous_ext.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sat Apr 10 23:28:50 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:27:28 2010 anta-m-bayang aidara
*/

#include	<sys/param.h>
#include	<stdlib.h>
#include	"serveur.h"

extern char	*s_path;

char		*extract_file(char *line)
{
  int		i;
  char		*file;
  char		**tab;

  i = 0;
  file = "";
  if ((tab = str_split(line, "/")) == NULL)
    return (line);
  while (tab[i] != NULL)
    i++;
  if (i)
    file = tab[i - 1];
  return (file);
}

int		check_cmd(char *cmd)
{
  if (cmd == NULL)
    return (FAILED);
  if (strcmp(cmd, S_LS) != 0 && strcmp(cmd, S_PWD) != 0 \
      && strcmp(cmd, S_CD) != 0 && strcmp(cmd, S_GET) != 0 \
      && strcmp(cmd, S_PUT) != 0 && strcmp(cmd, S_PWD) != 0 \
      && strcmp(cmd, S_QUIT) != 0)
    return (error(ERR_UNCMD));
  return (SUCCEED);
}

int		check_path(char *path)
{
  char		*r_path;
  char		buf[BUFSIZ];

  if ((r_path = realpath(path, buf)) == NULL)
    {
      my_putstr(ERR_ACCES);
      return (FAILED);
    }
  if (strncmp(r_path, s_path, strlen(s_path)) != 0)
    {
      my_putstr(ERR_ACCES);
      return (FAILED);
    }
  return (SUCCEED);
}

int		check_line(char *line)
{
  int		n;
  
  if (line == NULL)
    return (FAILED);
  n = strlen(line);
  if (n && line[n - 1] != '\n')
    return (FAILED);
  return (SUCCEED);
}

int		check_response(char *line)
{
  if (line == NULL)
    return (FAILED);
  if (strncmp(line, ERROR, SIZE_E) == 0)
    return (FAILED);
  else if (strncmp(line, SUCCEES, SIZE_S) == 0)
    return (SUCCEED);
  return (EXIT);
}
