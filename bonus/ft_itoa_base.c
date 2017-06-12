/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 23:44:43 by ariard            #+#    #+#             */
/*   Updated: 2017/02/21 01:19:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		sizeint(long nbr, int base)
{
	int	size;

	size = 0;
	if (nbr < 0 && base == 10)
	{
		size++;
		nbr *= -1;
	}
	else if (nbr < 0) 
		nbr *= -1;
	if (nbr == 0)
		size++;
	while (nbr)
	{
		size++;
		nbr /= base;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	int		ret;
	int		i;
	long	nbr;

	if (base < 2 || base > 16)
		return (NULL);
	size = sizeint(value, base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	nbr = value;
	if (nbr < 0 && base == 10)
		str[0] = '-';
	if (nbr < 0)
		nbr *= -1;
	i = size; 
	str[i] = 0;
	if (nbr == 0)
		str[0] = 48;
	while (nbr)
	{
		if ((ret = nbr % base) < 10)
			str[--i] = ret + 48;
		else
			str[--i] = ret + 55;
		nbr = nbr / base;
	}
	return (str);
}

int	main(void)
{
	int	i = 16;

	printf("16 is %s", ft_itoa_base(i, 2));
	return (0);
}
