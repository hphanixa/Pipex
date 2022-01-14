/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hphanixa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:02:43 by hphanixa          #+#    #+#             */
/*   Updated: 2022/01/14 22:09:35 by hphanixa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	**find_path(char **envp)
{
	char	**path;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (envp[i] == NULL)
		return (0);
	path = ft_split(envp[i] + LEN_WORD_PATH, ':');
	return (path);
}

char	*new_path_with_cmd(t_util *ptr_util, char *arg)
{
	char	**cmd_option;
	int		i;

	i = 0;
	cmd_option = ft_split(arg, ' ');
	if (arg != NULL && (ft_strncmp("./", arg, 2) == 0
			|| ft_strncmp("/", arg, 1) == 0))
		return (arg);
	while (ptr_util->search_path_in_envp != NULL
		&& ptr_util->search_path_in_envp[i] != NULL)
	{
		ptr_util->add_slash = ft_strjoin(ptr_util->search_path_in_envp[i], "/");
		ptr_util->final_path = ft_strjoin(ptr_util->add_slash, cmd_option[0]);
		free(ptr_util->add_slash);
		if (access(ptr_util->final_path, X_OK) == 0)
		{
			free_after_split(cmd_option);
			return (ptr_util->final_path);
		}
		if (ptr_util->search_path_in_envp[i + 1] != 0)
			free(ptr_util->final_path);
		i++;
	}
	free_after_split(cmd_option);
	return (ptr_util->final_path);
}

int	main(int ac, char **av, char **envp)
{
	t_util	util;
	char	**arg_position;

	util.arg = av;
	arg_position = av;
	util.environnement = envp;
	if (ac != ARG_NUMBER_REQUIRED)
		error_arg();
	check_if_infile_is_correct(&util);
	check_if_outfile_is_correct(&util);
	if ((envp == NULL) || (*envp == NULL))
		ft_error(*envp);
	util.cmd_option1 = check_if_cmd1_exist(&util);
	util.cmd_option2 = check_if_cmd2_exist(&util);
	util.search_path_in_envp = find_path(util.environnement);
	util.path_with_cmd1 = new_path_with_cmd(&util, arg_position[2]);
	util.path_with_cmd2 = new_path_with_cmd(&util, arg_position[3]);
	if (util.search_path_in_envp != NULL)
		free_after_split(util.search_path_in_envp);
	pipex(&util);
	return (EXIT_SUCCESS);
}
