/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zytrams <zytrams@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 09:42:32 by zytrams           #+#    #+#             */
/*   Updated: 2019/06/08 20:41:41 by zytrams          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int		ft_countwords(char const *s, char c)
{
	int			cnt;
	const char	*l_comma;
	const char	*tmp;
	int			f;

	tmp = s;
	l_comma = 0;
	cnt = 0;
	f = 0;
	while (*tmp)
	{
		if (*tmp == c && f == 0)
		{
			cnt++;
			f = 1;
			l_comma = tmp;
		}
		else if (*tmp != c && f == 1)
			f = 0;
		tmp++;
	}
	cnt += l_comma < (s + ft_strlen(s) - 1);
	cnt++;
	return (cnt);
}

static char		*ft_cutword(char const *s, char c, size_t i)
{
	char	*word;
	size_t	end;
	size_t	l;

	l = 0;
	end = i + 1;
	while (s[end] && s[end] != c)
		end++;
	word = (char *)ft_strnew(end - i);
	if (word == NULL)
		return (NULL);
	while (s[i] && i < end)
	{
		word[l++] = s[i];
		i++;
	}
	return (word);
}

static void		ft_putnull(char **res, int cnt)
{
	if (cnt > 1)
	{
		free(res[cnt - 1]);
		res[cnt - 1] = NULL;
	}
	else
	{
		free(res[cnt]);
		res[cnt] = NULL;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		cnt;
	int		words;
	size_t	i;

	if (s)
	{
		i = 0;
		cnt = 0;
		words = ft_countwords(s, c);
		res = (char **)ft_memalloc(sizeof(char **) * words);
		if (res == NULL)
			return (NULL);
		while (words-- > 0)
		{
			while (s[i] && s[i] == c)
				i++;
			res[cnt++] = ft_cutword(s, c, i);
			while (s[i] && s[i] != c)
				i++;
		}
		ft_putnull(res, cnt);
		return (res);
	}
	return (NULL);
}
