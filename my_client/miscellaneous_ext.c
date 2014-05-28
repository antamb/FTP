/*
** miscellaneous_ext.c for miscellaneous_ext.c in /home/aidara_b/save_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr 15 16:46:33 2010 anta-m-bayang aidara
** Last update Sat Apr 17 16:15:30 2010 anta-m-bayang aidara
*/

#include	<string.h>
#include	<stdlib.h>
#include	"client.h"

int		wait_server(int s)
{
  int		res;
  char		*line;

  while ((line = get_next_line(s)) != NULL)
    {
      if ((res = check_response(line)) != EXIT)
        return res;
    }
  return (SUCCEED);
}

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
