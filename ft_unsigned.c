/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atok <atok@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 17:28:17 by atok              #+#    #+#             */
/*   Updated: 2022/11/10 11:05:14 by atok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	unsignedint_len(unsigned int n)
{
	int		len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_ustrdup(const char *src)
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

char	*ft_uint_itoa(unsigned int n)
{
	char	*str;
	int		i;

	if (n == 0)
		return (ft_ustrdup("0"));
	i = unsignedint_len(n);
	str = (char *) malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = 0x00;
	i--;
	while (n != 0)
	{
		str[i] = '0' + (n % 10);
		i--;
		n = n / 10;
	}
	return (str);
}

int	ft_unsigned(unsigned int n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_uint_itoa(n);
	while (str[i] != 0x00)
	{
		write(1, &str[i], 1);
		i++;
	}
	free (str);
	return (i);
}

/* basically same as int but without the sign '-' */