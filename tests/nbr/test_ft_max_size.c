/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_max_size.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:21:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_max_size)
{
	massert(ft_max_size(1, 2), (size_t)2);
	massert(ft_max_size(2, 2), (size_t)2);
	massert(ft_max_size(3, 2), (size_t)3);
	massert(ft_max_size(0, 0), (size_t)0);
}
