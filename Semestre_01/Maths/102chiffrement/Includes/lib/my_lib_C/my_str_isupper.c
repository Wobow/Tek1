/*
** my_str_isupper.c for my_str_isupper in /home/balbo_a/rendu/Piscine-C-Jour_06/ex_13
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 17:23:05 2013 Alan Balbo
** Last update Thu Oct 10 20:17:06 2013 Alan Balbo
*/

int     my_str_isupper(char *str)
{
  int   i;
  int   out;

  i = 0;
  out = 1;
  while (str[i] != '\0')
    {
      if (str[i] < 'A' || str[i] > 'Z')
        {
          out = 0;
        }
      i = i + 1;
    }
  return (out);
}
