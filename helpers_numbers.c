#include "shell.h"

/**
 * long_to_string - converts a number to a string.
 * @number: number to be converted into a string.
 * @string: buffer to save the number as a string.
 * @base: base to convert number
 *
 * Return: Nothing.
 */
void long_to_string(long number, char *string, int base)
{
int index = 0, is_negative = 0;
long quotient = number;
char letters[] = "0123456789abcdef";


if (quotient == 0)
string[index++] = '0';

if (string[0] == '-')
is_negative = 1;


while (quotient)
{
if (quotient < 0)
string[index++] = letters[-(quotient % base)];
else
string[index++] = letters[quotient % base];
quotient /= base;
}
if (is_negative)
string[index++] = '-';

string[index] = '\0';
string_reverse(string);
}

/**
 * _atoi - convert a string to an integer.
 *
 * @s: pointer to the string origin.
 * Return: int of string or 0.
 */
int _atoi(char *s)
{
int sign = 1;
unsigned int number = 0;

/* 1 - analysis sign */
while (!('0' <= *s && *s <= '9') &&  *s != '\0')
{
if (*s == '-')
sign *= -1;
if (*s == '+')
sign *= +1;
s++;
}

/* 2 - extract the number */
while ('0' <= *s && *s <= '9' && *s != '\0')
{
number = (number * 10) + (*s - '0');
s++;
}
return (number *sign);
}

/**
 * count_characters - count the occurrences of a character in a string.
 *
 * @string: pointer to the string origin.
 * @character: string with characters to be counted.
 * Return: number of occurrences of character.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

for (; string[i]; i++)
{
if (string[i] == character[0])
counter++;
}
return (counter);
}
