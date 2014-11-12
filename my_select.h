/*
** my_select.h for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Tue Jan 14 17:21:53 2014 sebastien
** Last update Fri Jan 17 11:34:55 2014 sebastien
*/

#ifndef MY_SELECT_H_
# define MY_SELECT_H_

# include <termios.h>

typedef struct		s_list
{
  unsigned int		size_str;
  int			is_select;
  int			is_current;
  int			nb_elem;
  char			*str;
  struct s_list		*prec;
  struct s_list		*next;
}			t_list;

typedef struct		s_func
{
  char			*keycode;
  void			(*func_ptr)(t_list *root);
  struct s_func		*next;
}			t_func;

# define BUFFER_SIZE	42
# define TERM_BUF_SIZE	4096

t_list		*root_args;
int		fd_tty;

void		my_pustr(char *str);
int		puterror(char *str);
void		*puterror_null(char *str);
int		push_back(t_list **root, char *str);
int		init_root(t_list **root);
void		my_putchar(char c);
void		my_putnbr(int n);
char		*get_term(char **env);
int		my_strcmp(char *s1, char *s2);
int		restore_term(struct termios *term_attr);
int		init_term(char **env, struct termios *term_attr);
unsigned int	my_strlen(char *s);
void		buf_zero(char *buffer, int size);
void		my_tputs(char *str);
int		usage(void);
void		disp_select(t_list *root);
void		print_list(t_list *root);
void		get_sigwinch(int sig);
void		goto_prec(t_list *root);
void		goto_next(t_list *root);
void		goto_left(t_list *root);
void		goto_right(t_list *root);
void		select_it(t_list *root);
void		rm_it(t_list *root);
int		manage_col(int i, t_list *root);
void		clearscreen(t_list *root);
char		*init_prec(void);
char		*init_next(void);
char		*init_left(void);
char		*init_right(void);
t_func		*init_func(void);
char		*init_select(void);
char		*init_rm_backspace(void);
char		*init_rm_del(void);
int		get_cmd(void);

#endif /* !MY_SELECT_H_ */
