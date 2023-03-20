/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_str_not_chr.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 16:35:32 by sbos          #+#    #+#                 */
/*   Updated: 2022/04/06 15:34:19 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_str_not_chr)
{
	massert(ft_str_not_chr("bonjour", '\0'), "bonjour");
	massert(ft_str_not_chr("bonjour", 'b'), "onjour");
	massert(ft_str_not_chr("bonjour", 'o'), "bonjour");
}
