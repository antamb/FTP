/*
** client.c for client.c in /home/aidara_b/c/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Fri Apr  9 15:29:20 2010 anta-m-bayang aidara
** Last update Sun Apr 18 19:31:59 2010 anta-m-bayang aidara
*/

#include		"client.h"
#include		<stdlib.h>
#include		<stdio.h>
#include		<fcntl.h>
#include		<unistd.h>

extern char		*prompt;

int			check_result(int res)
{
  if (res == FAILED)
    my_putstr(ERROR);
  else
    my_putstr(SUCCEES);
  my_putstr("\n");
  return (SUCCEED);
}

static void		loop(int s)
{
  int			res;
  char			*line;
  char			**cmd;
  char			buf[BUFSIZ];

  while (99)
    {
      my_putstr(prompt);
      line = epur_command(fgets(buf, BUFSIZ, stdin));
      res = lprocess_cmd(strdup(line));
      if (strlen(line) > 0 && res == EXIT)
	{
	  xwrite(s, line, strlen(line));
	  cmd = str_split(line, " ");
	  check_result(process_cmd(s, line, cmd));
	}
    }
}

int			client(int port, char *machin)
{
  int			s;
  struct sockaddr_in	sin;

  if ((machin = gethost(machin)) == NULL)
    return (error(ERR_UHOST));
  if ((s = new_socket(port, &sin, machin)) == FAILED)
    return (error(ERR_SOCKT));
  if (connect(s, (struct sockaddr *)&sin, sizeof (struct sockaddr_in)) == -1)
    return (error(ERR_CONN));
  loop(s);
  return (SUCCEED);
}
