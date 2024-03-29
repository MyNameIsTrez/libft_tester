/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_min_int.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:26:34 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_min_int)
{
	massert(ft_min_int(1, 2), 1);
	massert(ft_min_int(2, 2), 2);
	massert(ft_min_int(3, 2), 2);
	massert(ft_min_int(-1, -2), -2);
	massert(ft_min_int(-2, -2), -2);
	massert(ft_min_int(-3, -2), -3);
	massert(ft_min_int(0, -1), -1);
	massert(ft_min_int(0, 0), 0);
}
