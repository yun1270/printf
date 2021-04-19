/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:12:55 by yujung            #+#    #+#             */
/*   Updated: 2021/04/16 17:20:23 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putbase(long long num, char type, char **buf, int i)
{
	char	*base;
	int		base_num;

	base_num = 16;
	if (type == 'd' || type == 'i' || type == 'u')
		base_num = 10;
	if (type == 'x' || type == 'p')
		base = "0123456789abcdef";
	else if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789";
	if (num >= base_num)
	{
		i = ft_putbase(num / base_num, type, &(*buf), i);
		(*buf)[i++] = base[num % base_num];
	}
	else
		(*buf)[i++] = base[num];
	return (i);
}

int			ft_numlen(char type, long long num)
{
	int		i;

	if (type == 'p' || type == 'x' || type == 'X')
	{
		i = 0;
		while (num > 0)
		{
			num /= 16;
			i++;
		}
		return (i);
	}
	else
	{
		i = 1;
		while (num /= 10)
			i++;
		return (i);
	}
}

int			set_buf(char type, long long num, char **buf, int buf_len)
{
	int		len;
	int		i;

	i = 0;
	len = ft_numlen(type, num);
	buf_len = len;
	if (ps->dec > len)
		buf_len = ps->dec;
	if (!(buf = malloc(sizeof(char) * buf_len + 1)))
		return (0);
	while (ps->dec != -1 && i < ps->dec - len)
		buf[i++] = '0';
	ft_putbase(num, type, &(*buf), i);
	buf[buf_len] = '\0';
	if (type == 'p')
		buf = ft_strjoin("0x", buf);
	return (buf_len);
}

void		put_sign(char type, int buf_len, char **buf, flag *ps)
{
	if ((type == 'd' || type == 'i'))
	{
		if (buf_len < ps->width && ps->zero == 1)
		{
			if (ps->sign == -1)
				buf[0] = '-';
			else if (ps->sign == 1)
				buf[0] = ' ';
		}
		else
		{
			if (ps->sign == -1)
				buf = ft_strjoin(" ", buf);
			else if (ps->sign == 1)
				buf = ft_strjoin(" ", buf);
		}
	}
}

int			print_num(long long num, char type, flag *ps)
{
	char	*buf;
	int		buf_len;

	if ((type == 'd' || type == 'i') && (num < 0))
	{
		num *= -1;
		if (ps->sign == 1)
			ps->sign = -1;
	}
	buf_len = set_buf(type, num, &buf, buf_len);
	ft_makebuf(&buf, ps);
	put_sign(type, buf_len, &buf, ps);
	ft_putstr(buf);
	free(buf);
	return (ft_strlen(buf));
}
