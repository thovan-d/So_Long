/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:22:30 by thovan-d          #+#    #+#             */
/*   Updated: 2023/02/15 11:48:44 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// length of hex
// ~ plus x while n / 16 isnt 0 to find the 
//  length of the str.

int	ft_lengthhex(unsigned long n)
{
	int	x;

	x = 0;
	while (n != 0)
	{
		x++;
		n = n / 16;
	}
	return (x);
}

// ft_fillstr (conversion to hex)
// ~ initialize i, set to 0.
// ~ loop while n / 16 != 0: within this loop
//   set i equal to n mod 16 to find the position 
//   within the hex string to convert the numer.

char	*ft_fillstr(char *hex, char *str, unsigned long n, int len)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i = n % 16;
		str[len] = hex[i];
		n = n / 16;
		len--;
	}
	return (str);
}

// Convert to uppercase hex
// ~ functions the same as conversion for normal hex,
//   except the function accepts unsigned longs.

int	ft_cnvrt2p(unsigned long n)
{	
	char	*hex;
	char	*str;
	int		x;
	int		len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = "0123456789abcdef";
	len = ft_lengthhex(n);
	x = len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[len] = '\0';
	len--;
	str = ft_fillstr(hex, str, n, len);
	ft_putstr(str);
	free(str);
	return (x);
}

// Convert to uppercase hex
// ~ functions the same as conversion for normal hex,
//   except the string is all in upper case.

int	ft_cnvrt2uphex(unsigned int n)
{	
	char	*hex;
	char	*str;
	int		x;
	int		len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = "0123456789ABCDEF";
	len = ft_lengthhex(n);
	x = len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[len] = '\0';
	len--;
	str = ft_fillstr(hex, str, n, len);
	ft_putstr(str);
	free(str);
	return (x);
}

// Convert to hex
// ~ Check if n == 0, if so just write 0
// ~ declare *hex as "0123456789abcdef" to use for
//   the convertion.
// ~ set int len = ft_lengthhex to findout how long the string
//   needs to be, set x (return value) = len.
// ~ malloc str using len, protect and set str[len] = '\0';
// ~ call ft_filstr to convert the int to hexidecimal, set
//   the return equal to str so we can print this.
// ~ free str to prevent leaks.

int	ft_cnvrt2hex(unsigned int n)
{	
	char	*hex;
	char	*str;
	int		x;
	int		len;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	hex = "0123456789abcdef";
	len = ft_lengthhex(n);
	x = len;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == 0)
		return (0);
	str[len] = '\0';
	len--;
	str = ft_fillstr(hex, str, n, len);
	ft_putstr(str);
	free(str);
	return (x);
}
