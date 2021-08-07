/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsailor <bsailor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 17:31:08 by bsailor           #+#    #+#             */
/*   Updated: 2021/04/21 18:20:47 by bsailor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;

	if (lst == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	len = ft_lstsize(lst);
	while (--len)
		lst = lst->next;
	return (lst);
}
