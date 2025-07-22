#include "libft.h"

int main(void)
{
	int test_values[] = {'A', 'Z', 'a', 'z', '0', '/', '@', '[', -1, 128, 255, EOF};
	int current_index = 0;
	int total_tests = sizeof(test_values) / sizeof(test_values[0]);
	int standard_result, custom_result;

	while (current_index < total_tests)
	{
		int input_character = test_values[current_index];
		standard_result = isalpha(input_character);
		custom_result = ft_isalpha(input_character);
		printf("Test char: ");
		if (input_character == EOF)
			printf("EOF");
		else if (input_character < 32 || input_character > 126)
			printf("0x%02X", (unsigned char)input_character);
		else
			printf("'%c'", input_character);
		printf(" | isalpha: %d | ft_isalpha: %d", standard_result, custom_result);
		if ((!!standard_result) == (!!custom_result))
			printf(" [OK]\n");
		else
			printf(" [FAIL]\n");
		current_index++;
	}
	return 0;
}
