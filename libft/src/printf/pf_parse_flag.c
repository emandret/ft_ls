/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emandret <emandret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 23:29:31 by emandret          #+#    #+#             */
/*   Updated: 2017/04/25 20:08:04 by emandret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_printf.h"

static void	enable_flag(const char **s, t_format *format)
{
	if (**s == '#' || **s == '0' || **s == '-' || **s == ' ' || **s == '+')
	{
		if (**s == '#')
			format->flags.convert = TRUE;
		if (**s == '0')
			format->flags.zero_padding = TRUE;
		if (**s == '-')
			format->flags.space_right = TRUE;
		if (**s == ' ')
			format->flags.space_left = TRUE;
		if (**s == '+')
			format->flags.enforce_sign = TRUE;
		(*s)++;
		enable_flag(s, format);
	}
}

static void	choose_flag(t_format *format)
{
	if (format->flags.space_right)
		format->flags.zero_padding = FALSE;
	if (format->flags.enforce_sign)
		format->flags.space_left = FALSE;
}

void		pf_parse_flag(const char **s, t_format *format)
{
	format->flags.convert = FALSE;
	format->flags.zero_padding = FALSE;
	format->flags.space_right = FALSE;
	format->flags.space_left = FALSE;
	format->flags.enforce_sign = FALSE;
	enable_flag(s, format);
	choose_flag(format);
}
