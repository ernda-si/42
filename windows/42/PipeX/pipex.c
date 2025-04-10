/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ernda-si <ernda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:43:16 by ernda-si          #+#    #+#             */
/*   Updated: 2025/04/10 15:42:58 by ernda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// verificar se a infile is valid -> existencia / leitura;
// verificar se a outfile is valid -> existencia / leitura / truncation;
// executar primeiro comando na infile;
// utilizar pipe para guardar o resultado do primeiro comando pipe[1];
// pegar primeiro resultado e executar segundo comando;
// por o resultado final na outfile com pipe[0];
// criar handler de erros;

void	ft_close_all(t_pipex *p)
{
	if(p->files[0] > -1)
		close(p->files[0]);
	if(p->files[1] > -1)
		close(p->files[1]);
	close(p->fds[0]);
	close(p->fds[1]);
}

void	free_matrix(char **matrix)
{
	int	i;
	
	i = -1;
	while (matrix && matrix[++i])
		free(matrix[i]);
	free(matrix);
}

void	clean(t_pipex *p)
{
	if (p->paths)
		free_matrix(p->paths);
	if (!p->cmd)
		p->cmd = 0;	
	free(p);
}

void	get_paths(t_pipex *p)
{
	char	*path_parse;
	char	**paths;
	char	*tmp;
	int		i;

	i = 0;
	while (p->envp[i])
	{
		if (ft_strnstr(p->envp[i], "PATH", 5))
			path_parse = p->envp[i];
		i++;
	}
	path_parse = ft_substr (path_parse, 5, ft_strlen(path_parse));
		paths = ft_split (path_parse, ':');
	i = -1;
	while (paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin (tmp, "/");
		if (tmp)
			free (tmp);
	}
	p->paths = paths;
	free(path_parse);
}

void	ft_first_child(t_pipex *p)
{
	char	*cmd;
	char	**mycmd;
	int		i;

	i = -1;
	if (access(p->av[1], F_OK | R_OK) == -1)
	{
		
		ft_close_all(p);
		clean (p);
		perror ("Infile");
		exit (1);
	}
	dup2 (p->files[0], 0);
	dup2 (p->fds[1], 1);
	ft_close_all (p);
	mycmd = ft_split(p->av[2], ' ');
	while (p->paths[++i])
	{
		if (access (p->av[2], F_OK) == -1)
			cmd = ft_strjoin(p->paths[i], mycmd[0]);
		else
			cmd = ft_strdup(p->av[2]);
		if (access (cmd, X_OK) == 0)
			execve (cmd, mycmd, p->envp);
		if (cmd)
			free(cmd);
	}
	if (mycmd)
		free_matrix(mycmd);
	perror ("execution failed!");
	clean(p);
	exit (1);
}

void	pexit(int status, char *error)
{
	perror(error);
	exit(status);
}

void	ft_second_child(t_pipex *p)
{
	char	*cmd;
	char	**mycmd;
	int		i;

	i = -1;
	if (access(p->av[4], F_OK | W_OK) == -1)
	{
		perror ("Outfile");
		free_matrix(p->paths);
		free(p);
		exit (1);
	}
	dup2 (p->fds[0], 0);
	dup2 (p->files[1], 1);
	ft_close_all (p);
	mycmd = ft_split(p->av[3], ' ');
	while (p->paths[++i])
	{
		if (access (p->av[3], F_OK) == -1)
			cmd = ft_strjoin(p->paths[i], mycmd[0]);
		else
			cmd = ft_strdup(p->av[i]);
		if (access (cmd, X_OK) == 0)
			execve (cmd, mycmd, p->envp);
		if (cmd)
			free(cmd);
	}
	free_matrix(mycmd);
	clean(p);
	pexit(1, "execution");
}

void	docmds(t_pipex *p)
{
	p->cmd = fork ();
	if (p->cmd < 0)
		pexit (1, "fork");
	else if (p->cmd == 0)
		ft_first_child(p);
	p->cmd2 = fork ();
	if (p->cmd2 < 0)
		pexit (1, "fork");
	else if (p->cmd2 == 0)
		ft_second_child(p);
}

void	ft_init_pipex(t_pipex *p)
{
	int	status;

	if (pipe (p->fds) < 0)
	{
		clean(p);
		pexit (1, "pipe");
	}
	docmds(p);
	ft_close_all(p);
	waitpid(p->cmd, &status, 0);
	waitpid(p->cmd2, &status, 0);
	if (WIFEXITED (status))
	{
		clean(p);
		exit (WEXITSTATUS (status));
	}
	else
	{
		clean(p);
		exit (1);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_pipex	*p;

	if (ac != 5)
	{
		write(1, "/pipex [in_file] '[cmd1]' '[cmd2]' [out_file]\n", 47);
		exit(1);
	}
	else if (av[1][0] == '\0' || av[4][0] == '\0')
		exit(1);
	p = (t_pipex *) malloc(sizeof(t_pipex));
	p->av = av;
	p->envp = envp;
	p->ac = ac;
	get_paths(p);
	p->files[0] = open(av[1], O_RDONLY);
	if (access(p->av[4], F_OK) == -1)
		unlink(av[4]);
	p->files[1] = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	ft_init_pipex(p);
}
