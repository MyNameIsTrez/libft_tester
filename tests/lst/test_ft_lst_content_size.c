/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lst_content_size.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:37:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:41:47 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

typedef size_t	(*t_size_fn)(const void *);

////////////////////////////////////////////////////////////////////////////////

Test(ft_lst_content_size)
{
	t_list	*lst;

	lst = NULL;

	massert(ft_lst_content_size(lst, (t_size_fn) &(ft_strlen)), (size_t)0);

	m_safe_assert(void *, ft_lst_new_back(&lst, "foo"), ft_lstlast(lst), NULL, false);
	if (NOT was_malloc_unstable)
	{
		massert(ft_lst_content_size(lst, (t_size_fn) &(ft_strlen)), (size_t)3);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "bar"), ft_lstlast(lst), NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		massert(ft_lst_content_size(lst, (t_size_fn) &(ft_strlen)), (size_t)6);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, "baz"), ft_lstlast(lst), NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		massert(ft_lst_content_size(lst, (t_size_fn) &(ft_strlen)), (size_t)9);
	}

	ft_lstclear(&lst, NULL);
}

////////////////////////////////////////////////////////////////////////////////
