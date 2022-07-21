/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_reverse.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:08:35 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:43:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lst_reverse)
{
	t_list	*lst;

	lst = NULL;

	m_safe_assert(void *, ft_lst_new_back(&lst, "foo"), ft_lstlast(lst), NULL, false);
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "bar"), ft_lstlast(lst), NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "baz"), ft_lstlast(lst), NULL, false);
	}

	if (NOT was_malloc_unstable)
	{
		ft_lst_reverse(&lst);
		massert((char *)lst->content, "baz");
		massert((char *)lst->next->content, "bar");
		massert((char *)lst->next->next->content, "foo");
		massert((void *)lst->next->next->next, NULL);
	}

	ft_lstclear(&lst, NULL);
}

////////////////////////////////////////////////////////////////////////////////
