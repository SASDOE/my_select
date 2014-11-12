/*
** clear.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 17:33:27 2014 sebastien
** Last update Thu Jan 16 17:33:56 2014 sebastien
*/

#include <curses.h>
#include <term.h>
#include "my_select.h"

void	clearscreen(t_list *root)
{
  int	i;

  i = 0;
  while (i < root->nb_elem)
  {
    my_tputs(tgetstr("up", NULL));
    i = i + 1;
  }
  i = 0;
  while (i < root->nb_elem)
  {
    my_tputs(tgetstr("dl", NULL));
    i = i + 1;
  }
}
