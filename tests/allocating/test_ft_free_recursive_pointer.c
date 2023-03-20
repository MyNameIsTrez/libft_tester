/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_free_recursive_pointer.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 16:06:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

typedef struct s_foo
{
	int		x;
	void	*address;
}	t_foo;

Test(ft_free_recursive_pointer)
{
	t_foo	*foo;

	m_safe_malloc_assert(foo = ft_malloc(1, sizeof(t_foo), "test ft_free_recursive_pointer"), false);

	if (!was_malloc_unstable)
	{
		foo->x = 4;
		foo->address = foo;

		ft_free(&foo->address);
	}
}
