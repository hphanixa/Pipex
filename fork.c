/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:02:41 by hphanixa          #+#    #+#             */
/*   Updated: 2022/01/12 17:07:57 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_util *util)
{	
	int	status;
	int	end[2];

	util->cmd_option1 = ft_split(util->arg[2], ' ');
	util->cmd_option2 = ft_split(util->arg[3], ' ');
	if (pipe(end) < 0)
		ft_error(NULL);
	util->child1 = fork();
	if (util->child1 < 0)
		ft_error("fork");
	if (util->child1 == 0 && util->infile > 0)
		child_one(end, util);
	else if (util->child1 == 0 && util->infile < 0)
		exit(1);
	util->child2 = fork();
	if (util->child2 < 0)
		ft_error("fork");
	else if (util->child2 == 0 && util->outfile > 0)
		child_two(end, util);
	else if (util->child2 == 0 && util->outfile < 0)
		exit(1);
	close(end[0]);
	close(end[1]);
	waitpid(util->child1, &status, 0);
	waitpid(util->child2, &status, 0);
	exit(WEXITSTATUS(status));
}

void	check_if_infile_is_correct(t_util *ptr_util)
{
	if (access(ptr_util->arg[1], F_OK) < 0)
	{
		ptr_util->infile = -1;
		perror(ptr_util->arg[1]);
	}
	else
		ptr_util->infile = open(ptr_util->arg[1], O_RDONLY);
}

void	check_if_outfile_is_correct(t_util *ptr_util)
{
	if (access(ptr_util->arg[4], F_OK) != 0 || 
		(access(ptr_util->arg[4], R_OK | W_OK) != 0))
	{
	   	ptr_util->outfile = open(ptr_util->arg[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		ptr_util->outfile = open(ptr_util->arg[4], O_RDWR | O_TRUNC);
	}
	if (ptr_util->outfile < 0)
		perror("open");
}

void	child_one(int *end, t_util *util1)
{
	dup2(util1->infile, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(util1->infile);
	close(end[1]);
	close(end[0]);
	execve(util1->path_with_cmd1, util1->cmd_option1, util1->environnement);
	printf("pas bon ----\n");
	perror(NULL);
	exit(1);
}

void	child_two(int *end, t_util *util2)
{
	close(end[1]);
	dup2(util2->outfile, STDOUT_FILENO);
	close(util2->outfile);
	dup2(end[0], STDIN_FILENO);
	close(end[0]);
	execve(util2->path_with_cmd2, util2->cmd_option2, util2->environnement);
	printf("------pas bon ----\n");
	perror(NULL);
	exit(1);
}
