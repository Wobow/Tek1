/*
** my_str_islower.c for my_str_islower in /home/balbo_a/rendu/Piscine-C-Jour_06
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct  7 17:20:15 2013 Alan Balbo
** Last update Mon Oct  7 17:21:46 2013 Alan Balbo
*/

int     my_str_islower(char *str)
{
  int   i;
  int   out;

  i = 0;
  out = 1;
  while (str[i] != '\0')
    {
      if (str[i] < 'a' || str[i] > 'z')
        {
          out = 0;
        }
      i = i + 1;
    }
  return (out);
}
