/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygorget <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:55:45 by ygorget           #+#    #+#             */
/*   Updated: 2024/10/16 12:05:05 by ygorget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*new;
	void	*tmp;

	newlst = NULL;
	new = NULL;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		tmp = f(lst->content);
		if (tmp)
			new = ft_lstnew(tmp);
		if (new == NULL || tmp == NULL)
		{
			if (tmp)
				del(tmp);
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, new);
		lst = lst->next;
	}
	return (newlst);
}
