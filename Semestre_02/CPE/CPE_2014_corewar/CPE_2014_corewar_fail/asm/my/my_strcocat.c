/*
** my_strcocat.c for lib in /home/cesar_a/rendu/lib/my
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Wed Jan 22 14:29:23 2014 Aymeric CESAR
** Last update Tue Mar 18 16:19:10 2014 Aymeric CESAR
*/

#include <stdlib.h>
#include "my.h"

char    *my_strcocat(char *str1, char *str2)
{
  char  *tmp;
  int   i;
  int   j;

  i = -1;
  j = 0;
  tmp = my_malloc((my_strlen(str1) + my_strlen(str2) + 1) * sizeof(*tmp));
  while (str1[++i])
    tmp[i] = str1[i];
  while (str2[j])
    tmp[i++] = str2[j++];
  tmp[i] = 0;
  return (tmp);
}
