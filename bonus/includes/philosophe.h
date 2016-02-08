#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include <pthread.h>
# include "configuration.h"
# ifdef BONUS_SDL
#  include "window.h"
# endif

# define FAILURE		1
# define SUCCESS		0

# define SIZE_MENU		7

# define REST_MSG_ID		0
# define THINK_MSG_ID		1
# define EAT_MSG_ID		2
# define AROUND_TABLE_MSG_ID	3
# define END_THREAD_MSG_ID	4

# define MAX_NB_THREAD		496
# define AROUND			AROUND_MSG_ID
# define REST			REST_MSG_ID
# define THINK			THINK_MSG_ID
# define EAT			EAT_MSG_ID
# define LEAVE			END_THREAD_MSG_ID

typedef unsigned int		t_hungry;
typedef unsigned int		t_time;
typedef unsigned int		t_id;
typedef int			t_food;
typedef unsigned int		t_status;
typedef struct s_philo		t_philo;
typedef struct s_chopstick	t_chopstick;
typedef struct s_handle		t_handle;
typedef struct s_menu		t_menu;

struct			s_philo
{
  t_id			id;
  t_hungry		hungry;
  t_food	        food;
  t_status		status;
  t_handle		*handle;
# ifdef BONUS_SDL
  t_window		*window;
# endif
  t_chopstick		*b_left;
  t_chopstick		*b_right;
};

struct			s_chopstick
{
  pthread_mutex_t	mutex;
  t_id			id;
};

struct			s_handle
{
  unsigned int		nb_philo;
  t_food		default_food;
  t_hungry		max_hungry;
  t_hungry		default_hungry;
  t_time		time_think;
  t_time		time_rest;
  t_time		time_eat;
# ifdef BONUS_SDL
  t_window		*window;
# endif
};

struct			s_menu
{
  char			*str;
  void			(*fptr)(t_handle *, char *);
};

void    *start(void *);
void	handle(t_handle *, char **, int);

void	load_nb_philo(t_handle *, char *);
void	load_default_food(t_handle *, char *);
void    load_max_hungry(t_handle *, char *);
void	load_default_hungry(t_handle *, char *);
void	load_time_think(t_handle *, char *);

void	free_data(t_philo *philo,
		  t_chopstick *chopstrick,
		  pthread_t *tab_thread,
		  int ret);

#endif /* !PHILOSOPHE_H_ */
