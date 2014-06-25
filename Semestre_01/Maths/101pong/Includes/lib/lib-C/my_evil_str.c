/*
** my_evil_str.c for my_evil_str in /home/balbo_a/rendu/Piscine-C-Jour_04
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Thu Oct  3 11:43:41 2013 Alan Balbo
** Last update Thu Oct 31 13:09:47 2013 Alan Balbo
*/

char	*my_evil_str(char *str)
{
  int	top;
  int	bot;
  char	tmp;

  top = my_strlen(str) - 1;
  bot = 0;
  while (bot <= top)
    {
      tmp = str[top];
      str[top] = str[bot];
      str[bot] = tmp;
      top = top - 1;
      bot = bot + 1;
    }
  return (str);
}
