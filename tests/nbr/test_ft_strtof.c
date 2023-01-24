/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_strtof.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/23 15:50:01 by sbos          #+#    #+#                 */
/*   Updated: 2023/01/23 15:50:01 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

#include <math.h>

////////////////////////////////////////////////////////////////////////////////

void	compare_strtofs(char *input, float expected_result)
{
	char	*ft_end;
	char	*libc_end;

	float	ft_result;
	float	libc_result;

	ft_result = ft_strtof(input, &ft_end);

	libc_result = strtof(input, &libc_end);

	massert(ft_end, libc_end);
	massert(ft_result, libc_result);
	massert(ft_result, expected_result);
}

Test(ft_strtof)
{
	compare_strtofs(" ", 0);
	compare_strtofs(" x 255,255,255\n", 0);
	compare_strtofs(" a", 0);
	compare_strtofs(" -", 0);
	compare_strtofs(" .", 0);
	compare_strtofs(" 4", 4);
	compare_strtofs("1", 1);
	compare_strtofs("-1", -1);
	compare_strtofs("+1", 1);
	compare_strtofs("- 1", 0);
	compare_strtofs("+ 1", 0);
	compare_strtofs("9", 9);
	compare_strtofs("0", 0);
	compare_strtofs("-0", -0);
	compare_strtofs("a", 0);
	compare_strtofs("-a", 0);
	compare_strtofs(".", 0);
	compare_strtofs("-.", 0);
	compare_strtofs(". 4", 0);
	compare_strtofs("-. 4", 0);
	compare_strtofs("-.4 2", -.4f);
	compare_strtofs("0.", 0);
	compare_strtofs("-0.", -0);
	compare_strtofs(".0", 0);
	compare_strtofs("-.0", -0);
	compare_strtofs("a.", 0);
	compare_strtofs("-a.", 0);
	compare_strtofs(".a", 0);
	compare_strtofs("-.a", 0);
	compare_strtofs("-1-2", -1);
	compare_strtofs("--1", 0);
	compare_strtofs("++1", 0);
	compare_strtofs("..1", 0);
	compare_strtofs(".-1", 0);
	compare_strtofs("1ab", 1);
	compare_strtofs("1.", 1);
	compare_strtofs("1.2", 1.2f);
	compare_strtofs("123456789", 123456789);
	compare_strtofs(" 1", 1);
	compare_strtofs("1 ", 1);
	compare_strtofs("-", 0);
	compare_strtofs("+", 0);
	compare_strtofs("-.", 0);
	compare_strtofs("+.", 0);
	compare_strtofs("-.0", -0);
	compare_strtofs("+.0", 0);
	compare_strtofs("-+0", 0);
	compare_strtofs("+-0", 0);
	// TODO: massert() doesn't do float comparisons properly.
	compare_strtofs("99999999999999999999999999999999999999999999999999", INFINITY);
	compare_strtofs("-99999999999999999999999999999999999999999999999999", -INFINITY);
	compare_strtofs("0.00000000000000000000000000000000000000000000000000000000000000000000000000001", 0.9f);
	compare_strtofs("-0.00000000000000000000000000000000000000000000000000000000000000000000000000001", 0.9f);
	compare_strtofs("1f", 1);
}

////////////////////////////////////////////////////////////////////////////////
