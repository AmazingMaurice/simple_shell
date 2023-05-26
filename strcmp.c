/**
 * my_strcmp - Compare two strings.
 * @string1: The first string to compare.
 * @string2: The second string to compare.
 * Return: 0 on equality
 * a - value if @string1 < @string2,
 * or a + value if @string1 > @string2.
 */
int my_strcmp(const char *string1, const char *string2)
{
while (*string1 != '\0' && *string2 != '\0' && *string1 == *string2)
{
string1++;
string2++;
}

return ((int) (*string1) -(*string2));
}
