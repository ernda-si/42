/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreira <pmoreira@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:20:53 by pmoreira          #+#    #+#             */
/*   Updated: 2025/06/27 15:24:16 by pmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_is_dir(t_cmd *cmd)
{
	DIR	*check;

	if (!cmd->args[0])
		return (1);
	check = opendir(cmd->cmd_path);
	if (check && ft_strchr(cmd->cmd_path, '/'))
	{
		ft_printf_fd(2, "minishell: %s: Is a directory\n", cmd->cmd_path);
		closedir(check);
		mini_cleaner(NULL, get_hell(NULL), 126);
	}
	return (0);
}

int	execute_builtin(t_cmd *cmd, t_hell *shell)
{
	if (!ft_strcmp(cmd->args[0], "echo"))
		return (mini_echo(cmd));
	else if (!ft_strcmp(cmd->args[0], "pwd"))
		return (mini_pwd());
	else if (!ft_strcmp(cmd->args[0], "cd"))
		return (mini_cd(cmd, &shell->env));
	else if (!ft_strcmp(cmd->args[0], "env"))
		mini_env(shell);
	else if (!ft_strcmp(cmd->args[0], "exit"))
		return (mini_exit(shell, cmd));
	else if (!ft_strcmp(cmd->args[0], "export"))
		return (mini_export(&shell->env, &shell->export, cmd));
	else if (!ft_strcmp(cmd->args[0], "unset"))
		mini_unset(&shell->env, cmd, &shell->export, shell);
	return (0);
}

void	execute_child(t_cmd *cmd, int prev_pipe, int *pipes, t_hell *shell)
{
	signal_handler(shell, 'D');
	if (cmd->prev && prev_pipe != -1)
		cmd->fd_in = prev_pipe;
	if (cmd->is_piped)
		cmd->fd_out = pipes[1];
	handle_redirections(cmd);
	if (shell->status == 1 && !cmd->is_fork)
		return ;
	if (shell->hist_fd >= 0)
		close(shell->hist_fd);
	if (cmd->fd_in != 0)
		ft_dup(cmd->fd_in, 0);
	if (cmd->fd_out != 1)
		ft_dup(cmd->fd_out, 1);
	close_all();
	if (cmd->is_builtin)
		mini_cleaner(NULL, shell, execute_builtin(cmd, shell));
	if (!cmd->cmd_path && cmd->args[0])
		try_run(shell, cmd->args);
	if (!check_is_dir(cmd) && cmd->cmd_path && cmd->args[0])
		execve(cmd->cmd_path, cmd->args, cmd->envp);
	mini_cleaner(NULL, shell, shell->status);
}
