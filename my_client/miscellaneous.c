/*
** miscellanous.c for miscellanous.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sat Apr 10 20:53:37 2010 anta-m-bayang aidara
** Last update Mon Apr 26 17:39:04 2010 anta-m-bayang aidara
*/

#include		<stdio.h>
#include		<netdb.h>
#include		<sys/uio.h>
#include		<unistd.h>
#include		<sys/uio.h>
#include		<unistd.h>
#include		<stdlib.h>
#include		<sys/types.h>
#include		<netinet/in.h>
#include		"client.h"

extern	char		*prompt;

char			*gethost(char *machin)
{
  struct hostent	*host;
  struct in_addr	addr;
  
  if ((host = gethostbyname(machin)) == NULL)
    {
      error(ERR_UHOST);
      free(prompt);
      exit(1);
    }
  bcopy(host->h_addr, &addr, sizeof(addr));
  return(inet_ntoa(addr));
}

char			*get_prompt(void)
{
  char			*prompt;
  char			buf[BUFSIZ];

  bzero(buf, sizeof(buf));
  if ((prompt = strcpy(buf, "(")) == NULL)
    return (NULL);
  if ((prompt = strcat(buf, getenv("USER"))) == NULL)
    return (NULL);
  if ((prompt = strcat(buf, "@")) == NULL)
    return (NULL);
  if ((prompt = strcat(buf, getenv("HOST"))) == NULL)
    return (NULL);
  if ((prompt = strcat(buf, ")")) == NULL)
    return (NULL);
  return (prompt);
}

int			check_line(char *line)
{
  int			n;

  if (line == NULL)
    return (FAILED);
  n = strlen(line);
  if (n && line[n - 1] != '\n')
    return (FAILED);
  return (SUCCEED);
}

int			check_response(char *line)
{
  if (line == NULL)
    return (FAILED);
  if (strcmp(line, ERROR) == 0)
    return (FAILED);
  else if (strcmp(line, SUCCEES) == 0)
    return (SUCCEED);
  return (EXIT);
}

char			*epur_command(char *cmd)
{
  int			i;

  if (cmd == NULL)
    return (NULL);
  i = 0;
  while (cmd[i] != '\0')
    i++;
  if (i)
    i--;
  while (cmd[i] == '\n' || cmd[i] == '\t' || cmd[i] == '\r')
    i--;
  cmd[i + 1] = '\0';
  return (cmd);
}

