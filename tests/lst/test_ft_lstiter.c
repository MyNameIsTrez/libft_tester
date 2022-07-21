/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstiter.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:02:50 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:46:47 by sbos          ########   odam.nl         */
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
	char *str;

	str = strdup("foo");
	m_safe_assert(void *, ft_lst_new_back(&lst, str), ft_lstlast(lst), NULL, false);
	if (was_malloc_unstable)
		ft_free(&str);
	if (NOT was_malloc_unstable)
	{
		str = strdup("bar");
		m_safe_assert(void *, ft_lst_new_back(&lst, str), ft_lstlast(lst), NULL, false);
		if (was_malloc_unstable)
			ft_free(&str);
	}
	if (NOT was_malloc_unstable)
	{
		str = strdup("baz");
		m_safe_assert(void *, ft_lst_new_back(&lst, str), ft_lstlast(lst), NULL, false);
		if (was_malloc_unstable)
			ft_free(&str);
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
