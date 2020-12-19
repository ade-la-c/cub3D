/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 11:14:32 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/23 15:03:55 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = -1;
	if (!c)
		return ((char*)s + ft_strlen(s));
	str = (char*)s;
	while (str[++i])
		if (c == str[i])
			return (&str[i]);
	return (NULL);
}
