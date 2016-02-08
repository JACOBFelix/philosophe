#ifndef WINDOW_H_
# define WINDOW_H_

# ifdef BONUS_SDL

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <string.h>

# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define SCREEN_BPP 32

# define RED 0xff0000
# define GREEN 0x00ff00
# define BLUE 0x0000ff
# define WHITE RED | GREEN | BLUE
# define BLACK 0x000000

# define FONT_COLOR_R 0xff
# define FONT_COLOR_G 0xff
# define FONT_COLOR_B 0xff

# define FONT_FILE "arial.ttf"
# define FONT_SIZE 20
# define CAPTION "Philosophe"

struct s_window
{
  SDL_Surface	*screen;
  SDL_Event	event;
  TTF_Font	*font;
  SDL_Color	fontColor;
  unsigned int	fontSize;
};
typedef struct s_window t_window;

void		add_surface(t_window* window,
			    SDL_Surface* surface,
			    int x,
			    int y);
SDL_Surface	*write_text(t_window* window,
			    char *text,
			    int x,
			    int y);
void		reset_sdl();
t_window	*start_sdl();

# endif /* !BONUS_SDL */

#endif /* !WINDOW_H_ */
