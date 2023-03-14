/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 14:03:53 by thovan-d          #+#    #+#             */
/*   Updated: 2023/03/14 17:09:04 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *placeholders, ...);
int		ft_writeint(int n, int length);
int		ft_writelong(long n, int length);
int		ft_putstr(char *s);
int		ft_cnvrt2hex(unsigned int n);
int		ft_cnvrt2uphex(unsigned int n);
int		ft_cnvrt2p(unsigned long n);

#endif