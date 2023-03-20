/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstsize.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 17:26:44 by sbos          #+#    #+#                 */
/*   Updated: 2022/02/05 18:19:15 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_lstsize)
{
	t_list	*lst;

	lst = NULL;

	m_safe_assert(void *, ft_lst_new_front(&lst, "foo", "test ft_lstsize 1"), lst, NULL, false);
	if (!was_malloc_unstable)
		m_safe_assert(void *, ft_lst_new_front(&lst, "foo", "test ft_lstsize 2"), lst, NULL, false);

	if (!was_malloc_unstable)
		massert(ft_lstsize(lst), (size_t)2);

	ft_lstclear(&lst, NULL);
}
