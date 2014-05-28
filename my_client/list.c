/*
** miscellanous.c for miscellanous.c in /home/aidara_b/c/my_ftp/my_serveur
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Sat Apr 10 20:53:37 2010 anta-m-bayang aidara
** Last update Sun Apr 18 18:10:27 2010 anta-m-bayang aidara
*/

#include	<stdlib.h>
#include	"client.h"

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

