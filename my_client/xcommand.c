/*
** xcommand.c for xcommand.c in /home/aidara_b/c/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sun Apr 11 04:42:28 2010 anta-m-bayang aidara
** Last update Sun Apr 18 19:42:56 2010 anta-m-bayang aidara
*/

#include	<sys/mman.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	"client.h"

extern char	*prompt;

int		quit(int s)
{
  free(prompt);
  close(s);
  my_putstr(LSUCCEES);
  exit(0);
}

static void	get_file_ext(int fd, char *line)
{
  int		len;

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

static int	get_file_loop(int s, int fd, char *file)
{
  int		res;
  char		*line;

  while ((line = get_next_line(s)) != NULL)
    {
      if ((res = check_response(line)) != EXIT)
        {
	  close(fd);
	  if (res == FAILED)
	    remove(file);
          return (res);
        }
      get_file_ext(fd, line);
      free(line);
    }
  return (SUCCEED);
}	

int		get_file(int s, char **cmd)
{
  int		fd;
  int		res;
  char		*file;
  char		*line;

  if (cmd[1] == NULL)
    return (FAILED);
  file = extract_file(cmd[1]);
  if ((fd = open(file, O_CREAT|O_TRUNC|O_WRONLY, 0644)) == -1)
    {
      xwrite(s, LERROR, strlen(LERROR));
      return (wait_server(s));
    }
  xwrite(s, LSUCCEES, strlen(LSUCCEES));
  return (get_file_loop(s, fd, file));
}

int		put_file(int s, char **cmd)
{
  char		c;
  char		*line;
  FILE		*stream;
  char		buf[BUFSIZ];

  c = FLAG;
  if (cmd == NULL || cmd[1] == NULL)
    return (FAILED);
  if ((stream = fopen(cmd[1], "r")) == NULL)
    {
      xwrite(s, LERROR, strlen(LERROR));
      return (wait_server(s));
    }
  while ((line = fgets(buf, BUFSIZ, stream)) != NULL)
    {
      xwrite(s, line, strlen(line));
      if (check_line(line) == FAILED)
	{
	  xwrite(s, &c, 1);
	  xwrite(s, "\n", 1);
	}    
    }
  fclose(stream);
  xwrite(s, LSUCCEES, strlen(LSUCCEES));
  return (wait_server(s));
}
