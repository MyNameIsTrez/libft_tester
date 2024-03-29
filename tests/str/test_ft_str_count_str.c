/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_count_str.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 12:44:58 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_count_str)
{
	massert(ft_str_count_str("foo", ""), (size_t)0);
	massert(ft_str_count_str("foo", "o"), (size_t)2);
	massert(ft_str_count_str("fooo", "oo"), (size_t)1);
}
