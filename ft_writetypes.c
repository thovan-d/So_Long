/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writetypes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:43:41 by thovan-d          #+#    #+#             */
/*   Updated: 2023/02/15 11:51:55 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// ~ when wanting to write a string: loop through
//   s and write the character up untill '\0'
//   returning the length at tehe end.

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

// Write an Integer
// ~ hardcode for if n == -2147483648 (int_min).
// ~ check if n < 0: if so write "-", make n positive
//   and up the length by one (for the "-")
// ~ incase if n < 10 just use write.
// ~ if n >= 10 use recursion to write the int ->
//   devides the number by 10 untill its writable as 1 character
//   then uses modulo to regain the other numbers and write those.

int	ft_writeint(int n, int length)
{
	char	c;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		n = n * -1;
		length++;
	}
	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		length++;
	}
	if (n >= 10)
	{
		length += ft_writeint (n / 10, 0);
		length += ft_writeint (n % 10, 0);
	}
	return (length);
}

// Write unsigned long
// ~ This function works identical to write int
//   except we dont have to hardcode the int min
//   and check for negative value.

int	ft_writelong(long n, int length)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		write(1, &c, 1);
		length++;
	}
	if (n >= 10)
	{
		length += ft_writeint (n / 10, 0);
		length += ft_writeint (n % 10, 0);
	}
	return (length);
}
