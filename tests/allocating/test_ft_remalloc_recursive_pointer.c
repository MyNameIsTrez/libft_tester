/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_remalloc_recursive_pointer.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 17:16:07 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

typedef struct s_foo
{
	int		x;
	void	*address;
}	t_foo;

Test(ft_remalloc_recursive_pointer)
{
	t_foo	*foo;

	m_safe_malloc_assert(foo = ft_malloc(1, sizeof(t_foo), "test ft_remalloc_recursive_pointer 1"), false);

	if (!was_malloc_unstable)
	{
		foo->x = 4;
		foo->address = foo;

		t_foo	*new_foo;
		m_safe_malloc_assert(new_foo = ft_remalloc(&foo->address, 2), false);

		if (!was_malloc_unstable)
		{
			new_foo[1].x = 2;
			new_foo[1].address = (void *)0x42;

			massert(new_foo[1].x, 2);
			massert(new_foo[1].address, (void *)0x42);
		}
		else
		{
			massert(foo->x, 4);
			massert(foo->address, (void *)foo);
		}
	}
}
