/*
** my_strcpy.c for Piscine-C-Jour_06 in /home/cesar_a/rendu/Piscine-C-Jour_06
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Mon Oct  7 09:18:29 2013 Aymeric CESAR
** Last update Thu Jan 23 20:04:19 2014 Aymeric CESAR
*/

void	my_strcpy(char *dest, char *src)
{
  while (*src)
    *(dest++) = *(src++);
  *(dest) = *(src);
}
