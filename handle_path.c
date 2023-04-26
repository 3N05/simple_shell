#include "shell.h"

/**
 * check_path - checkout the path
 * @env: anywhere
 * @argvs: anywhere
 * Return: -1
 */
int check_path(char **env, char **argvs)
{
	int i;
	char *ruta;
	char **paths;

	paths = get_path(env);

	if (paths == NULL || argvs == NULL)
		return (-1);

	for (i = 0; paths[i] != NULL; i++)
	{
		ruta = str_concat(paths[i], argvs[0]);
		if (access(ruta, F_OK & X_OK & R_OK) == 0)
		{
			free(argvs[0]);
			*(argvs) = ruta;
			free_dp(paths);
			return (0);
		}
		free(ruta);
	}

	free_dp(paths);
	return (access(argvs[0], F_OK & X_OK & R_OK));
}


/**
 * count_chr-how many chr delimitn has *srt
 * @str: string
 * @delimits: char to find in str
 * Return: - int no
 */

int count_chr(char *str, char *delimits)
{
	int result = 0, i, j;

	if (str != NULL && delimits != NULL)
	{
		for (i = 0; delimits[i] != '\0'; i++)
			for (j = 0; str[j] != '\0' j++)
				if (delimits[i] == str[j])
					result++;
	}
	return (result);
}

/**
 * get_path - get PATH in the environment
 * @env: environment var
 * Return: double pointer with each route
 */
char **get_path(char *env)
{
	char *str = "PATH", *my_path, *aux, **paths;
	unsigned int i = 0, j = 0, size;

	if (env == NULL)
		return (NULL);

	while (env[i] != NULL)
	{
		aux = _strstr(env[i], str);
		if (aux != NULL)
		{
			aux = _strdup(aux);
			size = count_chr(aux, PATH_DELIMIT) + BUFF_MAX;
			paths = (char **)malloc(sizeof(char *) * size);

			if (paths == NULL)
				return (NULL);

			my_path = strtok(aux, PATH_DELIMIT);
			while (my_path != NULL)
			{
				paths[j] = _strdup(my_path);

				if (paths[j] == NULL)
				{
					free(aux);
					return (free_dp(paths));
				}
				j++;
				my_path = strtok(NULL, PATH_DELIMIT);
			}
			paths[j] = NULL;
			free(aux);
			return (paths);
		}
		i++;
	}
	return (NULL);
}
