#ifndef PHILOSOPHE_GUI_H_
# define PHILOSOPHE_GUI_H_

# ifdef BONUS_SDL

#  include "window.h"
#  include "philosophe.h"

#  define SDL_TEXT_BUFF_SIZE	64
#  define MINIMUM(a, b)		((a < b) ? (a) : (b))

int		snprintf(char *str, size_t size, const char *format, ...);
int	       	set_philo_sdl_text(t_philo *philo,
				   char *text);
void		*start_gui(void *philo_uncast);

# endif

#endif /* !PHILOSOPHE_GUI_H_ */
