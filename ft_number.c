/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:22:02 by atok              #+#    #+#             */
/*   Updated: 2022/11/14 16:58:07 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	int_len(int n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_strdup(const char *src)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0x00)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0x00;
	return (dup);
}

char	*ft_int_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	i = int_len(n);
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = 0x00;
	i--;
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		str[i] = '0' + (n % 10);
		i--;
		n = n / 10;
	}
	return (str);
}

int	ft_number(int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_int_itoa(n);
	while (str[i] != 0x00)
	{
		write(1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}

/* need to malloc to create an empty string
cannot str = 0; */
/* why itoa? becase we are passing in an int and printing it out as char
and some time we may need to handle the '-' */