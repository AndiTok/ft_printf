/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:52:21 by atok              #+#    #+#             */
/*   Updated: 2022/11/10 14:18:35 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	ft_puthex(char h)
{
	write(1, &h, 1);
}

void	ft_10tohex(unsigned int n, const char flag)
{
	if (n >= 16)
		ft_10tohex(n / 16, flag);
	if (flag == 'x')
		write(1, &"0123456789abcdef" [n % 16], 1);
	else if (flag == 'X')
		ft_puthex("0123456789ABCDEF" [n % 16]);
}

int	ft_hex(unsigned int n, const char flag)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_10tohex(n, flag);
	return (hex_len(n));
}

// converting base 10 number to hex like atoi 
// "" = char*
// '' = char
// for memory pointer, it always start with 0x
// ft_10tohex is void ebcase we dont need it to return anything
// ft_hex will return length while ft_10tohex will print it out
// recursion then modulus, will print left to right
// flag parameter will auto pass in x or X becaused is linked from main input 

// apparently in printf C++ %x/%H takes in an unsigned int data type

// if input a neagtive it will retunr a max unsigned long - the amount.
// go beyond that it loops back from the max value and minus from there again.