/*
** signal.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 17:18:07 2014 sebastien
** Last update Thu Jan 16 17:20:07 2014 sebastien
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include "my_select.h"

void			get_sigwinch(int sig)
{
  my_tputs(tgetstr("cl", NULL));
  print_list(root_args);
}
