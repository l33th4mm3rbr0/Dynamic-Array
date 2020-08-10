// Une implémentation basique d'un tableau à allocation dymanique

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showValues(int* values, int number_of_values);
int* addValue(int* valuesList, int* number_of_values, int value);
int* removeValue(int* valuesList, int* number_of_values, int value_to_remove);

int main(int argc, char* argv[])
{
	srand((int)time(NULL));

	char input; // stores user input
	int number_of_values = 0;
	int* values = NULL;

	while (1)
	{
		input = getchar();
		printf("%c\n", input);
		if (input == 'q')
			break;

		switch (input)
		{
		case 'a': //add a value
			values = addValue(values, &number_of_values, rand() % 51);
			showValues(values, number_of_values);
			break;
		case 'r': //remove a value
			if (number_of_values > 0)
			{
				values = removeValue(values, &number_of_values, rand() % number_of_values);
				showValues(values, number_of_values);
			}
			else
				printf("cannot remove inexisting value\n");
			break;
		case 's': //show the stored values
			showValues(values, number_of_values);
			break;
		}

	}

	if (values)
		free(values);
	return 0;
}

void showValues(int* values, int number_of_values)
{
	printf("here are all the values: \n");
	for (int i = 0; i < number_of_values;i++)
	{
		printf("%d) %d\n", i+1, values[i]);
	}
}

int* addValue(int* valuesList, int* number_of_values, int value)
{
	*number_of_values+=1;
	int* newList = malloc(sizeof(int)*(*number_of_values));

	for (int i = 0; i < *number_of_values;i++)
	{
		if (i < *number_of_values - 1)
			newList[i] = valuesList[i];
		else
			newList[i] = value;
	}
	if (valuesList)
		free(valuesList);

	return newList;
}

int* removeValue(int* valuesList, int* number_of_values, int value_to_remove)
{
	*number_of_values -= 1;
	int* newList = malloc(sizeof(int) * (*number_of_values));
	for (int i = 0;i < *number_of_values;i++)
	{
		if (i < value_to_remove)
			newList[i] = valuesList[i];
		else
			newList[i] = valuesList[i+1];
	}
	printf("removed value: %d\n", valuesList[value_to_remove]);
	if (valuesList)
		free(valuesList);
	
	return newList;
}