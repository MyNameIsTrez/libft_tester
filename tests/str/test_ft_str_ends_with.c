/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_ends_with.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:29:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_ends_with)
{
	massert(ft_str_ends_with("", ""), (bool)true);
	massert(ft_str_ends_with("a", "a"), (bool)true);
	massert(ft_str_ends_with("a", "x"), (bool)false);
	massert(ft_str_ends_with("ab", "b"), (bool)true);
	massert(ft_str_ends_with("abcdef", "def"), (bool)true);
}
