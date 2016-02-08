/*
** philosophe.c for philosophe.c in /home/jacob_f/gitlab/philosophe/new
**
** Made by felix jacob
** Login   <jacob_f@epitech.net>
**
** Started on  Wed Feb 25 13:49:12 2015 felix jacob
** Last update Sun Mar  1 10:28:21 2015 Arthur Poulet
*/

#include <unistd.h>
#include <stdio.h>
#include "philosophe.h"
#include "philosophe_gui.h"

static void		says(t_philo *philo, unsigned int what)
{
  static const char	*sentences[] = {REST_MSG,
					THINK_MSG,
					EAT_MSG,
					AROUND_TABLE_MSG,
					END_THREAD_MSG};

  printf(sentences[what], philo->id, philo->hungry, "\n");
}

static void		eats(t_philo *philo)
{
  philo->status = EAT;
  says(philo, EAT_MSG_ID);
  sleep(philo->handle->time_eat);
  if (philo->food > 0)
    philo->food--;
  pthread_mutex_unlock(&philo->b_left->mutex);
  printf(PUT_LEFT_BAGET, philo->id, philo->b_left->id);
  pthread_mutex_unlock(&philo->b_right->mutex);
  printf(PUT_RIGHT_BAGET, philo->id, philo->b_right->id);
  philo->hungry = philo->handle->default_hungry;
  philo->status = REST;
  says(philo, REST_MSG_ID);
  sleep(philo->handle->time_rest);
}

static void		thinks(t_philo *philo,
			       t_chopstick *chopstick)
{
  philo->status = THINK;
  says(philo, THINK_MSG_ID);
  sleep(philo->handle->time_think);
  while (philo->hungry < philo->handle->max_hungry)
    {
      if (pthread_mutex_trylock(&chopstick->mutex) == 0)
	{
	  if (chopstick == philo->b_left)
	    printf(TAKE_LEFT_BAGET, philo->id, chopstick->id);
	  else
	    printf(TAKE_RIGHT_BAGET, philo->id, chopstick->id);
	  eats(philo);
	  return ;
	}
      sleep(philo->handle->time_think);
      philo->hungry++;
    }
}

void		*start(void *philo_uncast)
{
  t_philo	*philo;

  philo = (t_philo *)philo_uncast;
  says(philo, AROUND_TABLE_MSG_ID);
  says(philo, REST_MSG_ID);
  while (philo->hungry < philo->handle->max_hungry && philo->food != 0)
    {
      if (ID_PAIR && pthread_mutex_trylock(&philo->b_left->mutex) == 0)
	{
	  printf(TAKE_LEFT_BAGET, philo->id, philo->b_left->id);
	  thinks(philo, philo->b_right);
	}
      if (ID_UNPAIR && pthread_mutex_trylock(&philo->b_right->mutex) == 0)
      	{
	  printf(TAKE_RIGHT_BAGET, philo->id, philo->b_right->id);
	  thinks(philo, philo->b_left);
	}
      philo->hungry++;
      if (philo->hungry < philo->handle->max_hungry)
	sleep(philo->handle->time_rest);
    }
  says(philo, END_THREAD_MSG_ID);
  philo->status = LEAVE;
  return (NULL);
}
