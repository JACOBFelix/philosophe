/*
** window.c for  in /home/poulet_a/rendu/PSU_2014_philo
**
** Made by Arthur Poulet
** Login   <poulet_a@epitech.net>
**
** Started on  Thu Feb 26 08:28:33 2015 Arthur Poulet
** Last update Fri Feb 27 14:17:00 2015 Arthur Poulet
*/

#ifdef BONUS_SDL

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <string.h>
# include "window.h"

static int	init_sdl(t_window *window)
{
  window->screen = SDL_SetVideoMode(SCREEN_WIDTH,
				    SCREEN_HEIGHT,
				    SCREEN_BPP,
				    SDL_SWSURFACE);
  if (window->screen == NULL)
    return (1);
  if (TTF_Init() == -1)
    {
      printf("Cannot initialize SDL_TTF\n");
      return (2);
    }
  if ((window->font = TTF_OpenFont(FONT_FILE, FONT_SIZE)) == NULL)
    {
      printf("Cannort read %s with size %i\n", FONT_FILE, FONT_SIZE);
      return (3);
    }
  window->fontSize = FONT_SIZE;
  SDL_WM_SetCaption(CAPTION, NULL);
  window->fontColor.r = FONT_COLOR_R;
  window->fontColor.g = FONT_COLOR_G;
  window->fontColor.b = FONT_COLOR_B;
  return (0);
}

void	 add_surface(t_window* window,
		     SDL_Surface* surface,
		     int x,
		     int y)
{
  SDL_Rect	offset;

  if (window == NULL || window->screen == NULL || surface == NULL)
    return ;
  offset.x = x;
  offset.y = y;
  SDL_BlitSurface(surface, NULL, window->screen, &offset);
}

SDL_Surface	*write_text(t_window* window,
			    char *text,
			    int x,
			    int y)
{
  SDL_Surface	*message;

  message = TTF_RenderText_Solid(window->font, text, window->fontColor);
  if (message == NULL)
    return (NULL);
  add_surface(window, message, x, y);
  return (message);
}

void		reset_sdl()
{
  if (start_sdl() == NULL)
    return ;
  SDL_FreeSurface(start_sdl()->screen);
  TTF_CloseFont(start_sdl()->font);
  TTF_Quit();
  SDL_Quit();
}

t_window		*start_sdl()
{
  static t_window	*window = NULL;
  int			err;

  if (window == NULL)
    {
      if ((window = malloc(sizeof(t_window))) == NULL)
	return (NULL);
      if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
	  printf("Failed to initialize SDL\n");
	  return (NULL);
	}
      atexit(SDL_Quit);
      if ((err = init_sdl(window)) != 0)
	return (NULL);
    }
  return (window);
}

#endif
