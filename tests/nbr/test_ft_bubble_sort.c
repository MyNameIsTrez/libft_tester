/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_bubble_sort.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:26:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/09/01 16:51:56 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_bubble_sort)
{
	t_i32	arr[] = {2, 1, 3};

	ft_bubble_sort(arr, sizeof(arr) / sizeof(*arr));
	massert(arr[0], 1);
	massert(arr[1], 2);
	massert(arr[2], 3);

	t_i32	arr2[] = {6, 5, 3, 1, 8, 7, 2, 4};

	ft_bubble_sort(arr2, sizeof(arr2) / sizeof(*arr2));
	massert(arr2[0], 1);
	massert(arr2[1], 2);
	massert(arr2[2], 3);
	massert(arr2[3], 4);
	massert(arr2[4], 5);
	massert(arr2[5], 6);
	massert(arr2[6], 7);
	massert(arr2[7], 8);

	t_i32	arr3[] = {2, 1, 3, 6, 5, 8};

	ft_bubble_sort(arr3, sizeof(arr3) / sizeof(*arr3));
	massert(arr3[0], 1);
	massert(arr3[1], 2);
	massert(arr3[2], 3);
	massert(arr3[3], 5);
	massert(arr3[4], 6);
	massert(arr3[5], 8);
}
