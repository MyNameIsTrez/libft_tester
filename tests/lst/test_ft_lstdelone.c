/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_lstdelone.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 19:00:21 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 14:57:09 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

static void	free_content(void *content)
{
	ft_free(&content);
}

////////////////////////////////////////////////////////////////////////////////

Test(ft_lstdelone)
{
	char	*foo;
	t_list	*lst;

	foo = ft_malloc(4, sizeof(char));
	if (NOT was_malloc_unstable)
	{
		foo[0] = 'b';
		foo[1] = 'a';
		foo[2] = 'r';
		foo[3] = '\0';

		lst = ft_lstnew(foo);
		if (lst != NULL)
		{
			massert((char *)lst->content, "bar");
			ft_lstdelone(&lst, free_content);
			massert((void *)lst, NULL);
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
