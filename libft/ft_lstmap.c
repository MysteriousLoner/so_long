/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeyang <leeyang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:39:58 by leeyang           #+#    #+#             */
/*   Updated: 2022/06/21 15:40:07 by leeyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*nlist;

	head = NULL;
	while (lst != NULL)
	{
		nlist = ft_lstnew(f(lst->content));
		if (nlist == NULL)
			ft_lstclear(&nlist, del);
		else
			ft_lstadd_back(&head, nlist);
		lst = lst->next;
	}
	return (head);
}
