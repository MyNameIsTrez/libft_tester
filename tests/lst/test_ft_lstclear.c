/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstclear.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:59:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:45:02 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lstclear)
{
	t_list	*lst;

	lst = NULL;

	char *str = strdup("foo");
	if (ft_lst_new_back(&lst, str) == NULL)
		ft_free(&str);
	str = strdup("bar");
	if (ft_lst_new_back(&lst, str) == NULL)
		ft_free(&str);
	str = strdup("baz");
	if (ft_lst_new_back(&lst, str) == NULL)
		ft_free(&str);

	ft_lstclear(&lst, &free);
	massert((void *)lst, NULL);
}

Test(ft_lstclear_NULL)
{
	t_list	*lst;

	lst = NULL;

	ft_lst_new_back(&lst, "foo");
	ft_lst_new_back(&lst, "bar");
	ft_lst_new_back(&lst, "baz");

	ft_lstclear(&lst, NULL);
	massert((void *)lst, NULL);
}

////////////////////////////////////////////////////////////////////////////////
