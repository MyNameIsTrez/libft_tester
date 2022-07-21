/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstiter.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:02:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 15:21:36 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

static void foo(void *content)
{
	char *s = content;
	s[0] = 'x';
}

Test(ft_lstiter)
{
	t_list	*lst;

	lst = NULL;

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, strdup("foo")), ft_lstlast(lst), NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, strdup("bar")), ft_lstlast(lst), NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, ft_lst_new_back(&lst, strdup("baz")), ft_lstlast(lst), NULL, false);
	}


	if (NOT was_malloc_unstable)
	{
		ft_lstiter(lst, foo);
		massert((char *)lst->content, "xoo");
		massert((char *)lst->next->content, "xar");
		massert((char *)lst->next->next->content, "xaz");
		massert((void *)lst->next->next->next, NULL);
	}

	ft_lstclear(&lst, &free);
}

////////////////////////////////////////////////////////////////////////////////
