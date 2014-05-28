/*
** command.c for command.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Fri Apr  9 14:28:23 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:12:19 2010 anta-m-bayang aidara
*/

#include	<stdlib.h>
#include	"serveur.h"

t_cmd	cmds[] = {
  {LS, "ls", xls},
  {CD, "cd", xcd},
  {GET, "get", xget},
  {PUT, "put", xput},
  {PWD, "pwd", xpwd},
  {QUIT, "quit", xquit},
  {0, NULL, NULL}
};
