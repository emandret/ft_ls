/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/05 05:40:22 by emandret          #+#    #+#             */
/*   Updated: 2017/06/05 05:42:31 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_chrncpy(char *dest, char c, int n)
{
	int	i;

	if (n < 1)
		return (dest);
	i = 0;
	while (i < (n - 1))
		dest[i++] = c;
	return (dest);
}
