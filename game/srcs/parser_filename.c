/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_filename.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eharrag- <eharrag-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 16:52:15 by fsmith            #+#    #+#             */
/*   Updated: 2019/12/08 15:47:30 by eharrag-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <engine.h>

void		parser_filename_error(void)
{
	ft_putendl("Parsing error:");
	ft_putendl("More than one map!");
	ft_putendl("Usage: './doom_nukem [map_name without .lvl and folders]'");
	close_game(READING_ERROR);
}

void		parser_filename(t_engine *eng, int argc, char **argv)
{
	if (argc == 1)
		eng->map_name = ft_strdup(GAME_PATH);
	else if (argc == 2)
	{
		eng->map_name = ft_strnew(ft_strlen(argv[1]) +
				ft_strlen("game/resources/levels/") + ft_strlen(".lvl"));
		eng->map_name = ft_strcat(eng->map_name, "game/resources/levels/");
		eng->map_name = ft_strcat(eng->map_name, argv[1]);
		eng->map_name = ft_strcat(eng->map_name, ".lvl");
		eng->edit = false;
	}
	else if (argc == 3 && !ft_strcmp(argv[2], "--edit"))
	{
		eng->map_name = ft_strnew(ft_strlen(argv[1]) +
				ft_strlen("game/resources/levels/") + ft_strlen(".lvl"));
		eng->map_name = ft_strcat(eng->map_name, "game/resources/levels/");
		eng->map_name = ft_strcat(eng->map_name, argv[1]);
		eng->map_name = ft_strcat(eng->map_name, ".lvl");
		eng->edit = true;
	}
	else
		parser_filename_error();
}
