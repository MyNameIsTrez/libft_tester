/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_push_new_vector.c                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/02 14:20:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/02 14:23:34 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_push_new_vector)
{
	int	**ints_2d;
	int	v;

	m_safe_assert(void *, ints_2d = ft_vector_new(sizeof(int *)), ints_2d, NULL, false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(t_status, ft_vector_push_new_vector(&ints_2d, sizeof(int)), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 1;
		m_safe_assert(t_status, ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 2;
		m_safe_assert(t_status, ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 3;
		m_safe_assert(t_status, ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert(ints_2d[0][0], 1);
		massert(ints_2d[0][1], 2);
		massert(ints_2d[0][2], 3);
	}
}
