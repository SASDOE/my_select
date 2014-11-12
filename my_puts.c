/*
** utils.c for my_select in /home/sebastien/travaux/my_select
**
** Made by sebastien
** Login   <sebastien@epitech.net>
**
** Started on  Tue Jan 14 17:32:39 2014 sebastien
** Last update Thu Jan 16 15:28:46 2014 sebastien
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_select.h"

int	puterror(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return (-1);
  while (str[i])
    write(2, &str[i++], 1);
  return (-1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
    return ;
  while (str[i])
    write(1, &str[i++], 1);
}

void	my_tputs(char *str)
{
  int	i;

  i = 0;
  if (str == NULL)
  {
    puterror("error: problem with tgetstr or tgoto\n");
    exit(EXIT_FAILURE);
  }
  while (str[i])
    write(fd_tty, &str[i++], 1);
}

void	my_putchar(char c)
{
  write(fd_tty, &c, 1);
}

void	my_putnbr(int n)
{
  if (n < 0)
  {
    my_putchar('-');
    n = -n;
  }
  if (n >= 10)
    my_putnbr(n / 10);
  my_putchar((n % 10) + '0');
}
