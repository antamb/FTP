/*
** serveur.h for serveur.h in /home/aidara_b/c/my_ftp/my_serveur/include
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:27:34 2010 anta-m-bayang aidara
** Last update Sun Apr 18 17:26:25 2010 anta-m-bayang aidara
*/

#ifndef _SERVEUR_
# define _SERVEUR_

/*Includes system*/
#include "my.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*Defines*/
#define QUEUE	42
#define SIZE_E	7
#define SIZE_S	9

#define ERROR	"=>ERROR\n"
#define SUCCEES	"=>SUCCEES\n"

#define FLAG	3
#define EXIT	1
#define FAILED	-1
#define SUCCEED	0

/*Define commands*/
#define LS	0
#define CD	1
#define GET	2
#define PUT	3
#define PWD	4
#define QUIT	5

#define S_LS	"ls"
#define S_CD	"cd"
#define S_GET	"get"
#define S_PUT	"put"
#define S_PWD	"pwd"
#define S_QUIT	"quit"

/*Define error*/
#define ERR_FORK	"Unable to fork process.\n"
#define ERR_FOPEN	"Unable to open file.\n"
#define ERR_UNCMD	"Unknown command.\n"
#define ERR_ACCES	"Permition denied.\n"
#define ERR_GPATH	"Unable to get current path.\n"
#define ERR_RDCMD	"Unable to read command.\n"
#define ERR_SBIND	"Unable to bind address.\n"
#define ERR_SOCKT	"Error socket.\n"
#define ERR_WPORT	"serveur: Unknown port `%s'.\n"
#define ERR_FARGS	"serveur: Too few arguments.\n"
#define ERR_MARGS	"serveur: Too many arguments.\n"

/*Define structure*/
typedef struct	s_cmd{
  int	flag;
  char	*cmd;
  int	(*func)();
}		t_cmd;

typedef struct	s_list{
  char		*name;
  struct s_list	*next;
}		t_list;

typedef struct sockaddr		t_sock;
typedef struct sockaddr_in	t_sock_in;
/*Extern*/
extern t_cmd cmds[];

/*Define functions*/
int	xls(int cs, char **cmd, t_sock_in sin);
int	xcd(int cs, char **cmd, t_sock_in sin);
int	xget(int cs, char **cmd, t_sock_in sin);
int	xput(int cs, char **cmd, t_sock_in sin);
int	xpwd(int cs, char **cmd, t_sock_in sin);
int	xquit(int cs,char **cmd, t_sock_in sin);

int	error(char *msg);
int	server(int port);
int	parser(char **av);
int	xwrite(int fd, char *str, size_t size);
int	new_socket(int port, struct sockaddr_in *sin);

int	check_path(char *path);
int	check_cmd(char *cmd);
int	check_line(char *line);
int	show_list(t_list *list);
int	free_list(t_list **list);
int	wait_client(int s);
int	check_response(char *line);
int	add_element(t_list **list, char *name);

void	sigchld(int sig);

char	*epur_command(char *cmd);
char	*extract_file(char *line);

#endif /*_SERVEUR_*/
