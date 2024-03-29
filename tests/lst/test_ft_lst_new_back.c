/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_new_back.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:56:02 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:42:37 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_lst_new_back)
{
	t_list	*lst;
	t_list	*new_lst;

	lst = NULL;

	m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, "foo", "test ft_lst_new_back 1"), new_lst, NULL, false);
	if (!was_malloc_unstable)
	{
		massert((char *)new_lst->content, "foo");
		massert((void *)lst, (void *)new_lst);
	}

	if (!was_malloc_unstable)
	{
		m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, "bar", "test ft_lst_new_back 2"), new_lst, NULL, false);
	}
	if (!was_malloc_unstable)
	{
		massert((char *)new_lst->content, "bar");
		massert((void *)lst->next, (void *)new_lst);
	}

	if (!was_malloc_unstable)
	{
		m_safe_assert(void *, new_lst = ft_lst_new_back(&lst, "baz", "test ft_lst_new_back 3"), new_lst, NULL, false);
	}
	if (!was_malloc_unstable)
	{
		massert((char *)new_lst->content, "baz");
		massert((void *)lst->next->next, (void *)new_lst);
	}

	ft_lstclear(&lst, NULL);
}
