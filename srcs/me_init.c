/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:32:59 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/08 17:32:59 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mapeditor.h>

int		me_init(t_editor *editor)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		me_init_error_handler("video");
	editor->win = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (editor->win == NULL)
		me_init_error_handler("window");
	editor->ren = SDL_CreateRenderer(editor->win, -1, SDL_RENDERER_ACCELERATED);
	if (editor->ren == NULL)
		me_init_error_handler("renderer");
	editor->run = 1;
	return 0;
}
