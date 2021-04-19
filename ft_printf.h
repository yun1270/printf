/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:58:49 by yujung            #+#    #+#             */
/*   Updated: 2021/04/18 14:58:39 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_flag
{
	int	align;
	int	sign;
	int	zero;
	int	width;
	int	dec;
}			flag;

/*
*********ft_printf.c*********
*/
int		ft_printf(const char *s, ...);
int		check_type(const char *s, int i);
void	check_flag(char ch, va_list ap, flag *ps);
int		print_type(char type, va_list ap, flag *ps);

/*
*********ft_printf_utils.c*********
*/
void	set_flag(flag *ps);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_makebuf(char **buf, flag *ps);
void	ft_putstr(char *s);

/*
*********print_num.c*********
*/
int		ft_numlen(int num);
int		set_buf(char type, long long num, char **buf, int buf_len);
void	put_sign(char type, int buf_len, char **buf, flag *ps);
int		ft_putbase(long long num, char type, char **buf, int i);
int		print_num(long long num, char type, flag *ps);

/*
*********print_char_str.c*********
*/
int		print_str(char *str, flag *ps);
int		print_char(char c, char type, flag *ps);

#endif
