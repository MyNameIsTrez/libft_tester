/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_not_set.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:39:16 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_not_set)
{
	massert((void *)ft_str_not_set("", ""), NULL);
	massert(ft_str_not_set("1.24", "1234567890"), ".24");
	massert((void *)ft_str_not_set("aba", "aba"), NULL);
}
