/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:16:54 by yujung            #+#    #+#             */
/*   Updated: 2021/05/05 19:58:05 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_flag(t_flag *ps)
{
	ps->align = 0;
	ps->sign = 0;
	ps->zero = 0;
	ps->width = 0;
	ps->dec = -1;
}

void		check_flag_wigth_dec(char ch, va_list ap, t_flag *ps)
{
	if ('0' <= ch && ch <= '9')
		if (ps->dec == -1)
			ps->width = ps->width * 10 + ch - 48;
		else
			ps->dec = ps->dec * 10 + ch - 48;
	else if (ch == '*')
	{
		if (ps->dec == -1)
		{
			ps->width = va_arg(ap, int);
			if (ps->width < 0)
			{
				if (ps->zero == 1)
					ps->zero = 0;
				ps->align = 1;
				ps->width *= -1;
			}
		}
		else
			ps->dec = va_arg(ap, int);
	}
}

void		check_flag(char ch, va_list ap, t_flag *ps)
{
	if (ch == '-')
		ps->align = 1;
	else if (ch == ' ')
		ps->sign = 1;
	else if (ch == '0' && ps->width == 0 && ps->dec == -1)
		ps->zero = 1;
	else if (ch == '.')
		ps->dec = 0;
	else if (ch == '*' || ('0' <= ch && ch <= '9'))
		check_flag_wigth_dec(ch, ap, ps);
}
