/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapeditor.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 14:45:38 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/08 17:32:15 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

#include <libft.h>
#include <SDL2/SDL.h>

# define SCREEN_WIDTH		1024
# define SCREEN_HEIGHT		768
# define SCREEN_TITLE		"Map editor"
# define ERROR_CODE_INIT	42

typedef struct		s_editor
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event 		event;
	int 			run;
}					t_editor;

int		main(int argc, char **argv);
void	rules(void);
int		me_init(t_editor *editor);
void	me_quit(t_editor *editor);

void 	me_init_error_handler(char *reason);

void	me_keyboard_handler(t_editor *editor);
# endif
