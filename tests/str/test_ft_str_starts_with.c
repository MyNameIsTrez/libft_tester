/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_starts_with.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:29:46 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_str_starts_with)
{
	massert(ft_str_starts_with("", ""), (bool)true);
	massert(ft_str_starts_with("a", "a"), (bool)true);
	massert(ft_str_starts_with("a", "x"), (bool)false);
	massert(ft_str_starts_with("ab", "a"), (bool)true);
	massert(ft_str_starts_with("abcdef", "abc"), (bool)true);
}

////////////////////////////////////////////////////////////////////////////////
