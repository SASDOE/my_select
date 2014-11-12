/*
** mod_term.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Tue Jan 14 20:01:00 2014 sebastien
** Last update Thu Jan 16 20:01:55 2014 sebastien
*/

#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include "my_select.h"

int	init_term(char **env,
		   struct termios *term_attr)
{
  char	term_buf[TERM_BUF_SIZE];
  char	*term_name;

  if ((term_name = get_term(env)) == NULL)
    term_name = "xterm";
  if ((tgetent(term_buf, term_name)) <= 0)
  {
    puterror("error: could not find termcap database or \"");
    puterror(term_name);
    puterror("\" is not specified\n");
    return (-1);
  }
  if ((tcgetattr(0, term_attr)) < 0)
    return (puterror("error: could not get term values\n"));
  term_attr->c_lflag &= ~ICANON;
  term_attr->c_lflag &= ~ECHO;
  term_attr->c_cc[VMIN] = 1;
  term_attr->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSANOW, term_attr) < 0)
    return (puterror("error: could not set term values\n"));
  my_tputs(tgetstr("vi", NULL));
  my_tputs(tgetstr("cl", NULL));
  root_args->next->is_current = 1;
  print_list(root_args);
  return (0);
}

int	restore_term(struct termios *term_attr)
{
  clearscreen(root_args);
  term_attr->c_lflag |= ICANON;
  term_attr->c_lflag |= ECHO;
  if ((tcsetattr(0, TCSANOW, term_attr)) == -1)
    return (puterror("error: could not set term values\n"));
  my_tputs(tgetstr("ve", NULL));
  if ((close(fd_tty)) == -1)
    return (puterror("error: could not close /dev/tty\n"));
}
