/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstadd_front.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:20:41 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/05 18:21:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_lstadd_front)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;

	m_safe_assert(void *, new = ft_lstnew("foo", "test ft_lstadd_front 1"), new, NULL, false);
	if (!was_malloc_unstable)
	{
		ft_lstadd_front(&lst, new);
		m_safe_assert(void *, new = ft_lstnew("foo", "test ft_lstadd_front 2"), new, NULL, false);
	}
	if (!was_malloc_unstable)
	{
		ft_lstadd_front(&lst, new);
		massert(ft_lstsize(lst), (size_t)2);
	}

	ft_lstclear(&lst, NULL);
}
