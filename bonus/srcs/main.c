/*
** main.c for main.c in /home/jacob_f/gitlab/philosophe
**
** Made by felix jacob
** Login   <jacob_f@epitech.net>
**
** Started on  Mon Feb 16 17:42:42 2015 felix jacob
** Last update Sun Mar  1 15:54:14 2015 felix jacob
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
# include "philosophe.h"
#ifdef BONUS_SDL
# include "philosophe_gui.h"
# include "window.h"
#endif

static void		init_philo(t_philo *philo,
				   t_chopstick *left,
				   t_chopstick *right,
				   t_id id)
{
  philo->id = id;
  philo->b_left = left;
  philo->b_right = right;
  philo->food = philo->handle->default_food;
  philo->hungry = philo->handle->default_hungry;
}

static int		init_chopstick(t_chopstick *chopstick, t_id id)
{
  if (pthread_mutex_init(&chopstick->mutex, NULL) != 0)
    return (FAILURE);
  chopstick->id = id;
  return (SUCCESS);
}

static int		init_philo_and_chopstick(t_chopstick chopstick[],
						 t_philo philo[],
						 t_handle *handler)
{
  unsigned int		i;

  i = 0;
  while (i < handler->nb_philo)
    {
      if (init_chopstick(&chopstick[i], i) == FAILURE)
	return (FAILURE);
      i++;
    }
  i = 0;
  while (i < handler->nb_philo)
    {
      philo[i].status = REST;
      philo[i].handle = handler;
#ifdef BONUS_SDL
      philo[i].window = handler->window;
#endif
      init_philo(&philo[i], &chopstick[i],
		 (i == 0 ? &chopstick[handler->nb_philo - 1] :
		  &chopstick[i - 1]), i);
      i++;
    }
  return (SUCCESS);
}

static int		game_init(pthread_t *tab_thread,
				  t_philo *philo,
				  t_handle *handle)
{
  unsigned int		i;
  pthread_t		gui;

  i = 0;
  while (i < handle->nb_philo)
    {
      if (pthread_create(&tab_thread[i], NULL, &start, &philo[i]) != 0)
	{
	  perror(NULL);
	  return (FAILURE);
	}
      i++;
    }
#ifdef BONUS_SDL
  pthread_create(&gui, NULL, &start_gui, philo);
#else
  (void)gui;
#endif
  i = 0;
  while (i < handle->nb_philo)
    pthread_join(tab_thread[i++], NULL);
#ifdef BONUS_SDL
  pthread_join(gui, NULL);
#endif
  return (SUCCESS);
}

int			main(int ac, char **ag)
{
  t_chopstick		*chopstick;
  t_philo		*philo;
  pthread_t		*tab_thread;
  t_handle		handler;
  int			ret;

  handle(&handler, ag, ac);
#ifdef BONUS_SDL
  if ((handler.window = start_sdl()) == NULL)
    return (FAILURE);
#endif
  if (handler.nb_philo == 0 || handler.nb_philo > MAX_NB_THREAD ||
      ((chopstick = malloc(sizeof(t_chopstick) * handler.nb_philo)) == NULL) ||
      ((philo = malloc(sizeof(t_philo) * handler.nb_philo)) == NULL) ||
      ((tab_thread = malloc(sizeof(pthread_t) * handler.nb_philo)) == NULL))
    {
#ifdef BONUS_SDL
      reset_sdl();
#endif
      return (FAILURE);
    }
  ret = (init_philo_and_chopstick(chopstick, philo, &handler) == SUCCESS) ?
    game_init(tab_thread, philo, &handler) : SUCCESS;
  free_data(philo, chopstick, tab_thread, ret);
  return (ret);
}
