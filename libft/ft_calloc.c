/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalee <yalee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:37:26 by leeyang           #+#    #+#             */
/*   Updated: 2022/06/22 22:47:29 by yalee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*x;

	if (nitems >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	x = malloc(size * nitems);
	if (!x)
		return (0);
	ft_bzero (x, nitems * size);
	return (x);
}
