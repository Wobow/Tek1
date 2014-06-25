/*
** my.h for my in /home/balbo_a/rendu/Piscine-C-include
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct 10 11:01:58 2013 Alan Balbo
** Last update Sun Mar 16 21:00:55 2014 BALBO Alan
*/

#ifndef MY_H_
# define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <fcntl.h>

# define NB_FLAGS 12
# define BUFF_SIZE 4096

typedef struct	s_apin
{
  char		*pandore;
  va_list	ap;
  int		i;
  char		*s;
  void		(**f)();
}		t_apin;

/*
** my_printf functions
*/

void	my_putfloat(float);
void	my_put_ptr(int);
void	my_putbin(unsigned int);
void	my_putstr_nb(char*);
void	my_putunbr(unsigned int);
void	my_putoctal(int);
void	my_puthexa(int);
void	my_puthexa_up(int);

/*
** get_next_line functions
*/

int	my_strlen2(char*);
char	*my_concat(char*, char);
char	*get_next_line(const int);
int	clean_buffer(char *);

/*
** basic functions
*/

int	my_putchar(char c);
int	my_put_nbr(int nb);
int	my_putnbr(int nb);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
int	mu_power_rec(int nb, int power);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	*my_strdup(char *src);
void	*xmalloc(unsigned int);
int	my_printf(char*, ...);
char	*get_next_line(const int);
int	*my_intdup(int*);
char	*get_file(char*, int);
char	**my_str_to_wordtab(char*, char);

#endif /* MY_H_ */
