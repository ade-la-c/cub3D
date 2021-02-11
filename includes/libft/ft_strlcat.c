/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:01:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 14:38:51 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	res;

	i = ft_strlen(dst);
	res = ft_strlen(src);
	if (size <= i)
		res += size;
	else
		res += i;
	j = 0;
	while (src[j] && i + 1 < size)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (res);
}
