/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakombo- <yakombo-@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 22:25:44 by yakombo-          #+#    #+#             */
/*   Updated: 2026/04/30 22:26:06 by yakombo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp_new;

	if (!f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		tmp_new = ft_lstnew(f(lst->content));
		if (!tmp_new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp_new);
		lst = lst->next;
	}
	return (new);
}
