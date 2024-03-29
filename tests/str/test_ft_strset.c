/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strset.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:39:19 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_strset)
{
	massert((void *)ft_strset("foobar", ""), NULL);
	massert((void *)ft_strset("foobar", "x"), NULL);
	massert(ft_strset("foobar", "b"), "bar");
	massert(ft_strset("foobar", "bx"), "bar");
}
