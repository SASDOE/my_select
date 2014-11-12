/*
** init_keys.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Thu Jan 16 18:26:03 2014 sebastien
** Last update Fri Jan 17 11:34:47 2014 sebastien
*/

#include <stdlib.h>

char	*init_prec(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(4))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 65;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_next(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(4))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 66;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_left(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(4))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 68;
    keycode[3] = 0;
  }
  return (keycode);
}

char	*init_right(void)
{
  char	*keycode;

  if (keycode = (char*)malloc(4))
  {
    keycode[0] = 27;
    keycode[1] = 91;
    keycode[2] = 67;
    keycode[3] = 0;
  }
  return (keycode);
}
