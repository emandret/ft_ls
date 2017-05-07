/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:02:47 by emandret          #+#    #+#             */
/*   Updated: 2017/04/17 10:09:29 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcharlen(wchar_t c)
{
	size_t	len;

	len = 1;
	if (c <= 0x7F)
		return (len);
	if (c > 0x1FFFFF)
		return (0);
	while (c >>= 6)
		len++;
	return (len);
}
