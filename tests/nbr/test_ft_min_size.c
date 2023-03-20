/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_min_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:26:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_min_size)
{
	massert(ft_min_size(1, 2), (size_t)1);
	massert(ft_min_size(2, 2), (size_t)2);
	massert(ft_min_size(3, 2), (size_t)2);
	massert(ft_min_size(0, 0), (size_t)0);
}
