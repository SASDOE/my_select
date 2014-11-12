/*
** cmd.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 19:56:04 2014 sebastien
** Last update Fri Jan 17 14:42:50 2014 chapui_s
*/

#include <stdlib.h>
#include "my_select.h"

static int	do_func(char *buf,
			t_func *list_func,
			t_list *root)
{
  void		(*func_tmp)(t_list *root);

  while (list_func && my_strcmp(buf, list_func->keycode) != 0)
    list_func = list_func->next;
  if (list_func)
  {
    func_tmp = (list_func)->func_ptr;
    func_tmp(root);
  }
  return (0);
}

int			get_cmd(void)
{
  t_func		*list_func;
  char			buffer[BUFFER_SIZE];
  int			ret_read;

  list_func = NULL;
  if ((list_func = init_func()) == NULL)
    return (-1);
  buf_zero(&buffer[0], BUFFER_SIZE);
  while (((ret_read = read(0, buffer, BUFFER_SIZE)) > 0)
	 && buffer[0] != '\n')
  {
    if (ret_read == -1)
      return (puterror("error: could not read\n"));
    if (buffer[0] == 27 && buffer[1] == 0)
      break ;
    do_func(&buffer[0], list_func, root_args);
    buf_zero(&buffer[0], BUFFER_SIZE);
  }
  return (0);
}
