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

#include "libft_tests.h"

Test(ft_lstclear)
{
	t_list	*lst;

	lst = NULL;

	char *str = strdup("foo");
	if (ft_lst_new_back(&lst, str, "test ft_lstclear 1") == NULL)
		ft_free(&str);
	str = strdup("bar");
	if (ft_lst_new_back(&lst, str, "test ft_lstclear 2") == NULL)
		ft_free(&str);
	str = strdup("baz");
	if (ft_lst_new_back(&lst, str, "test ft_lstclear 3") == NULL)
		ft_free(&str);

	ft_lstclear(&lst, &free);
	massert((void *)lst, NULL);
}

Test(ft_lstclear_null)
{
	t_list	*lst;

	lst = NULL;

	ft_lst_new_back(&lst, "foo", "test ft_lstclear_null 1");
	ft_lst_new_back(&lst, "bar", "test ft_lstclear_null 2");
	ft_lst_new_back(&lst, "baz", "test ft_lstclear_null 3");

	ft_lstclear(&lst, NULL);
	// TODO: I don't know how to assert that the content is still allocated
	massert((void *)lst, NULL);
}
