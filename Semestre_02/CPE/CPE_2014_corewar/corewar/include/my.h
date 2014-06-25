/*
** my.h for my in /home/balbo_a/rendu/Piscine-C-include
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct 10 11:01:58 2013 Alan Balbo
** Last update Sun Apr 13 10:40:33 2014 Alan BALBO
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <errno.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

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

int	my_putfloat(float);
int	my_put_ptr(int);
int	my_putbin(unsigned int);
int	my_putstr_nb(char*);
int	my_putunbr(unsigned int);
int	my_putoctal(unsigned int);
int	my_putoctal_form(unsigned int, int);
int	my_puthexa(unsigned int);
int	my_puthexa_up(unsigned int);
int	my_putchar2(int);

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

int	my_putchar(char);
int	my_putnbr(int n);
int	my_putstr(char *str);
int	my_strlen(char *str);
long	my_getnbr(char *str);
int	my_power_rec(int nb, int power);
char	*my_strcpy(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcat(char *dest, char *src);
char	*my_strdup(char *src);
void	*xmalloc(unsigned int);
int	my_printf(char*, ...);
char	*get_next_line(const int);
int	my_putnbr_base(int, char*);
char	*my_strconcat(char*, char*);

#endif /* MY_H_ */
