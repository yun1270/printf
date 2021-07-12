#include "ft_printf.h"

int	print_str(char *str, t_flag *ps)
{
	char	*buf;
	int		buf_len;
	int		len;
	int		i;

	if (str == NULL)
		str = "(null)";
	buf_len = ft_strlen(str);
	if (ps->dec != -1 && ps->dec < buf_len && ps->dec >= 0)
		buf_len = ps->dec;
	buf = malloc(sizeof(char) * buf_len + 1);
	if (!buf)
		return (0);
	i = 0;
	while (i < buf_len)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	len = ft_makebuf(&buf, ps);
	ft_putstr(buf);
	free(buf);
	return (len);
}

int	put_width_char(int i, t_flag *ps)
{
	int	j;

	j = 0;
	while (j < ps->width - i)
	{
		if (ps->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		j++;
	}
	return (j + 1);
}

int	print_char(char c, char type, t_flag *ps)
{
	int		len;

	if (type == '%' && ps->align == 1)
		ps->zero = 0;
	if (ps->align == 1)
		write(1, &c, 1);
	len = put_width_char(1, ps);
	if (ps->align == 0)
		write(1, &c, 1);
	return (len);
}
