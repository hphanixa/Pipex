#include "pipex.h"
#include "libft.h"

char **find_path(char **envp)
{
	char **path;
	int i; 
	
	i = 0;
	while (envp[i] != NULL && ft_strnstr(envp[i], "PATH=", 5) == NULL)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	path = ft_split(envp[i] + LEN_WORD_PATH, ':');
	return (path);
}

char *new_path_with_cmd(t_util *ptr_util, char *arg)
{

	char	*add_slash;
	char	*final_path;
	char	**cmd_option;
	int		i;

	i = 0;
//	errno = 0;
//	cmd_option = ft_split(*ptr_util->arg, ' ');
	cmd_option = ft_split(arg, ' ');
	if (arg != NULL && (ft_strncmp("./", arg, 2) == 0  || ft_strncmp("/", arg, 1) == 0 ))
		return (arg);
//	{
//		strerror(errno); // no such file or directory
//		return (strerror(ENOENT)); // >
//	}
//	if (ptr_util->infile < 0)
//		ft_cmd_error(&cmd_option[0]);

	while (ptr_util->search_path_in_envp != NULL && ptr_util->search_path_in_envp[i] != NULL)
	{
		add_slash = ft_strjoin(ptr_util->search_path_in_envp[i], "/");
		final_path = ft_strjoin(add_slash, cmd_option[0]);
		free(add_slash);
		if (access(final_path, X_OK) == 0)
			return (final_path);
		i++;
	}
//	ft_cmd_error(&cmd_option[0]);
	return (0);
}

int main (int ac, char **av, char **envp)
{
	t_util	util;
	int i;
	int j;
	char **arg_position;
	i = 0;
	j = 0;

	util.arg = av;
	arg_position = av;
	util.environnement = envp;
	if (ac != ARG_NUMBER_REQUIRED)
		error_arg();
	check_if_infile_is_correct(&util);
	check_if_outfile_is_correct(&util);
	if ((envp == NULL) || (*envp == NULL))
			ft_error(*envp);
	/*while (util.arg[i])
	{
		if (ft_isprintable(util.arg[j]) == 0)
			ft_error(*util.arg);
		i++;
		j++;
	}*/

//	if ((av[3] == 32) && (av[4] == 32)) // utiliser ft_strcmp
	util.search_path_in_envp = find_path(util.environnement);
//	if (util.infile > 0)
		util.path_with_cmd1 = new_path_with_cmd(&util, arg_position[2]);
	util.path_with_cmd2 = new_path_with_cmd(&util, arg_position[3]);
	if (util.search_path_in_envp != NULL)
		free_after_split(&util.search_path_in_envp);
	pipex(&util);
	return (EXIT_SUCCESS);
}
