/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_vector.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/19 16:27:25 by sbos          #+#    #+#                 */
/*   Updated: 2022/07/20 14:54:48 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_vector)
{
	{
		int	*ints;
		int	v;

		ints = vector_new(sizeof(int));

		vector_reserve(&ints, 1);

		v = 1;
		vector_push(&ints, &v);
		v = 2;
		vector_push(&ints, &v);
		v = 3;
		vector_push(&ints, &v);

		massert(ints[0], 1);
		massert(ints[1], 2);
		massert(ints[2], 3);

		vector_free(ints);
	}
	{
		int	*ints;
		int	v;

		ints = vector_new_reserved(sizeof(int), 1);

		v = 1;
		vector_push(&ints, &v);
		v = 2;
		vector_push(&ints, &v);
		v = 3;
		vector_push(&ints, &v);

		massert(ints[0], 1);
		massert(ints[1], 2);
		massert(ints[2], 3);

		vector_free(ints);
	}
	{
		int	**ints_2d;
		int	*row_0;
		int	*row_1;
		int	v;

		ints_2d = vector_new(sizeof(int *));


		row_0 = vector_new(sizeof(int));
		vector_push(&ints_2d, &row_0);
		v = 1;
		vector_push(&ints_2d[0], &v);
		v = 2;
		vector_push(&ints_2d[0], &v);
		v = 3;
		vector_push(&ints_2d[0], &v);

		massert(ints_2d[0][0], 1);
		massert(ints_2d[0][1], 2);
		massert(ints_2d[0][2], 3);


		row_1 = vector_new(sizeof(int));
		v = 4;
		vector_push(&row_1, &v);
		v = 5;
		vector_push(&row_1, &v);
		v = 6;
		vector_push(&row_1, &v);
		vector_push(&ints_2d, &row_1);

		massert(ints_2d[1][0], 4);
		massert(ints_2d[1][1], 5);
		massert(ints_2d[1][2], 6);


		vector_push_new_vector(&ints_2d, sizeof(int));
		v = 7;
		vector_push(&ints_2d[2], &v);
		v = 8;
		vector_push(&ints_2d[2], &v);
		v = 9;
		vector_push(&ints_2d[2], &v);

		massert(ints_2d[2][0], 7);
		massert(ints_2d[2][1], 8);
		massert(ints_2d[2][2], 9);
	}
	vector_clean_up();
}

////////////////////////////////////////////////////////////////////////////////
