/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_putnbr.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 15:00:51 by sbos          #+#    #+#                 */
/*   Updated: 2022/08/18 14:09:11 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft_tests.h"

Test(ft_putnbr)
{
	test_io(ft_putnbr, -123, "-123", -1, 0);
}
