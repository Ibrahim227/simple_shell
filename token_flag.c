#include "main.h"

/**
 * **strtow - splits a string into words
 * @str: input str
 * @dem: delimeter str
 * Return: a pointer to an array
 */

char **strtow(char *str, char *dem)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!dem)
		dem = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], dem) && (is_delim(str[i + 1], dem) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(str[i], dem))
			i++;
		k = 0;
		while (!is_delim(str[i + k], dem) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - splits a string
 * @str: the input str
 * @dem: the delimeter
 * Return: a pointer to an array
 */
char **strtow2(char *str, char dem)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != dem && str[i + 1] == dem) ||
		    (str[i] != dem && !str[i + 1]) || str[i + 1] == dem)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == dem && str[i] != dem)
			i++;
		k = 0;
		while (str[i + k] != dem && str[i + k] && str[i + k] != dem)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

