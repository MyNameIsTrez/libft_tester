/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_max.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 17:21:43 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_max)
{
	massert(ft_max(1, 2), 2);
	massert(ft_max(2, 2), 2);
	massert(ft_max(3, 2), 3);
	massert(ft_max(-1, -2), -1);
	massert(ft_max(-2, -2), -2);
	massert(ft_max(-3, -2), -2);
	massert(ft_max(0, -1), 0);
	massert(ft_max(0, 0), 0);
}

////////////////////////////////////////////////////////////////////////////////
