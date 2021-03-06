/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:02:41 by hphanixa          #+#    #+#             */
/*   Updated: 2022/01/16 13:33:59 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_util *util)
{	
	int	status;

	if (pipe(util->end) < 0)
		ft_error(NULL);
	util->child1 = fork();
	if (util->child1 < 0)
		ft_error("fork");
	if (util->child1 == 0 && util->infile > 0) // si retour de fork = 0, signifie que
		child_one(util);                   // le processus child1 est en cours.
	else if (util->child1 == 0 && util->infile < 0)
		exit(1);
	util->child2 = fork();
	if (util->child2 < 0)
		ft_error("fork");
	else if (util->child2 == 0 && util->outfile > 0)
		child_two(util);
	else if (util->child2 == 0 && util->outfile < 0)
		exit(1);
	(close(util->infile));
	(close(util->end[0]));
	(close(util->end[1]));
	(close(util->outfile));
	waitpid(util->child1, &status, 0);  // le parent attend que le child1 termine son process
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
	if (access(ptr_util->arg[4], F_OK) != 0
		|| (access(ptr_util->arg[4], R_OK | W_OK) != 0))
	{
		ptr_util->outfile = open(ptr_util->arg[4],
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	else
	{
		ptr_util->outfile = open(ptr_util->arg[4], O_RDWR | O_TRUNC);
	}
	if (ptr_util->outfile < 0)
		perror("open");
}

void	child_one(t_util *util1)
{
	dup2(util1->infile, STDIN_FILENO);
	dup2(util1->end[1], STDOUT_FILENO);
	(close(util1->infile));
	(close(util1->end[1]));
	(close(util1->end[0]));
	if (util1->cmd_option1 != NULL)
		execve(util1->path_with_cmd1, util1->cmd_option1, util1->environnement);
	if ((ft_strncmp("./", util1->cmd_option1[0], 2) == 0
			|| ft_strncmp("/", util1->cmd_option1[0], 1) == 0)
		|| (util1->cmd_option1 == NULL))
		ft_cmd_error(util1->cmd_option1);
	perror("");
	exit(1);
}

void	child_two(t_util *util2)
{
	dup2(util2->outfile, STDOUT_FILENO);
	dup2(util2->end[0], STDIN_FILENO);
	(close(util2->outfile));
	(close(util2->end[0]));
	(close(util2->end[1]));
	if (util2->cmd_option2 != NULL)
		execve(util2->path_with_cmd2, util2->cmd_option2, util2->environnement);
	if ((ft_strncmp("./", util2->cmd_option2[0], 2) == 0
			|| ft_strncmp("/", util2->cmd_option2[0], 1) == 0)
		|| (util2->cmd_option2 == NULL))
		ft_cmd_error(util2->cmd_option2);
	perror("");
	exit(1);
}
