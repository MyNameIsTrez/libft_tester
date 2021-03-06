/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector_2d.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/29 20:25:04 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/29 20:25:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector_2d)
{
	int	**ints_2d;
	int	*row_0;
	int	*row_1;
	int	v;

	m_safe_assert(void *, ints_2d = ft_vector_new(sizeof(int *)), ints_2d, NULL, false);

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, row_0 = ft_vector_new(sizeof(int)), row_0, NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(int, (int)ft_vector_push(&ints_2d, &row_0), OK, ERROR, false);
	}

	// WARNING:
	// "ft_vector_push(&row_0, &v);" doesn't work since whenever row_0
	// is realloced, ints_2d wouldn't be aware row_0 its address moved

	if (NOT was_malloc_unstable)
	{
		v = 1;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 2;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 3;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[0], &v), OK, ERROR, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert(ints_2d[0][0], 1);
		massert(ints_2d[0][1], 2);
		massert(ints_2d[0][2], 3);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(void *, row_1 = ft_vector_new(sizeof(int)), row_1, NULL, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 4;
		m_safe_assert(int, (int)ft_vector_push(&row_1, &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 5;
		m_safe_assert(int, (int)ft_vector_push(&row_1, &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 6;
		m_safe_assert(int, (int)ft_vector_push(&row_1, &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		m_safe_assert(int, (int)ft_vector_push(&ints_2d, &row_1), OK, ERROR, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert(ints_2d[1][0], 4);
		massert(ints_2d[1][1], 5);
		massert(ints_2d[1][2], 6);
	}

	if (NOT was_malloc_unstable)
	{
		m_safe_assert(int, (int)ft_vector_push_new_vector(&ints_2d, sizeof(int)), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 7;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[2], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 8;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[2], &v), OK, ERROR, false);
	}
	if (NOT was_malloc_unstable)
	{
		v = 9;
		m_safe_assert(int, (int)ft_vector_push(&ints_2d[2], &v), OK, ERROR, false);
	}

	if (NOT was_malloc_unstable)
	{
		massert(ints_2d[2][0], 7);
		massert(ints_2d[2][1], 8);
		massert(ints_2d[2][2], 9);
	}

	// ft_vector_free(&ints_2d);
}

////////////////////////////////////////////////////////////////////////////////
