/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:27:35 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/01/31 18:19:33 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *s1, const char *s2)
{
	int		i;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s2[++i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}
