/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_not_str.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:39:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_not_str)
{
	massert((void *)ft_str_not_str("", ""), NULL);
	massert(ft_str_not_str("aba", "a"), "ba");
	massert(ft_str_not_str("aba", "ab"), "a");
	massert((void *)ft_str_not_str("aba", "aba"), NULL);
}
