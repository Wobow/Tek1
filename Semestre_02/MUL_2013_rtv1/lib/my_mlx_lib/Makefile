##
## Makefile for MiniLibX in /home/boulon/work/c/raytraceur/minilibx
## 
## Made by Olivier Crouzet
## Login   <ol@epitech.net>
## 
## Started on  Tue Oct  5 15:56:43 2004 Olivier Crouzet
## Last update Thu Dec 12 14:54:23 2013 BALBO Alan
##


CC	= gcc

NAME	= libmlx.a

SRC	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
	mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
	mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
	mlx_int_wait_first_expose.c mlx_int_get_visual.c \
	mlx_flush_event.c mlx_string_put.c \
	mlx_new_image.c mlx_get_data_addr.c \
	mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
	mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
	mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
	mlx_rgb.c \
	shapes.c \
	draw_line.c \
	my_key_hook.c

OBJ	=$(SRC:.c=.o)
CFLAGS	=-I/usr/X11R6/include -Wno-deprecated-declarations -O3

all:	$(NAME)

aff:
	@echo -en "\e[01;36mCompilation of libmlx : "

.c.o:
	@ echo -en ".."
	@ $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME)	: aff $(OBJ)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@cp $(NAME) libmlx_$(HOSTTYPE).a
	@cp $(NAME) libmlx_$(HOSTTYPE).a ../
	@echo -e "Done.\e[00m"

clean	:
	@rm -f $(OBJ) $(NAME) *~ core *.core

re:	clean all
