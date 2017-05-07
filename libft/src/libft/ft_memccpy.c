/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 20:58:52 by emandret          #+#    #+#             */
/*   Updated: 2016/11/27 14:18:52 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*u_dest;
	unsigned char	*u_src;
	unsigned char	x;

	i = 0;
	u_dest = (unsigned char*)dest;
	u_src = (unsigned char*)src;
	x = (unsigned char)c;
	while (i < n)
	{
		if ((u_dest[i] = u_src[i]) == x)
			return (u_dest + i + 1);
		i++;
	}
	return (NULL);
}
