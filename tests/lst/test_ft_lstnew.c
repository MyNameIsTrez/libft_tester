/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstnew.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:04:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lstnew)
{
	char	foo[] = "bar";

	t_list	*lst;
	m_safe_assert(void *, lst = ft_lstnew(foo), lst, NULL);

	if (lst != NULL)
	{
		massert((char *)lst->content, "bar");
		massert((void *)lst->next, NULL);

		ft_free(&lst);
	}
}

////////////////////////////////////////////////////////////////////////////////
