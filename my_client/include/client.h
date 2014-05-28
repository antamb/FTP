/*
** client.h for client.h in /home/aidara_b/c/my_ftp/my_client/include
** 
** Made by anta-m-bayang aidara
** Login   <aidara_b@epitech.net>
** 
** Started on  Wed Apr  7 15:25:50 2010 anta-m-bayang aidara
** Last update Sun Apr 18 18:16:39 2010 anta-m-bayang aidara
*/

#ifndef _CLIENT_
# define _CLIENT_

/*Includes system*/
#include "my.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

/*Defines*/
#define PROMPT	"$>"

#define ERROR	"=>ERROR"
#define SUCCEES	"=>SUCCEES"
#define LERROR  "=>ERROR\n"
#define LSUCCEES "=>SUCCEES\n"	

#define FLAG	3
#define EXIT	2
#define FAILED	-1
#define SUCCEED	0

/*Define explamations*/
#define E_LS	"Listing directory.\n"
#define E_CD	"Change directory.\n"
#define E_PWD	"Display current path.\n"
#define E_QUIT	"Exit client.\n"
#define E_GET	"Download file.\n"
#define E_PUT	"Upload file.\n"

/*Define commands*/
#define LS	"ls"
#define CD	"cd"
#define GET	"get"
#define PUT	"put"
#define PWD	"pwd"
#define QUIT	"quit"	

#define LLS	"lls"
#define LPWD	"lpwd"
#define LCD	"lcd"

/*Defines error*/
#define ERR_CONN	"client: error connexion server.\n"
#define ERR_UFILE	"Unable to upload file.\n"
#define ERR_DFILE	"Unable to download file.\n"
#define ERR_UHOST	"hostname nor servname provided, or not known.\n"
#define ERR_SOCKT	"Error socket.\n"
#define ERR_UNCMD	"Unknown command.\n"	
#define ERR_SBIND	"Unable to bind address\n"
#define ERR_FARGS	"client: Too few arguments.\n"
#define ERR_MARGS	"client: Too many arguments.\n"
#define ERR_WPORT	"client: Unknown port `%s'.\n"

/*Define structure*/
typedef struct  s_list{
  char          *name;
  struct s_list *next;
}               t_list;

/*Defines functions*/
int	lpwd(void);
int	lls(char **cmd);
int	lcd(char **cmd);

int	error(char *msg);
int	parser(char **av);
int	client(int port, char *machin);
int	xwrite(int fd, char *str, size_t size);
int	new_socket(int port, struct sockaddr_in *sin, char *machin);

int	quit(int s);
int	wait_server(int s);
int	check_line(char *line);

int     check_result(int res);
int     free_list(t_list **list);
int     show_list(t_list *list);
int     add_element(t_list **list, char *name);
int	check_response(char *res);
int	get_file(int s, char **cmd);
int	put_file(int s, char **cmd);
int	lprocess_cmd(char *line);
int	process_cmd(int s, char *line, char **cmd);
int     sort_alph_list(t_list **list);

char	*get_prompt(void);
char	*gethost(char *machin);
char	*extract_file(char *line);
char	*epur_command(char *cmd);
#endif /*_CLIENT_*/
