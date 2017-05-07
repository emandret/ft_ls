/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:02:47 by emandret          #+#    #+#             */
/*   Updated: 2017/04/17 10:10:08 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i])
		len += ft_wcharlen(s[i++]);
	return (len);
}
