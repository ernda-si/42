/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:10:40 by pmoreira          #+#    #+#             */
/*   Updated: 2025/06/24 12:16:18 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prepare_next_input(t_hell *data)
{
	data->cmd_count = 0;
	if (data->tokens)
		clean_list(data);
	if (data->cmd)
	{
		clean_cmds(data);
		data->cmd = NULL;
	}
	if (data->input)
	{
		free(data->input);
		data->input = NULL;
	}
}

void	close_all(void)
{
	int	i;

	i = 3;
	while (i < 1024)
	{
		close(i);
		i++;
	}
}

/// @brief Clear all minishell data, close all fds and exit with status given.
/// @param matrix If not null, clear the matrix.
/// @param data If not null, call armageddon.
/// @param status If status < 0, armageddon don't gonna be called.
void	mini_cleaner(char **matrix, t_hell *data, int status)
{
	if (matrix)
		ft_clean_matrix(matrix);
	close_all();
	if (data && status >= 0)
	{
		armageddon(data);
		exit(status);
	}
}

/// @brief Deletes all data from the program.
/// @param data Main struct of the program.
void	armageddon(t_hell *data)
{
	if (data->tokens)
		clean_list(data);
	if (data->env)
		clean_env(data);
	if (data->export)
		clean_export(data);
	if (data->cmd)
		clean_cmds(data);
	if (data->path)
		ft_clean_matrix(data->path);
	if (data->hist_fd >= 0)
		close(data->hist_fd);
	if (data->envp)
		ft_clean_matrix(data->envp);
	if (data->input)
		free(data->input);
	rl_clear_history();
	free(data);
}
