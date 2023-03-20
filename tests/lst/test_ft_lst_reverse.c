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

#include "libft_tests.h"

Test(ft_lst_reverse)
{
	t_list	*lst;

	lst = NULL;

	m_safe_assert(void *, ft_lst_new_back(&lst, "foo", "test ft_lst_reverse 1"), ft_lstlast(lst), NULL, false);
	if (!was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "bar", "test ft_lst_reverse 2"), ft_lstlast(lst), NULL, false);
	}
	if (!was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "baz", "test ft_lst_reverse 3"), ft_lstlast(lst), NULL, false);
	}

	if (!was_malloc_unstable)
	{
		ft_lst_reverse(&lst);
		massert((char *)lst->content, "baz");
		massert((char *)lst->next->content, "bar");
		massert((char *)lst->next->next->content, "foo");
		massert((void *)lst->next->next->next, NULL);
	}

	ft_lstclear(&lst, NULL);
}
