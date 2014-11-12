/*
** init_others_keys.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 18:42:48 2014 sebastien
** Last update Thu Jan 16 18:49:25 2014 sebastien
*/

#include <stdlib.h>
#include "my_select.h"

char	*init_select(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(2))
  {
    keycode[0] = 32;
    keycode[1] = 0;
  }
  return (keycode);
}

char	*init_rm_backspace(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(2))
  {
    keycode[0] = 127;
    keycode[1] = 0;
  }
  return (keycode);
}

char	*init_rm_del(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(5))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 51;
    keycode[3] = 126;
    keycode[4] = 0;
  }
  return (keycode);
}
