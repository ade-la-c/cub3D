/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 16:37:12 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/01/27 16:22:45 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2 || !(str = (malloc(sizeof(char)
	* (ft_strlen(s1) + ft_strlen(s2) + 1)))))
		return (NULL);
	*str = '\0';
	return (ft_strcat(ft_strcpy(str, s1), s2));
}
