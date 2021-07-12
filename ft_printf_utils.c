#include "ft_printf.h"

int	put_char(char ch)
{
	write(1, &ch, 1);
	return (1);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int	ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int n)
{
	char	*str;
	char	*ret;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (n == 1)
		ret = (char *)s1;
	else if (n == 2)
		ret = (char *)s2;
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free(ret);
	return (str);
}

int	ft_makebuf(char **buf, t_flag *ps)
{
	char	*width;
	char	ch;
	int		j;

	ch = ' ';
	j = 0;
	if (ps->width > ft_strlen(*buf))
	{
		width = malloc(sizeof(char) * ps->width - ft_strlen(*buf) + 1);
		if (ps->zero == 1)
			ch = '0';
		while (j < ps->width - ft_strlen(*buf))
			width[j++] = ch;
		width[j] = '\0';
		if (ps->align == 0)
			*buf = ft_strjoin(width, *buf, 2);
		else
			*buf = ft_strjoin(*buf, width, 1);
		free(width);
		return (ps->width);
	}
	return (ft_strlen(*buf));
}
