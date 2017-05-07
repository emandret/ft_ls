/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 10:02:47 by emandret          #+#    #+#             */
/*   Updated: 2017/04/17 10:18:39 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	get_len(intmax_t n, unsigned int base)
{
	unsigned int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n /= base)
		len++;
	return (len);
}

static void			to_string(char **s, unsigned int *i, intmax_t n,
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

char				*ft_ltoa_base(intmax_t n, unsigned int base)
{
	char			*s;
	unsigned int	i;
	unsigned int	is_neg;

	s = NULL;
	i = get_len(n, base);
	if (base >= 2 && base <= 16 && (s = ft_strnew(i)))
	{
		if (n == 0)
		{
			to_string(&s, &i, n, base);
			return (s);
		}
		if ((is_neg = (n < 0)))
			n = ABS(n);
		to_string(&s, &i, n, base);
		if (is_neg)
			s[i] = '-';
	}
	return (s);
}
