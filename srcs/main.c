#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "philosophe.h"

static void		eats(t_philo *philo)
{
  printf(EAT_MSG);
  sleep(TIME_EAT);
  if (philo->food > 0)
    philo->food--;
  pthread_mutex_unlock(philo->b_left);
  pthread_mutex_unlock(philo->b_right);
  philo->hungry = DEFAULT_HUNGRY;
  printf(REST_MSG);
  sleep(TIME_REST);
}

static void		thinks(t_philo *philo,
			       pthread_mutex_t *mutex)
{
  printf(THINK_MSG);
  sleep(TIME_THINK);
  while (philo->hungry < MAX_HUNGRY)
    {
      if (pthread_mutex_trylock(mutex) == 0)
	{
	  eats(philo);
	  return ;
	}
      sleep(TIME_THINK);
      philo->hungry++;
    }
}

static void		*start(void *philo_uncast)
{
  t_philo		*philo;

  philo = (t_philo *)philo_uncast;
  printf(AROUND_TABLE_MSG);
  printf(REST_MSG);
  while (philo->hungry++ < MAX_HUNGRY && philo->food != 0)
    {
      if (ID_PAIR && pthread_mutex_trylock(philo->b_left) == 0)
	thinks(philo, philo->b_right);
      if (ID_UNPAIR && pthread_mutex_trylock(philo->b_right) == 0)
      	thinks(philo, philo->b_left);
      sleep(TIME_THINK);
    }
  printf(END_THREAD_MSG);
  return (NULL);
}

static void		init_philo(t_philo *philo,
				   t_chopstick *left,
				   t_chopstick *right,
				   t_id id)
{
  philo->id = id;
  philo->b_left = left;
  philo->b_right = right;
  philo->food = MAX_FOOD;
  philo->hungry = DEFAULT_HUNGRY;
}

int			main()
{
  t_chopstick		chopstick[NB_PHILO];
  t_philo		philo[NB_PHILO];
  pthread_t		tab_thread[NB_PHILO];
  int			i;

  i = -1;
  while (++i < NB_PHILO)
    chopstick[i] = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
  i = -1;
  while (++i < NB_PHILO)
    init_philo(&philo[i], &chopstick[i],
	       (i == 0 ? &chopstick[NB_PHILO - 1] : &chopstick[i - 1]), i);
  i = -1;
  while (++i < NB_PHILO)
    if (pthread_create(&tab_thread[i], NULL, &start, &philo[i]) != 0)
      {
	perror(NULL);
	return (FAILURE);
      }
  i = -1;
  while (++i < NB_PHILO)
    pthread_join(tab_thread[i], NULL);
  return (SUCCESS);
}
