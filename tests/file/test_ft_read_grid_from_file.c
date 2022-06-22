/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read_grid_from_file.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:37:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/22 11:56:29 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "libft_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(ft_read_grid_from_file)
{
	{
		t_grid		grid;
		t_success	success;

		success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/empty");
		massert(success, (t_success)SUCCESS);
		massert(grid.width, (size_t)0);
		massert(grid.height, (size_t)0);
	}

	{
		t_grid		grid;
		t_success	success;

		success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/no_trailing_newline");
		massert(success, (t_success)SUCCESS);
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
	}

	{
		t_grid		grid;
		t_success	success;

		success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/not_rectangular");
		massert(success, (t_success)ERROR);
	}

	{
		t_grid		grid;
		t_success	success;

		success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/trailing_newline");
		massert(success, (t_success)SUCCESS);
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
	}
}

////////////////////////////////////////////////////////////////////////////////
