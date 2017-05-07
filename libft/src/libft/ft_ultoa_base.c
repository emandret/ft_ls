/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:02:47 by emandret          #+#    #+#             */
/*   Updated: 2017/04/17 10:21:04 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_len(uintmax_t n, unsigned int base)
{
	unsigned int	len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

static void			to_string(char **s, unsigned int *i, uintmax_t n,
	unsigned int base)
{
	char	t[16];

	ft_strcpy(t, "0123456789ABCDEF");
	if (n == 0)
		(*s)[0] = '0';
	(*i)--;
	while (n > 0)
	{
		(*s)[*i] = t[n % base];
		n /= base;
		(*i)--;
	}
}

char				*ft_ultoa_base(uintmax_t n, unsigned int base)
{
	char			*s;
	unsigned int	i;

	s = NULL;
	i = get_len(n, base);
	if (base >= 2 && base <= 16 && (s = ft_strnew(i)))
	{
		if (n == 0)
		{
			to_string(&s, &i, n, base);
			return (s);
		}
		to_string(&s, &i, n, base);
	}
	return (s);
}
