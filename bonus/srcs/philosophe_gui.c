/*
** philosophe_gui.c for  in /home/poulet_a/rendu/PSU_2014_philo/new
**
** Made by Arthur Poulet
** Login   <poulet_a@epitech.net>
**
** Started on  Wed Feb 25 23:14:48 2015 Arthur Poulet
** Last update Fri Feb 27 11:31:55 2015 felix jacob
*/

#ifdef BONUS_SDL

# include "philosophe.h"
# include "philosophe_gui.h"
# include "window.h"

int		set_philo_sdl_text(t_philo *philo, char *text)
{
  SDL_Surface	*sdl_black;
  SDL_Surface	*sdl_text;

  sdl_black = SDL_CreateRGBSurface(0, SCREEN_WIDTH,
				   philo->window->fontSize + 1,
				   32, 0, 0, 0, 0);
  if (sdl_black == NULL)
    return (1);
  add_surface(philo->window, sdl_black, 1,
	      philo->id * philo->window->fontSize + 1);
  SDL_FreeSurface(sdl_black);
  sdl_text = write_text(philo->window,
			text, 1,
			philo->id * philo->window->fontSize + 1);
  SDL_FreeSurface(sdl_text);
  SDL_Flip(philo->window->screen);
  return (0);
}

void			*start_gui(void *philo_uncast)
{
  t_philo		*philos;
  int			i;
  unsigned int		deads;
  char			sdl_text[SDL_TEXT_BUFF_SIZE];
  static const char	*sentences[] = {REST_MSG,
					THINK_MSG,
					EAT_MSG,
					AROUND_TABLE_MSG,
					END_THREAD_MSG};

  philos = (t_philo *)philo_uncast;
  i = 0;
  deads = 0;
  while (deads != philos[0].handle->nb_philo)
    {
      if (philos[0].status == LEAVE)
	deads++;
      else
	deads = 0;
      snprintf(sdl_text, SDL_TEXT_BUFF_SIZE,
	       sentences[philos[i].status], philos[i].id, philos[i].hungry, " ");
      set_philo_sdl_text(&philos[i], sdl_text);
      i = (i + 1) % philos[0].handle->nb_philo;
    }
  return (NULL);
}

#endif
