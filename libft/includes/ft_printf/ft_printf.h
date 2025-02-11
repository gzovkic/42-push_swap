/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gzovkic <gzovkic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:41:35 by gzovkic           #+#    #+#             */
/*   Updated: 2024/11/20 16:08:28 by gzovkic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_printf(const char *format, ...);
int				ft_putnbr_rt(int n);
int				ft_putptr_rt(void *ptr);
int				ft_puthex_rt_lowercase(unsigned long num);
int				ft_puthex_rt_uppercase(unsigned long num);
unsigned int	ft_putudc_rt(unsigned int n);
int				ft_putchar_rt(char c);
int				ft_putstr_rt(char *s);
int				ft_strlen_p(char *s);

#endif