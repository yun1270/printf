/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:01:40 by yujung            #+#    #+#             */
/*   Updated: 2021/04/16 17:20:25 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_str(char *str, flag *ps)
{
	char	*buf;
	int		buf_len;
	int		i;

	if (str == NULL)
		str = "(null)";
	buf_len = ft_strlen(str);
	if (ps->dec != -1 && ps->dec < buf_len)
		buf_len = ps->dec;
	if (!(buf = malloc(sizeof(char) * buf_len + 1)))
		return (0);
	i = 0;
	while (i < buf_len)
	{
		buf[i] = str[i];
		i++;
	}
	buf[i] = '\0';
	ft_makebuf(&buf, ps);
	ft_putstr(buf);
	free(buf);
	return (ft_strlen(buf));
}

int			print_char(char c, char type, flag *ps)
{
	char	*buf;

	buf = malloc(sizeof(char) * 2);
	buf[0] = c;
	buf[1] = '\0';
	ft_makebuf(&buf, ps);
	ft_putstr(buf);
	free(buf);
	return (ft_strlen(buf));
}
