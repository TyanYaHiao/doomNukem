/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djast <djast@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:13:07 by fsmith            #+#    #+#             */
/*   Updated: 2019/12/07 17:41:41 by djast            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "editor.h"

uint_least32_t		calculate_crc(char *buf, size_t len)
{
	uint_least32_t	crc_table[256];
	uint_least32_t	crc;
	int				i;
	int				j;

	i = 0;
	while (i < 256)
	{
		crc = i;
		j = 0;
		while (j < 8)
		{
			crc = crc & 1 ? (crc >> 1) ^ 0xEDB88320UL : crc >> 1;
			j++;
		}
		crc_table[i] = crc;
		i++;
	}
	crc = 0xFFFFFFFFUL;
	while (len--)
	{
		crc = crc_table[(crc ^ *buf++) & 0xFF] ^ (crc >> 8);
	}
	return (crc ^ 0xFFFFFFFFUL);
}
