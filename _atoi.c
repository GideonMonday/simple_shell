#include "shell.h"

/**
 * checkInteractiveMode - returns true if shell is interactive mode
 * @info: pointer to info_t struct holding shell information
 *    *
 *     * Returns 1 if the shell is in interactive mode, otherwise 0
 */
int checkInteractiveMode(info_t *info)
{
	return (isInputTerminal() && info->readfd <= 2);
}

/**
 *  * isDelimiter - checks if character is a delimiter
 *   * @character: character to check
 *    * @delimiters: string containing delimiters
 *     *
 *      * Returns 1 if the character is a delimiter, otherwise 0
 */
int isDelimiter(char character, char *delimiters)
{
	while (*delimiters)
	{
		if (*delimiters == character)
			return (1);
		delimiters++;
	}
	return (0);
}

/**
 *  * isAlphabetic - checks for alphabetic character
 *   * @character: character to check
 *    *
 *     * Returns 1 if the character is alphabetic, otherwise 0
 */
int isAlphabetic(int character)
{
	if ((character >= 'a' && character <= 'z')
			|| (character >= 'A' && character <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *  * convertStringToInt - converts a string to an integer
 *   * @str: string to convert
 *    *
 *     * Returns the converted integer or 0 if no numbers in the string
 */
int convertStringToInt(char *str)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			sign *= -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

