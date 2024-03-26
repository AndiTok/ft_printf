/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:31:30 by atok              #+#    #+#             */
/*   Updated: 2022/11/10 11:04:55 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printptr(unsigned long p)
{
	if (p >= 16)
		ft_printptr(p / 16);
	write(1, &"0123456789abcdef"[p % 16], 1);
}

int	ft_ptrlen(unsigned long p)
{
	int	i;

	i = 0;
	while (p != 0)
	{
		p = p / 16;
		i++;
	}
	return (i);
}

int	ft_pointer(unsigned long p)
{
	int	print_len;

	print_len = 0;
	if (p == 0)
		print_len += write (1, "0x0", 3);
	else if (p > 0)
	{
		print_len += write (1, "0x", 2);
		ft_printptr(p);
		print_len += ft_ptrlen(p);
	}
	return (print_len);
}

/* #include <stdio.h> 

int main()
{

  void *a;

  printf("Size - void pointer:%lu",sizeof(a));

  return 0;
}

on a 16 bit machine pointer == 2 byte
32 == 4 byte 
64 == 8 byte */

/* #include <stdio.h>
void    ft_putptr(unsigned long num)
{
    if (num >= 16)
        ft_putptr(num / 16);
    printf("%c" ,"0123456789abcdef"[num % 16]);
}
int main() 
{
  ft_putptr(2736456);
  return 0;
}

conver int to hex */