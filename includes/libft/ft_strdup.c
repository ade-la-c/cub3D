/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:04:17 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/27 16:44:46 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	size;
	char	*s2;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	if (!(s2 = (malloc(sizeof(char) * size + 1))))
		return (NULL);
	return (ft_strcpy(s2, s1));
}
