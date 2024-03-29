/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstnew.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:04:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/22 12:03:23 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_lstnew)
{
	char	foo[] = "bar";

	t_list	*lst;
	m_safe_assert(void *, lst = ft_lstnew(foo, "test ft_lstnew"), lst, NULL, true);

	if (lst != NULL)
	{
		massert((char *)lst->content, "bar");
		massert((void *)lst->next, NULL);
	}
}
