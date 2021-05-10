/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:57:13 by yujung            #+#    #+#             */
/*   Updated: 2021/05/11 00:41:29 by yujung           ###   ########.fr       */
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

int			print_type(char type, va_list ap, t_flag *ps)
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
	else
		return (-1);
	return (len);
}

int			check_and_print(const char *s, va_list ap, t_flag *ps)
{
	int		i;
	int		len;
	int		n;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			set_flag(ps);
			while (s[++i] && check_type(s, i) == 0)
				check_flag(s[i], ap, ps);
			if ((ps->align == 1 || ps->dec > -1))
				ps->zero = 0;
			if ((n = print_type(s[i], ap, ps)) != -1)
			{
				len += n;
				i++;
			}
		}
		else
			len += put_char(s[i++]);
	}
	return (len);
}

int			ft_printf(const char *s, ...)
{
	va_list	ap;
	t_flag	*ps;
	int		len;

	va_start(ap, s);
	if (!(ps = malloc(sizeof(t_flag) * 1)))
		return (-1);
	len = check_and_print(s, ap, ps);
	free(ps);
	va_end(ap);
	return (len);
}
