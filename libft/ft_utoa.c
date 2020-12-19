/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:35:30 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/10/23 17:58:57 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(unsigned long long n)
{
	int size;

	size = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char		*ft_utoa(unsigned long long n)
{
	int					size;
	char				*nbr;

	size = 0;
	size += get_size(n);
	if (!(nbr = ft_calloc(1, sizeof(char) * (size + 1))))
		return (NULL);
	size--;
	while (size >= 0)
	{
		nbr[size] = (n % 10) + 48;
		size--;
		n = n / 10;
	}
	return (nbr);
}
