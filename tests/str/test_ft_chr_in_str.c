/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_chr_in_str.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/22 12:55:29 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/22 13:38:52 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_chr_in_str)
{
	massert(ft_chr_in_str('\0', ""), true);
	massert(ft_chr_in_str('\0', "b"), true);

	massert(ft_chr_in_str('a', ""), false);
	massert(ft_chr_in_str('a', "bc"), false);

	massert(ft_chr_in_str('a', "a"), true);
	massert(ft_chr_in_str('a', "ba"), true);
	massert(ft_chr_in_str('a', "ab"), true);
}
