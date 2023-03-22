/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:40:44 by yalee             #+#    #+#             */
/*   Updated: 2023/03/22 11:55:53 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*dest;
	int		joinlen;
	int		i;
	int		j;

	i = 0;
	joinlen = ft_strlen1(s1) + ft_strlen1(s2);
	dest = malloc(sizeof(char) * (joinlen + 1));
	if (!dest || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[joinlen] = '\0';
	return (dest);
}

char	*check_s(char *str, int sep)
{
	int		i;

	i = 0;
	while (str[i] != sep && str[i] != '\0')
		i++;
	if (str[i] == sep)
		return (&str[i]);
	else
		return (NULL);
}
