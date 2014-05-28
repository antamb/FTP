/*
** xcommand_ext.c for xcommand_ext.c in /home/aidara_b/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sun Apr 18 17:07:17 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:09:16 2010 anta-m-bayang aidara
*/

#include	<fcntl.h>
#include	<stdlib.h>
#include	"serveur.h"

static void     put_file_ext(int fd, char *line)
{
  int           len;

  len = strlen(line);
  if (len > 0 && line[len - 1] == FLAG)
    {
      line[len - 1] = '\0';
      xwrite(fd, line, strlen(line));
    }
  else
    {
      xwrite(fd, line, len);
      xwrite(fd, "\n", 1);
    }
}

int             xput(int cs, char **cmd, t_sock_in sin)
{
  int           fd;
  int           res;
  char          *file;
  char          *line;

  (void)sin;
  if (cmd[1] == NULL)
    return (FAILED);
  file = extract_file(cmd[1]);
  if ((fd = open(file, O_CREAT|O_TRUNC|O_WRONLY, 0644)) == -1)
    return (FAILED);
  while ((line = get_next_line(cs)) != NULL)
    {
      if ((res = check_response(line)) != EXIT)
        {
          close(fd);
          if (res == FAILED)
            remove(file);
          return (res);
        }
      put_file_ext(fd, line);
      free(line);
    }
  close(fd);
  return (SUCCEED);
}
