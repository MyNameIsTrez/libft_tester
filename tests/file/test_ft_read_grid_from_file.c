/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_read_grid_from_file.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/05 18:37:13 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/22 18:31:29 by sbos          ########   odam.nl         */
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
		massert(grid.cells[0], (char *)NULL);
		free(grid.cells);
	}

	{
		t_grid		grid;
		t_success	success;

		success = ft_read_grid_from_file(&grid, "tests/file/ft_read_grid_from_file_test_files/no_trailing_newline");
		massert(success, (t_success)SUCCESS);
		massert(grid.width, (size_t)13);
		massert(grid.height, (size_t)5);
		m_safe_string_assert(grid.cells[0], "1111111111111", true);
		m_safe_string_assert(grid.cells[1], "10010000000C1", true);
		m_safe_string_assert(grid.cells[2], "1000011111001", true);
		m_safe_string_assert(grid.cells[3], "1P0011E000001", true);
		m_safe_string_assert(grid.cells[4], "1111111111111", true);
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
		m_safe_string_assert(grid.cells[0], "1111111111111", true);
		m_safe_string_assert(grid.cells[1], "10010000000C1", true);
		m_safe_string_assert(grid.cells[2], "1000011111001", true);
		m_safe_string_assert(grid.cells[3], "1P0011E000001", true);
		m_safe_string_assert(grid.cells[4], "1111111111111", true);
		free(grid.cells);
	}
}

////////////////////////////////////////////////////////////////////////////////
