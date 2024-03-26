/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 12:03:45 by atok              #+#    #+#             */
/*   Updated: 2022/11/14 16:52:28 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formatflags(const char flag, va_list args)
{
	int	print_len;

	print_len = 0;
	if (flag == 'c')
		print_len += ft_putchar(va_arg(args, int));
	else if (flag == 's')
		print_len += ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		print_len += ft_pointer(va_arg(args, unsigned long));
	else if (flag == 'd' || flag == 'i')
		print_len += ft_number(va_arg(args, int));
	else if (flag == 'u')
		print_len += ft_unsigned(va_arg(args, unsigned int));
	else if (flag == 'x' || flag == 'X')
		print_len += ft_hex(va_arg(args, unsigned int), flag);
	else if (flag == '%')
		print_len += ft_percent();
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		print_len;

	print_len = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != 0x00)
	{
		if (str[i] == '%')
		{
			print_len += ft_formatflags(str[i + 1], args);
			i++;
		}
		else
		{
			print_len = ft_putchar(str[i]) + print_len;
		}
		i++;
	}
	va_end(args);
	return (print_len);
}

/* #include <stdio.h>  */

/* int main (void)
{
	ft_printf("%%");
	write(1, "\n", 1);
	printf("%%");
	write(1, "\n", 1);	
} */

/*  int main (void)
{
	ft_printf("%x", -4294967298);
	ft_printf("\n");
	ft_printf("%x", -1);
	write(1, "\n", 1);
	printf("%x", 1);
	printf("\n");
	printf("%x", -1);
} */

/* int main (void)
{
	int n = -42;
	int p = 42;

	ft_printf("\tft\nnegative - %u\nposotive - %u",n,p);
	ft_printf("\n");
	printf("\tnft\nnegative - %u\npositive - %u",n,p);
	printf("\n");
} */

/* int main (void)
{
//	int i = 10;
	ft_printf("%d",0);// d or i
	ft_printf("\n");
	printf("%d",0);
	printf("\n");
} */

/* int main (void)
{
	static char str [] = "test";
//	static char str = 0;	

//	printf("%d",ft_printf(str));
	ft_printf("%p",str);// p
	printf("\n");
	printf("%p",str);
	printf("\n");
	return (0);
} */

/* int main (void)
{
	char str[] = "hello world";
	ft_printf("%s",str);// s
	return (0);
} */

/* int main ()
{
	ft_printf("%c","0123456789abcdef"[10]);// c
} */

/* int main (int argc , char **argv)
{
	if (argc == 2)
	ft_putchar(*argv[1]);
} */

/* ft_putchar (man)
writes the character c 
(single ascii character) 
(converted to an ``unsigned char'')
to std output */