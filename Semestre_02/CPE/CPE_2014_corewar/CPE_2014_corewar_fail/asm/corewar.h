/*
** corewar.h for corewar in /home/cesar_a/rendu/CPE_2014_corewar/ASM
** 
** Made by Aymeric CESAR
** Login   <cesar_a@epitech.net>
** 
** Started on  Mon Mar 31 15:32:42 2014 Aymeric CESAR
** Last update Sat Apr 12 16:14:13 2014 Aymeric CESAR
*/

#ifndef COREWAR_H_
# define COREWAR_H_

typedef struct	bop_s
{
  int		label;
  int		cmd;
  char		type[4];
  char		**args;
  struct bop_s	*next;
}		bop_t;

typedef struct	lb_s
{
  int		cur;
  char		*name;
  struct lb_s	*next;
}		lb_t;

char	**my_arg_to_wordtab(char *str);
int	init(int *src, char *name, header_t *head);
void	my_wr(int fd, header_t head, bop_t *bop, lb_t *lb);
void	my_chk_lab(char *s, lb_t **lb, int cur);
char	my_get_type(char **str, int *cur, int cmd, int i);
int	check_args(char *arg, bop_t *bop, int *cur);
void	my_get_ls(char *s, bop_t **bop, int *cur, int cmd);
void	my_get_cmd(char **s, int *cur, bop_t **bop, lb_t **lb);

#endif /* COREWAR_H_ */
