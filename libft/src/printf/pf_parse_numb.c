/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_numb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/04/25 20:08:22 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static int	get_numb(const char **s)
{
	int	n;

	n = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
	return (n);
}

void		pf_parse_numb(const char **s, t_format *format)
{
	format->min_field = 0;
	format->precision = 0;
	format->has_precision = FALSE;
	if (ft_isdigit(**s))
		format->min_field = get_numb(s);
	if (**s == '.')
	{
		(*s)++;
		format->precision = get_numb(s);
		format->has_precision = TRUE;
	}
}
