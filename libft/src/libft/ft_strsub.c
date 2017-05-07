/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:28:44 by emandret          #+#    #+#             */
/*   Updated: 2016/11/22 10:13:33 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if ((new = ft_strnew(len)))
	{
		i = 0;
		while (i < len)
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
