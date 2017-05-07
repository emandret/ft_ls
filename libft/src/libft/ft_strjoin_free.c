/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:11:17 by emandret          #+#    #+#             */
/*   Updated: 2017/01/12 11:14:22 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(const char *s1, const char *s2)
{
	const char	*tmp;

	tmp = s1;
	s1 = ft_strjoin(s1, s2);
	ft_memdel((void**)&tmp);
	return ((char*)s1);
}
