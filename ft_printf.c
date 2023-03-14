/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thovan-d <thovan-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:18:02 by thovan-d          #+#    #+#             */
/*   Updated: 2023/02/15 11:48:23 by thovan-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// second find type function
// ~ Further looks for conversions and calls the
//   concerning function of that conversion.

int	ft_findtype2(const char *placeholders, va_list args, int i, int length)
{
	if (placeholders[i] == '%')
	{
		write(1, "%", 1);
		length++;
	}
	else if (placeholders[i] == 'd' || placeholders[i] == 'i')
		length += ft_writeint(va_arg(args, int), 0);
	else if (placeholders[i] == 'u')
		length += ft_writelong(va_arg(args, unsigned int), 0);
	else if (placeholders[i] == 'x')
		length += ft_cnvrt2hex(va_arg(args, int));
	else if (placeholders[i] == 'X')
		length += ft_cnvrt2uphex(va_arg(args, int));
	else if (placeholders[i] == 'p')
	{
		write (1, "0x", 2);
		length += ft_cnvrt2p(va_arg(args, unsigned long)) + 2;
	}
	return (length);
}

// ~ Initialize int x and char *str.
// ~ I check for the possible conversions; if i find one
//   i use the va_arg macro to retrieve the value of 
//   the current var_type, subsequently i write the given type. 
// ~ Incase of conversion c is found, simply print using write.
// ~ incas of conversion s is found call ft_putstr.

int	ft_findtype(const char *placeholders, va_list args, int i, int length)
{
	int		x;
	char	*str;

	if (placeholders[i] == 'c')
	{
		x = va_arg(args, int);
		write(1, &x, 1);
		length++;
	}
	else if (placeholders[i] == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr("(null)");
			length = length + 6;
			return (length);
		}
		length += ft_putstr(str);
	}
	else
		length += ft_findtype2(placeholders, args, i, length);
	return (length);
}

// ~ Initialize the va_list as 'args'.
// ~ Initialize my index i and length, set both to zero.
// ~ Call va_start macros to access the variable arguments.
// ~ Enter the main loop while the variable arguments last.
// ~ Go through the index's and look for a %, check if the 
//   next charachter isnt a \0, if not cal ft_findtype->.
// ~ If there isnt a % just write the placeholder as an
//   char and length++.

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		i;
	int		length;

	length = 0;
	i = 0;
	va_start(args, placeholders);
	while (placeholders[i] != '\0')
	{
		if (placeholders[i] == '%')
		{
			i++;
			if (!placeholders[i])
				return (length);
			length += ft_findtype(placeholders, args, i, 0);
		}
		else
		{
			write(1, &placeholders[i], 1);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}

// int	ft_printf(const char *placeholders, ...);
// int main()
// {

// int a = ft_printf("lets see %i, %%", 10433);
// int b = printf("lets see %i, %%", 10433);

// printf("\n%i %i\n", a, b);

// return (0);
// }