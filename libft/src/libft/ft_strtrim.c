/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 09:58:44 by emandret          #+#    #+#             */
/*   Updated: 2016/11/27 14:22:25 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim(const char *s)
{
	int	i;

	i = 0;
	while (ft_isblanks(s[i]))
		i++;
	return (i);
}

static int	rtrim(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (ft_isblanks(s[i]))
		i--;
	return (i);
}

char		*ft_strtrim(const char *s)
{
	char	*new;
	int		size;
	int		srt;
	int		end;

	srt = trim(s);
	end = rtrim(s);
	if ((size = ++end - srt) < 1)
		size = 1;
	if ((new = ft_strnew(size)))
	{
		size = 0;
		while (srt < end)
			new[size++] = s[srt++];
		return (new);
	}
	return (NULL);
}
