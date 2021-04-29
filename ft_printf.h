/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujung <yujung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:58:49 by yujung            #+#    #+#             */
/*   Updated: 2021/04/28 13:32:02 by yujung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_flag
{
	int			align;
	int			sign;
	int			zero;
	int			width;
	int			dec;
}				t_flag;

/*
*********ft_printf.c*********
*/
void			set_flag(t_flag *ps);
int				ft_printf(const char *s, ...);
int				check_type(const char *s, int i);
void			check_flag(char ch, va_list ap, t_flag *ps);
int				print_type(char type, va_list ap, t_flag *ps);
/*
*********ft_printf_utils.c*********
*/
int				put_char(char ch);
void			ft_putstr(char *s);
int				ft_strlen(const char *s);
char			*ft_strjoin(char const *s1, char const *s2);
int				ft_makebuf(char **buf, t_flag *ps);
/*
*********print_num.c*********
*/
int				ft_numlen(char type, long long num);
int				put_sign(int len, int buf_len, char **buf, t_flag *ps);
int				ft_putbase(long long num, char type, char **buf, int i);
long long		check_sign(char type, long long num, t_flag *ps);
int				print_num(long long num, char type, t_flag *ps);
/*
*********print_char_str.c*********
*/
int				print_str(char *str, t_flag *ps);
int				print_char(char c, char type, t_flag *ps);

#endif
