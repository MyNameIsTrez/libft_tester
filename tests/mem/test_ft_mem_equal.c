/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_mem_equal.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/23 14:11:03 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_mem_equal)
{
	massert(ft_mem_equal("foo", "foo", 4), true);
	massert(ft_mem_equal("doo", "foo", 4), false);
	massert(ft_mem_equal("foo", "doo", 4), false);
	massert(ft_mem_equal("fx", "foo", 4), false);
	massert(ft_mem_equal("f", "foo", 4), false);
}
