/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 16:38:23 by emandret          #+#    #+#             */
/*   Updated: 2016/11/22 17:22:50 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	if ((new = ft_memalloc(++size)))
	{
		i = 0;
		while (i < size)
		{
			new[i] = '\0';
			i++;
		}
		return (new);
	}
	return (NULL);
}
