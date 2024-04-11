/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:07:55 by syoun             #+#    #+#             */
/*   Updated: 2024/04/05 20:34:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fspecificer (const char *format, va_list args)
{

	int i;
	i = 0;
	if (*format == 'c')
		i += ft_putchar ((char *) args)
	else if (*format == 's')
		i += ft_putstr ((char *) args)
	else if (*format == 'p')
		i += ft_print_ptr_hexa 
	else if (*format == 'd' || *format == 'i')
		i += ft_putnbr ((int) args)
	else if (*format == 'u')
		i +=
	else if (*format == 'x')
		i += ft_hexa ((unsigned int) args)
	else if (*format == 'X')
		i += ft_hexaupp ((unsigned int) args)
	return (i);
}

int ft_printf (const char *format, ...)
{
	va_list args;
	va_start (args, format);
	int	i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (ft_strchr("cspdiuxX%", *format))
				i += ft_fspecifier (format, args);
			else if (*format == '%')
				i += ft_putchar('%');
		}
		else
		{
			i += ft_putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (i);
}
/*
int	main(void)
{
	char *format;
	char *string;
	char character;
	int num;
	int result_ft;
	int result_print;
	// ft_printf(format, 1, 2, 3);

	puts("=== Character: %c ===");
	format = "%c\n";
	character = 'A';
	result_ft = ft_printf(format, character);
	result_print = printf(format, character);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	character = 'B';
	result_ft = ft_printf(format, character);
	result_print = printf(format, character);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("=== String: %s ===");
	format = "%s\n";
	string = NULL;
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	string = "Hello I am a String";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Integer: %d ===");
	format = "%d\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Hexa lower-Cased: %x ===");
	format = "%x\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Hexa UPPER-CASED: %X ===");
	format = "%X\n";
	num = 0;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Multiple-Options (%d%s%X) ===");
	format = "%d%s%X\n";
	string = ": ";
	num = 0;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 42;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -42;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = 2147483647;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	num = -2147483648;
	result_ft = ft_printf(format, num, string, num);
	result_print = printf(format, num, string, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Percent: %% ===");
	format = "%%\n";
	result_ft = ft_printf(format);
	result_print = printf("%%\n");
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n=== Pointer: %p ===");
	format = "%p\n";
	string = NULL;
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	string = "Im a pointer";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	puts("\n=== Not supported Option and normal text: %y ===");
	format = "Im not supported %y\n";
	result_ft = ft_printf(format, string);
	result_print = printf(format, string);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	puts("\n=== Custom Tests ===");
	format = "%d%d\n";
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	format = NULL;
	num = 42;
	result_ft = ft_printf(format, num);
	result_print = printf(format, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
	format = "%c %s %p %d %i %u %x %X %%\n";
	num = 42;
	char c = '4';
	string = "printf";
	result_ft = ft_printf(format, c, string, string, num, num, num, num, num);
	result_print = printf(format, c, string, string, num, num, num, num, num);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);

	puts("\n === Check max Pointer ===");
	format = "%p\n";
	result_ft = ft_printf(format, 18446744073709551615ULL);
	result_print = printf(format, 18446744073709551615ULL);
	printf("Return: ft_printf=%d printf=%d\n\n", result_ft, result_print);
} */