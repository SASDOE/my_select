/*
** print_list.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 17:08:42 2014 sebastien
** Last update Thu Jan 16 17:23:15 2014 sebastien
*/

#include <curses.h>
#include <term.h>
#include "my_select.h"

static void	puts_select(char *str)
{
  my_tputs(tgetstr("so", NULL));
  my_tputs(str);
  my_tputs(tgetstr("se", NULL));
}

static void	puts_current(char *str)
{
  my_tputs(tgetstr("us", NULL));
  my_tputs(str);
  my_tputs(tgetstr("ue", NULL));
}

static void	puts_two(char *str)
{
  my_tputs(tgetstr("so", NULL));
  my_tputs(tgetstr("us", NULL));
  my_tputs(str);
  my_tputs(tgetstr("ue", NULL));
  my_tputs(tgetstr("se", NULL));
}

void		print_list(t_list *root)
{
  t_list	*tmp;
  int		i;

  i = 0;
  tmp = root->next;
  my_tputs(tgoto(tgetstr("cm", NULL), 0, 0));
  while (tmp != root)
  {
    if ((manage_col(i, root)) == -1)
      return ;
    if (tmp->is_select == 1 && tmp->is_current == 0)
      puts_select(tmp->str);
    else if (tmp->is_current == 1 && tmp->is_select == 0)
      puts_current(tmp->str);
    else if (tmp->is_current == 1 && tmp->is_select == 1)
      puts_two(tmp->str);
    else
      my_tputs(tmp->str);
    my_putchar('\n');
    i = i + 1;
    tmp = tmp->next;
  }
}
