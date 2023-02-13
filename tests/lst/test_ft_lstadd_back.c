/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstadd_back.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:16:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/05 18:19:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lstadd_back)
{
	t_list	*lst;
	t_list	*new;

	lst = NULL;

	m_safe_assert(void *, new = ft_lstnew("foo"), new, NULL, false);
	if (!was_malloc_unstable)
	{
		ft_lstadd_back(&lst, new);
		m_safe_assert(void *, new = ft_lstnew("foo"), new, NULL, false);
	}
	if (!was_malloc_unstable)
	{
		ft_lstadd_back(&lst, new);
		massert(ft_lstsize(lst), (size_t)2);
	}

	ft_lstclear(&lst, NULL);
}

////////////////////////////////////////////////////////////////////////////////
