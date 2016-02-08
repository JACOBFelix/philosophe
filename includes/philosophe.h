#ifndef PHILOSOPHE_H_
# define PHILOSOPHE_H_

# include <pthread.h>

/* Configuration */
# define TIME_EAT		2
# define TIME_THINK		1
# define TIME_REST		2
# define NB_PHILO		7
# define DEFAULT_HUNGRY		0
# define MAX_HUNGRY		NB_PHILO * NB_PHILO
# define MAX_FOOD		10
# define ID_PAIR		philo->id % 2 == 0
# define ID_UNPAIR		philo->id % 2 == 1
# define REST_MSG		"Philo %i : rests\n", philo->id
# define THINK_MSG		"Philo %i : thinks\n", philo->id
# define EAT_MSG		"Philo %i : eats\n", philo->id
# define AROUND_TABLE_MSG	"Philo %i : around table\n", philo->id
# define END_THREAD_MSG		"Philo %i : To eat or not to eat\n", philo->id
/* End configuration */

# define FAILURE		1
# define SUCCESS		0

typedef struct s_philo		t_philo;
typedef unsigned int		t_hungry;
typedef pthread_mutex_t		t_chopstick;
typedef unsigned int		t_id;
typedef int			t_food;

struct			s_philo
{
  t_chopstick		*b_left;
  t_chopstick		*b_right;
  t_id			id;
  t_hungry		hungry;
  t_food		food;
};

#endif /* !PHILOSOPHE_H_ */
