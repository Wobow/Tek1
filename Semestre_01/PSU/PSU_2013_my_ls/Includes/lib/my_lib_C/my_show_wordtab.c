/*
** my_show_wordtab.c for my_show_wordtab in /home/balbo_a/rendu/Piscine-C-lib/my
** 
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
** 
** Started on  Mon Oct 21 09:07:36 2013 Alan Balbo
** Last update Mon Oct 21 09:10:11 2013 Alan Balbo
*/

int	my_show_wordtab(char **tab)
{
  int   i;

  i = 0;
  while (tab[i] != '\0')
    {
      my_putstr(tab[i]);
      i = i + 1;
      my_putchar(10);
    }
}
