/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_numb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/05/27 08:13:13 by emandret         ###   ########.fr       */
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

static int	dispatch(const char **s, va_list ap)
{
	if (**s == '*')
	{
		(*s)++;
		return (va_arg(ap, int));
	}
	return (get_numb(s));
}

void		pf_parse_numb(const char **s, t_format *format, va_list ap)
{
	format->min_field = 0;
	format->precision = 0;
	format->has_precision = FALSE;
	if (ft_isdigit(**s) || **s == '*')
		format->min_field = dispatch(s, ap);
	if (**s == '.')
	{
		(*s)++;
		format->precision = dispatch(s, ap);
		format->has_precision = TRUE;
	}
}
