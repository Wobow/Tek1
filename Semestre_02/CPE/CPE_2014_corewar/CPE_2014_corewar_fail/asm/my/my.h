
/*
** my.h for libmy in /home/cesar_a/rendu/Piscine-C-lib/my
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Fri Oct 11 10:20:29 2013 Aymeric CESAR
** Last update Wed Jan 22 16:26:23 2014 Aymeric CESAR
*/

#ifndef LIBMY
# define LIBMY

# define BUFF_SIZE 1024
# include <stdlib.h>

void	*my_malloc(size_t size);
char	*my_strcocat(char *str1, char *str2);
char	*get_next_line(const int fd);
int	my_atoi(char *str);
int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);
char	**my_str_to_wordtab(char *str);
int	my_showstr(char *str);
int	my_putnbr_base(int nbr, char *base);
int	my_printf(const char *format, ...);
void	*my_verif(size_t size);

#endif
