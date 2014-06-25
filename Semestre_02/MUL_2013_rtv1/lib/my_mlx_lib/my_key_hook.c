/*
** my_key_hook.c for my_key_hook in /home/balbo_a/rendu/CPE-2013-BSQ/Bonus/srcs
**
** Made by BALBO Alan
** Login   <balbo_a@epitech.net>
**
** Started on  Wed Dec  4 19:12:53 2013 BALBO Alan
** Last update Wed Dec  4 19:14:55 2013 BALBO Alan
*/

#include <mlx.h>
#include <mlx_int.h>

int	my_key_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[KeyPress].hook = funct;
  win->hooks[KeyPress].param = param;
  win->hooks[KeyPress].mask = KeyPressMask;
}

int	my_pointer_hook(t_win_list *win, int (*funct)(), void *param)
{
  win->hooks[MotionNotify].hook = funct;
  win->hooks[MotionNotify].param = param;
  win->hooks[MotionNotify].mask = PointerMotionMask;
}
