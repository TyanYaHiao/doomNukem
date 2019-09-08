/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   me_errors_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsmith <fsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:01:20 by fsmith            #+#    #+#             */
/*   Updated: 2019/09/08 17:06:14 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mapeditor.h>

void 	me_init_error_handler(char *reason)
{
	ft_putendl("Init error!");
	ft_putstr("Cannot init ");
	ft_putstr(reason);
	ft_putendl("!");
	exit(ERROR_CODE_INIT);
}
