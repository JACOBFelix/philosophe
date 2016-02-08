/*
** handle.c for handle.c in /home/jacob_f/gitlab/philosophe/new
**
** Made by felix jacob
** Login   <jacob_f@epitech.net>
**
** Started on  Wed Feb 25 14:22:55 2015 felix jacob
** Last update Sat Feb 28 23:03:57 2015 felix jacob
*/

#include <string.h>
#include <stdlib.h>
#include "philosophe.h"

static void		load_time_rest(t_handle *handle, char *str)
{
  handle->time_rest = (t_time)atoi(str);
}

static void		load_time_eat(t_handle *handle, char *str)
{
  handle->time_eat = (t_time)atoi(str);
}

static int		check_nbr(char *str)
{
  int			i;

  if (!str)
    return (FAILURE);
  i = -1;
  while (str[++i])
    if (str[i] < '0' || str[i] > '9')
      return (FAILURE);
  return (SUCCESS);
}

void			check_arg(t_handle *handle,
				  const t_menu menu[],
				  char **ag,
				  int ac)
{
  int			i;
  int			j;

  i = 0;
  while (ag[++i] && i <= ac)
    {
      j = -1;
      while (++j < SIZE_MENU)
	if (ag[i] && check_nbr(ag[i + 1]) == SUCCESS
	    && strcmp(ag[i], menu[j].str) == 0)
	  {
	    menu[j].fptr(handle, ag[i + 1]);
	    i += 2;
	    j = -1;
	  }
    }
}

void			handle(t_handle *handler,
			       char **ag,
			       int ac)
{
  t_menu		menu[SIZE_MENU];

  menu[0].str = OPT_NB_PHILO;
  menu[0].fptr = &load_nb_philo;
  menu[1].str = OPT_DEFAULT_FOOD;
  menu[1].fptr = &load_default_food;
  menu[2].str = OPT_MAX_HUNGRY;
  menu[2].fptr = &load_max_hungry;
  menu[3].str = OPT_DEFAULT_HUNGRY;
  menu[3].fptr = &load_default_hungry;
  menu[4].str = OPT_TIME_THINK;
  menu[4].fptr = &load_time_think;
  menu[5].str = OPT_TIME_REST;
  menu[5].fptr = &load_time_rest;
  menu[6].str = OPT_TIME_EAT;
  menu[6].fptr = &load_time_eat;
  handler->nb_philo = NB_PHILO;
  handler->default_food = DEFAULT_FOOD;
  handler->max_hungry = MAX_HUNGRY;
  handler->default_hungry = DEFAULT_HUNGRY;
  handler->time_think = TIME_THINK;
  handler->time_rest = TIME_REST;
  handler->time_eat = TIME_EAT;
  check_arg(handler, menu, ag, ac);
}
