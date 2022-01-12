#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "./libft/libft.h"

# define USAGE "usage: ./pipex [infile] [cmd1] [cmd2] [outfile]\n"
# define ARG_NUMBER_REQUIRED 5
# define EXIT_NUMBER 125
# define LEN_WORD_PATH 5

typedef struct s_util
{
	char	*path_with_cmd1;
	char	*path_with_cmd2;
	char	**arg;
	char	**environnement;
	char	**search_path_in_envp;
	char	**cmd_option1;
	char	**cmd_option2;
	char 	**arg_position;
	int		infile;
	int		outfile;
	int		child1;
	int		child2;
}	t_util;

char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(char const *str);
int		is_charset(char c, char charset);
int		count_words(char const *str, char c);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
void	child_one(int *end, t_util *util1);
void	child_two(int *end, t_util *util2);
void	free_after_split(char ***str);
void	pipex(t_util *util);
void	ft_cmd_error(char **cmd);
void	ft_error(const char *m);
void 	error_arg(void);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
void	check_if_infile_is_correct(t_util *ptr_util);
void	check_if_outfile_is_correct(t_util *ptr_util);
char *new_path_with_cmd(t_util *ptr_util, char *arg);

#endif
