/*
** load.c for load.c in /home/jacob_f/gitlab/philosophe/new
**
** Made by felix jacob
** Login   <jacob_f@epitech.net>
**
** Started on  Wed Feb 25 15:03:43 2015 felix jacob
** Last update Wed Feb 25 18:25:40 2015 Arthur Poulet
*/

#include <stdlib.h>
#include "philosophe.h"

void		load_nb_philo(t_handle *handle, char *str)
{
  handle->nb_philo = atoi(str);
}

void		load_default_food(t_handle *handle, char *str)
{
  handle->default_food = (t_hungry)atoi(str);
}

void		load_max_hungry(t_handle *handle, char *str)
{
  handle->max_hungry = (t_hungry)atoi(str);
}

void		load_default_hungry(t_handle *handle, char *str)
{
  handle->default_hungry = (t_hungry)atoi(str);
}

void		load_time_think(t_handle *handle, char *str)
{
  handle->time_think = (t_time)atoi(str);
}
