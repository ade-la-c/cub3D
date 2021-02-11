/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-la-c <ade-la-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:18:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2020/12/17 17:02:41 by ade-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strlen_gnl(const char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

static char			*ft_strcpy_gnl(char *dest, const char *src)
{
	int	i;

	i = -1;
	if (!src)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char				*ft_strjoin_gnl(char *s1, char *s2, int b)
{
	int				i;
	int				j;
	char			*string;
	char			s1_new[ft_strlen_gnl(s1) + 1];
	char			s2_new[ft_strlen_gnl(s2) + 1];

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdup_gnl(s2));
	ft_strcpy_gnl(s1_new, s1);
	free(s1);
	ft_strcpy_gnl(s2_new, s2);
	if (b == 1)
		free(s2);
	b = ft_strlen_gnl(s1_new) + ft_strlen_gnl(s2_new);
	if (!(string = (char *)malloc(sizeof(char) * (b + 1))))
		return (NULL);
	while (++i < ft_strlen_gnl(s1_new))
		string[i] = s1_new[i];
	while (++j < ft_strlen_gnl(s2_new))
		string[i + j] = s2_new[j];
	string[b] = '\0';
	return (string);
}

char				*ft_strdup_gnl(const char *s1)
{
	int				i;
	char			*string;
	int				size;

	i = 0;
	size = ft_strlen_gnl(s1);
	string = NULL;
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char				*ft_substr_gnl(char *s, int start, int len, char *str)
{
	char			*string;
	int				i;

	i = -1;
	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
	{
		free(str);
		str = NULL;
		return (ft_strdup_gnl(""));
	}
	if (start + len > ft_strlen_gnl(s))
		len = ft_strlen_gnl(s) - start;
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		string[i] = s[start + i];
	free(str);
	str = NULL;
	string[i] = '\0';
	return (string);
}
