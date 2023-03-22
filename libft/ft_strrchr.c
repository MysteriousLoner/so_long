/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:28:24 by leeyang           #+#    #+#             */
/*   Updated: 2022/06/21 22:35:22 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*alts;

	alts = (char *)s;
	i = ft_strlen(s);
	if (c == '\0')
		return (alts + i);
	while (i != 0)
	{
		if (alts[i] == (char)c)
			return (alts + i);
		i--;
	}
	if (s[0] == (char)c)
		return (alts);
	return (0);
}
