/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_memcmp.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 16:02:06 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_memcmp)
{
	massert(ft_memcmp("foo", "foo", 4), 0);
	massert(ft_memcmp("doo", "foo", 4), 'd' - 'f');
	massert(ft_memcmp("foo", "doo", 4), 'f' - 'd');
	massert(ft_memcmp("fx", "foo", 4), 'x' - 'o');
	massert(ft_memcmp("f", "foo", 4), '\0' - 'o');
}
