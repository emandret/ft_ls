/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:27:47 by emandret          #+#    #+#             */
/*   Updated: 2016/11/27 14:21:38 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*str;
	size_t		len;

	str = (char*)s;
	len = ft_strlen(s);
	while (len != 0 && str[len] != (char)c)
		len--;
	if (str[len] == (char)c)
		return ((char*)str + len);
	return (NULL);
}
