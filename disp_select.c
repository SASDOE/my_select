/*
** disp.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 16:59:58 2014 sebastien
** Last update Thu Jan 16 17:05:39 2014 sebastien
*/

#include <unistd.h>
#include "my_select.h"

int		is_last(t_list *tmp, t_list *root)
{
  tmp = tmp->next;
  while (tmp != root)
  {
    if (tmp->is_select == 1)
      return (0);
    tmp = tmp->next;
  }
  return (1);
}

void		disp_select(t_list *root)
{
  t_list	*tmp;

  tmp = root->next;
  while (tmp != root)
  {
    if (tmp->is_select == 1)
    {
      my_putstr(tmp->str);
      if (is_last(tmp, root) == 0)
	write(1, " ", 1);
    }
    tmp = tmp->next;
  }
}
