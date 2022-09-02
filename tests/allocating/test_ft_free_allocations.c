/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_free_allocations.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:47:23 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/25 14:40:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_free_allocations)
{
	ft_free_allocations();
}

Test(ft_free_allocations_double)
{
	ft_free_allocations();
	ft_free_allocations();
}

Test(ft_free_allocations_double_around)
{
	ft_free_allocations();

	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new(sizeof(int)), ints, NULL, false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(t_status, ft_vector_reserve(&ints, 1), OK, ERROR, false);
	}

	int i = 0;
	while (i < 1000)
	{
		if (NOT was_malloc_unstable)
		{
			v = i;
			m_safe_assert(t_status, ft_vector_push(&ints, &v), OK, ERROR, false);
			if (NOT was_malloc_unstable)
				massert(ints[i], i);
		}
		i++;
	}

	ft_free_allocations();
}

////////////////////////////////////////////////////////////////////////////////
