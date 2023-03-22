/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeyang <leeyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:30:59 by leeyang           #+#    #+#             */
/*   Updated: 2022/06/21 15:31:24 by leeyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*rm;

	tmp = *lst;
	while (tmp != NULL)
	{
		rm = tmp->next;
		del(tmp->content);
		free(tmp);
		tmp = rm;
	}
	*lst = NULL;
}
