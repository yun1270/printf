/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:57:13 by yujung            #+#    #+#             */
/*   Updated: 2021/04/16 17:19:14 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_type(const char *s, int i)
{
	if (s[i] == 's' || s[i] == 'c' || s[i] == 'd'
		|| s[i] == 'i' || s[i] == 'x' || s[i] == 'X'
		|| s[i] == 'u' || s[i] == 'p' || s[i] == '%')
		return (1);
	return (0);
}

void		check_flag(char ch, va_list ap, flag *ps)
{
	if (ch == '0' && ps->width == 0 && ps->dec == -1)
		ps->zero = 1;
	else if (ch == '-')
		ps->align = 1;
	else if (ch == ' ')
		ps->sign = 1;
	else if (ch == '.')
		ps->dec = 0;
	else if (ch == '*' || ('0' <= ch && ch <= '9'))
	{
		if ('0' <= ch && ch <= '9')
			if (ps->dec == -1)
				ps->width = ps->width * 10 + ch - 48;
			else
				ps->dec = ps->dec * 10 + ch - 48;
		else if (ch == '*')
		{
			if (ps->dec == -1)
				ps->width = va_arg(ap, int);
			else
				ps->dec = va_arg(ap, int);
		}
	}
}

int			print_type(char type, va_list ap, flag *ps)
{
	int		len;

	len = 0;
	if (type == 's')
		len += print_str(va_arg(ap, char *), ps);
	else if (type == 'c')
		len += print_char(va_arg(ap, int), type, ps);
	else if (type == 'd' || type == 'i')
		len += print_num(va_arg(ap, int), type, ps);
	else if (type == 'x' || type == 'X' || type == 'u')
		len += print_num(va_arg(ap, unsigned int), type, ps);
	else if (type == 'p')
		len += print_num(va_arg(ap, unsigned long long), type, ps);
	else if (type == '%')
		len += print_char('%', type, ps);
	return (len);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	flag	*ps;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, s);
	if (!(ps = malloc(sizeof(flag) * 1)))
		return (-1);
	while (s[i])
	{
		if (s[i] == '%')
		{
			set_flag(ps);
			while (s[i] && check_type(s, ++i) == 0)
				check_flag(s[i], ap, ps);
			len += print_type(s[i++], ap, ps);
		}
		else
		{
			write(1, &s[i++], 1);
			len++;
		}
	}
	free(ps);
	va_end(ap);
	return ();
}
