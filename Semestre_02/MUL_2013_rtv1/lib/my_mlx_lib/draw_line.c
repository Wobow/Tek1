/*
** draw_line.c for draw_line in /home/balbo_a/rendu/fdf-2018-balbo_a
**
** Made by Alan Balbo
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Nov 20 16:50:57 2013 Alan Balbo
** Last update Sun Dec  8 14:26:18 2013 BALBO Alan
*/

void	draw_line(void *img, int x1, int y1, int x2, int y2, int color)
{
  int	pony;

  if (x1 < x2 && abs(y2 - y1) <= abs(x2 - x1))
    {
      pony = x1;
      while (pony <= x2)
	{
	  if (pony > 0)
	    my_pixel_put_image(img, pony, y1+((y2-y1)*(pony-x1))/(x2-x1), color);
	  pony = pony + 1;
	}
    }
  else if (y1 < y2 && abs(y2 - y1) >= abs(x2 - x1))
    {
      pony = y1;
      while (pony <= y2)
	{
	  if (x1+((x2-x1)*(pony-y1))/(y2-y1) > 0)
	    my_pixel_put_image(img, x1+((x2-x1)*(pony-y1))/(y2-y1), pony, color);
	  pony = pony + 1;
	}
    }
  else
    draw_line(img, x2, y2, x1, y1, color);
}
