/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_new_reserved.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:24:37 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/26 17:07:41 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_new_reserved)
{
	int	*ints;
	int	v;

	m_safe_assert(void *, ints = ft_vector_new_reserved(sizeof(int), 1), ints, NULL, false);

	if (NOT was_malloc_unstable)
	{
		v = 1;
		m_safe_assert(int, (int)ft_vector_push(&ints, &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 2;
		m_safe_assert(int, (int)ft_vector_push(&ints, &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 3;
		m_safe_assert(int, (int)ft_vector_push(&ints, &v), OK, ERROR, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert(ints[0], 1);
		massert(ints[1], 2);
		massert(ints[2], 3);
	}

	ft_vector_free(&ints);
	massert((void *)ints, NULL);
}

Test(ft_vector_new_reserved_empty)
{
	massert(ft_vector_new_reserved(sizeof(int), 0), NULL);
}

////////////////////////////////////////////////////////////////////////////////
