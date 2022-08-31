void	echo(int argc, char *argv[])
{
	int	i;
	int	n_flag;

	i = 0;
	n_flag = 0;
	if (ft_strcmp(argv[1], "-n") == 0)
	{
		n_flag = 1;
		i++;
	}
	while (++i < argc - 1)
		printf("%s ", argv[i]);
	if (i == argc - 1)
		printf("%s", argv[i]);
	if (!n_flag)
		printf("\n");
}
