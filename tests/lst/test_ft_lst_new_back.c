/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_new_back.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:56:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 15:21:42 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lst_new_back)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = NULL;

	m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, strdup("foo")), new_lst, NULL, false);
	if (NOT was_malloc_unstable)
	{
		massert((char *)new_lst->content, "foo");
		massert((void *)lst, (void *)new_lst);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, strdup("bar")), new_lst, NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		massert((char *)new_lst->content, "bar");
		massert((void *)lst->next, (void *)new_lst);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, strdup("baz")), new_lst, NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		massert((char *)new_lst->content, "baz");
		massert((void *)lst->next->next, (void *)new_lst);
	}

	ft_lstclear(&lst, &free);
}

////////////////////////////////////////////////////////////////////////////////
