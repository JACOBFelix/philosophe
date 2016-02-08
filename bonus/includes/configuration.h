#ifndef CONFIGURATION_H_
# define CONFIGURATION_H_

/*
** begin configuration
*/
# define NB_PHILO		7
# define TIME_EAT		1
# define TIME_THINK		1
# define TIME_REST		1
# define DEFAULT_HUNGRY		0
# define MAX_HUNGRY		handler->nb_philo * handler->nb_philo
# define DEFAULT_FOOD		10
# define ID_PAIR		philo->id % 2 == 0
# define ID_UNPAIR		philo->id % 2 == 1
# define OPT_NB_PHILO		"-philo"
# define OPT_DEFAULT_FOOD	"-default_food"
# define OPT_MAX_HUNGRY		"-max_hungry"
# define OPT_DEFAULT_HUNGRY	"-default_hungry"
# define OPT_TIME_THINK		"-time_think"
# define OPT_TIME_REST		"-time_rest"
# define OPT_TIME_EAT		"-time_eat"
/*
** where %i is the id of the philosophe (must be first)
** where %u is the id of the chopstick (must be the second)
** %s must be at the end of the str
*/
# define REST_MSG		"Philo %i : rests                : %u%s"
# define THINK_MSG		"Philo %i : thinks               : %u%s"
# define EAT_MSG		"Philo %i : eats                 : %u%s"
# define AROUND_TABLE_MSG	"Philo %i : around table         : %u%s"
# define END_THREAD_MSG		"Philo %i : To eat or not to eat : %u %s"
/*
** where the %i is the id of the philosophe
** where the %u is the id of the chopstick
*/
# define PUT_LEFT_BAGET "Philo : %i put his left baget %u on the table\n"
# define PUT_RIGHT_BAGET "Philo : %i put his right baget %u on the table\n"
# define TAKE_LEFT_BAGET "Philo : %i take his left baget %u\n"
# define TAKE_RIGHT_BAGET "Philo : %i take his right baget %u\n"
/*
** end configuration
*/

#endif /* !CONFIGURATION_H_ */
