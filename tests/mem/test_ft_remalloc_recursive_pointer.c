/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_remalloc_recursive_pointer.c               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/12 16:28:28 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

typedef struct s_foo
{
	int		x;
	void	*address;
}	t_foo;

Test(ft_remalloc_recursive_pointer)
{
	t_foo	*foo;

	m_safe_malloc_assert(foo = ft_malloc(1, sizeof(t_foo)), false);

	if (NOT was_malloc_unstable)
	{
		foo->x = 4;
		foo->address = foo;

		if (malloc_call_count_to_fail == 171)
			massert(foo->address, (void *)foo);

		t_foo	*new_foo;
		m_safe_malloc_assert(new_foo = ft_remalloc(&foo->address, 1, 2, sizeof(t_foo)), false);
		if (malloc_call_count_to_fail == 171)
			massert(foo->address, (void *)foo);

		if (NOT was_malloc_unstable)
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

////////////////////////////////////////////////////////////////////////////////
