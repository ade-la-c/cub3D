/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 14:48:45 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/27 16:53:58 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;
	char			*str;

	ch = (unsigned char)c;
	i = -1;
	str = (char*)b;
	while (++i < n)
		str[i] = ch;
	return ((void*)str);
}
