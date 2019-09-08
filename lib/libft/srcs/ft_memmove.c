/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:42:41 by zytrams           #+#    #+#             */
/*   Updated: 2019/08/30 20:08:29 by fsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*buff;

	buff = (char *)malloc(len);
	if (buff)
	{
		ft_memcpy(buff, src, len);
		ft_memcpy(dst, buff, len);
	}
	free(buff);
	return (dst);
}
