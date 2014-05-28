/*
** miscellanous.c for miscellanous.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sat Apr 10 20:53:37 2010 anta-m-bayang aidara
** Last update Thu Apr 15 23:29:07 2010 anta-m-bayang aidara
*/

#include	<stdlib.h>
#include	"serveur.h"

int		free_list(t_list **list)
{
  t_list	*swap;

  if (*list == NULL)
    return (FAILED);
  while (*list != NULL)
    {
      free((*list)->name);
      swap = *list;
      *list = (*list)->next;
      free(swap);
    }
  return (SUCCEED);
}

int		add_element(t_list **list, char *name)
{
  t_list	*elem;

  if ((elem = malloc(sizeof(t_list))) == NULL)
    return (FAILED);
  elem->name = strdup(name);
  elem->next = *list;
  *list = elem;
  return (SUCCEED);
}

int             sort_alph_list(t_list **list)
{
  char		*swap;
  t_list	*swap1;
  t_list	*swap2;

  if (list == NULL)
    return (FAILED);
  swap1 = *list;
  while (swap1 != NULL)
    {
      swap2 = swap1->next;
      while (swap2 != NULL)
        {
          if (strcmp(swap1->name, swap2->name) > 0)
            {
              swap = swap1->name;
              swap1->name = swap2->name;
              swap2->name = swap;
            }
          swap2 = swap2->next;
        }
      swap1 = swap1->next;
    }
  return (SUCCEED);
}

int		show_list(t_list *list)
{
  t_list	*swap;

  sort_alph_list(&list);
  swap = list;
  while (swap != NULL)
    {
      my_putstr(swap->name);
      my_putstr("\n");
      swap = swap->next;
    }
  return (SUCCEED);
}

char		*epur_command(char *cmd)
{
  int		i;

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
