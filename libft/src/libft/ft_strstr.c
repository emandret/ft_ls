/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:34:51 by emandret          #+#    #+#             */
/*   Updated: 2016/11/27 14:22:09 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int	i;
	unsigned int	pos;
	size_t			len;

	i = 0;
	len = ft_strlen(needle);
	if (len == 0)
		return ((char*)haystack);
	while (haystack[i])
	{
		pos = 0;
		while (needle[pos] == haystack[pos + i])
		{
			if (pos == (len - 1))
				return ((char*)haystack + i);
			pos++;
		}
		i++;
	}
	return (NULL);
}
