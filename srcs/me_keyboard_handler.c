/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me_keyboard_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:30:14 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/08 17:30:14 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mapeditor.h>

void	me_keyboard_handler(t_editor *editor)
{
	if (SDL_PollEvent(&editor->event))
	{
		if (editor->event.type == SDL_KEYDOWN)
		{
			if (editor->event.key.keysym.sym == SDLK_ESCAPE)
			{
				editor->run = 0;
			}
		}
	}
}
