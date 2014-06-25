/*
** my_str_isnum.c for my_str_isnum in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_11
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 17:16:51 2013 Alan Balbo
** Last update Mon Oct  7 17:18:37 2013 Alan Balbo
*/

int     my_str_isnum(char *str)
{
  int   i;
  int   out;

  i = 0;
  out = 1;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
        {
          out = 0;
        }
      i = i + 1;
    }
  return (out);
}
