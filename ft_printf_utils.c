/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:55:42 by yujung            #+#    #+#             */
/*   Updated: 2021/04/16 16:56:15 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_flag(flag *ps)
{
	ps->align = 0;
	ps->sign = 0;
	ps->zero = 0;
	ps->width = 0;
	ps->dec = -1;
}

int			ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

void		ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

void		ft_makebuf(char **buf, flag *ps)
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
			*buf = ft_strjoin(width, *buf);
		else
			*buf = ft_strjoin(*buf, width);
	}
}