/*
** my.h for my.h in /u/all/aidara_b/cu/rendu/include
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Fri Oct 17 21:32:36 2008 anta-m-bayang aidara
** Last update Thu Apr 15 18:58:20 2010 anta-m-bayang aidara
*/

#ifndef _MY_
# define _MY_

#include <stdio.h>
#define ALLOC 512
#define SIZEBUFF BUFSIZ
#define SIZETOREAD BUFSIZ
#define LEN(X) my_strlen(X)
#define SIZE(x) size_tab(x)

typedef struct	s_s
{
  char		*buff;
  int		siz;
  int		j;
}		t_s;

typedef struct  s_p
{
  char		buffert[SIZETOREAD + 1];
  char          buf[SIZEBUFF + 1];
  int           i;
}               t_p;

int	freetab(char **tab);
int	my_putstr(char *s);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int len);

char	*my_strdup(char *str);
char	*get_next_line(int fd);
char	*my_strcpy(char *dst, char *src);
char	*my_strcat(char *s, char *append);
char	*my_strncpy(char *dst, char *src, int len);
char	*my_strncat(char *s, char *append, int count);
char	*get_str(int nb);

char	**wordtab(char *s);
char	**str_split(char *s, const char *ct);

void	my_bzero(void *b, int len);
#endif /*_MY_*/
