/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:48:24 by emandret          #+#    #+#             */
/*   Updated: 2016/11/27 14:22:01 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	skip(const char *s, char c, unsigned int *i)
{
	while (s[*i] && s[*i] == c)
		(*i)++;
}

static int	count_words(const char *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		skip(s, c, &i);
		if (s[i] && s[i] != c)
		{
			while (s[i] && s[i] != c)
				i++;
			words++;
		}
	}
	return (words);
}

static void	add(char **s, char c)
{
	char	*new;
	char	*tmp;
	size_t	size;

	if (s)
	{
		if (*s)
		{
			size = ft_strlen(*s);
			new = ft_strnew(size + 1);
			new = ft_strcpy(new, *s);
			new[size] = c;
			tmp = *s;
			*s = new;
			ft_memdel((void**)&tmp);
		}
		else
		{
			*s = ft_strnew(1);
			**s = c;
		}
	}
}

char		**ft_strsplit(const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	char			**t;

	t = NULL;
	if ((t = (char**)ft_memalloc(sizeof(char*) * (count_words(s, c) + 1))))
	{
		i = 0;
		j = 0;
		while (s[i])
		{
			skip(s, c, &i);
			if (s[i] && s[i] != c)
			{
				while (s[i] && s[i] != c)
				{
					add(t + j, s[i]);
					i++;
				}
				j++;
				t[j] = NULL;
			}
		}
	}
	return (t);
}
