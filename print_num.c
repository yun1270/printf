#include "ft_printf.h"

int	ft_numlen(char type, long long num, t_flag *ps)
{
	int		i;
	int		base;

	base = 10;
	if (type == 'p' || type == 'x' || type == 'X')
		base = 16;
	if (num == 0 && ps->dec != 0)
		return (1);
	i = 0;
	while (num)
	{
		i++;
		num /= base;
	}
	return (i);
}

int	put_sign(int buf_len, char **buf, t_flag *ps)
{
	int		ret;

	ret = 0;
	if (ps->zero == 1)
	{
		if (buf_len >= ps->width)
		{
			if (ps->sign == -1)
			{
				*buf = ft_strjoin("-", *buf, 2);
				ret = 1;
			}
			else if (ps->sign == 1)
				*buf = ft_strjoin(" ", *buf, 2);
		}
		else if (buf_len < ps->width)
		{
			if (ps->sign == -1)
				*buf[0] = '-';
			else if (ps->sign == 1)
				*buf[0] = ' ';
		}
	}
	return (ret);
}

int	ft_putbase(long long num, char type, char **buf, int i)
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

void	put_buf(char **buf, t_flag *ps, long long num, char type)
{
	int		i;

	i = 0;
	while (ps->dec != -1 && i < ps->dec - ft_numlen(type, num, ps))
		(*buf)[i++] = '0';
	if (num == 0 && ps->dec == 0)
		(*buf)[i] = 0;
	else
		ft_putbase(num, type, &(*buf), i);
	if ((type == 'd' || type == 'i') && ps->zero == 0)
	{
		if (ps->sign == -1)
			*buf = ft_strjoin("-", *buf, 2);
		else if (ps->sign == 1)
			*buf = ft_strjoin(" ", *buf, 2);
	}
	if (type == 'p')
		*buf = ft_strjoin("0x", *buf, 2);
}

int	print_num(long long num, char type, t_flag *ps)
{
	char	*buf;
	int		len;
	int		buf_len;

	if ((type == 'd' || type == 'i') && (num < 0))
	{
		num *= -1;
		ps->sign = -1;
	}
	buf_len = ft_numlen(type, num, ps);
	if (ps->dec > buf_len)
		buf_len = ps->dec;
	buf = malloc(sizeof(char) * buf_len + 1);
	if (!buf)
		return (0);
	buf[buf_len] = '\0';
	put_buf(&buf, ps, num, type);
	len = ft_makebuf(&buf, ps);
	len += put_sign(buf_len, &buf, ps);
	ft_putstr(buf);
	free(buf);
	return (len);
}
