/*
** free.c for  in /home/poulet_a/rendu/PSU_2014_philo/bonus
**
** Made by Arthur Poulet
** Login   <poulet_a@epitech.net>
**
** Started on  Thu Feb 26 14:42:42 2015 Arthur Poulet
** Last update Thu Feb 26 14:52:11 2015 Arthur Poulet
*/

#include <stdlib.h>
#include "philosophe.h"

void	free_data(t_philo *philo,
		  t_chopstick *chopstick,
		  pthread_t *tab_thread,
		  int ret)
{
  free(chopstick);
  free(philo);
  if (ret == SUCCESS)
    free(tab_thread);
#ifdef BONUS_SDL
  reset_sdl();
#endif
}
