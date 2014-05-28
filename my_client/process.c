/*
** process.c for process.c in /home/aidara_b/my_ftp/my_client
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Thu Apr 15 22:35:14 2010 anta-m-bayang aidara
** Last update Sun Apr 18 18:15:54 2010 anta-m-bayang aidara
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"client.h"

static int      exec_command(int s)
{
  int		res;
  char		*line;

  while ((line = get_next_line(s)) != NULL)
    {
      if  ((res = check_response(line)) != EXIT)
        return (res);
      my_putstr(line);
      my_putstr("\n");
      free(line);
    }
  return (SUCCEED);
}

int		lprocess_cmd(char *line)
{
  int		res;
  char		**cmd;

  cmd = str_split(line, " ");
  if (line == NULL || cmd == NULL)
    return (FAILED);
  if (strcmp(cmd[0], LLS) == 0)
    {
      check_result(res = lls(cmd));
      return (res);
    }
 else if (strcmp(cmd[0], LPWD) == 0)
   {   
     check_result(res = lpwd());
     return (res);
   } 
 else if (strcmp(cmd[0], LCD) == 0)
   { 
     check_result(res = lcd(cmd));
     return (res);
   }
  return (EXIT);
}

int		process_cmd(int s, char *line, char **cmd)
{
  if (line == NULL || cmd == NULL)
    return (FAILED);
  if (strcmp(cmd[0], QUIT) == 0)
    quit(s);
  else if (strcmp(cmd[0], GET) == 0)
    return (get_file(s, cmd) == FAILED ? error(ERR_DFILE) : SUCCEED);
  else if (strcmp(cmd[0], PUT) == 0)
    return (put_file(s, cmd) == FAILED ? error(ERR_UFILE) : SUCCEED);
  else
    return (exec_command(s));
  return (SUCCEED);
}
