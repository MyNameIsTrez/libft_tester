/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstlast.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:02:57 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/21 16:47:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_lstlast)
{
	t_list	*lst;

	lst = NULL;

	ft_lst_new_back(&lst, "foo");
	ft_lst_new_back(&lst, "bar");

	t_list *last = ft_lstnew("baz");
	ft_lstadd_back(&lst, last);

	if (lst != NULL AND last != NULL)
		massert((void *)ft_lstlast(lst), (void *)last);
	ft_lstclear(&lst, NULL);
}

////////////////////////////////////////////////////////////////////////////////
