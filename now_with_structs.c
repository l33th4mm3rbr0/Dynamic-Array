// Une implémentation basique d'un tableau à allocation dymanique
// J'ai changé le code précédent pour stocker des "struct" au lieu d'un simple entier

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Object
{
	char name[5];
	int value;
}Object;

void showValues(Object* values, int number_of_values);
Object* addValue(Object* valuesList, int* number_of_values, int value);
Object* removeValue(Object* valuesList, int* number_of_values, int value_to_remove);
void assignName(Object* object);

int main(int argc, char* argv[])
{
	srand((int)time(NULL));

	char input; // stores user input
	int number_of_values = 0;
	Object* values = NULL;

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

void showValues(Object* values, int number_of_values)
{
	printf("here are all the values: \n");
	for (int i = 0; i < number_of_values;i++)
	{
		printf("%d) name: %s, value: %d\n", i+1, values[i].name, values[i].value);
	}
}

Object* addValue(Object* valuesList, int* number_of_values, int value)
{
	*number_of_values+=1;
	Object* newList = malloc(sizeof(Object)*(*number_of_values));

	for (int i = 0; i < *number_of_values;i++)
	{
		if (i < *number_of_values - 1)
			newList[i] = valuesList[i];
		else
		{
			assignName(&newList[i]);
			newList[i].value = value;
		}
	}
	if (valuesList)
		free(valuesList);

	return newList;
}

Object* removeValue(Object* valuesList, int* number_of_values, int value_to_remove)
{
	*number_of_values -= 1;
	Object* newList = malloc(sizeof(Object) * (*number_of_values));
	for (int i = 0;i < *number_of_values;i++)
	{
		if (i < value_to_remove)
			newList[i] = valuesList[i];
		else
			newList[i] = valuesList[i+1];
	}
	printf("removed value: %s / %d\n", valuesList[value_to_remove].name, valuesList[value_to_remove].value);
	if (valuesList)
		free(valuesList);
	
	return newList;
}

void assignName(Object* object)
{
	char random;
	for (int i = 0;i < 5;i++)
	{
		if (i == 4)
			object->name[i] = '\0';
		else
		{
			random = rand() % 5;
			switch (random)
			{
			case 0:
				object->name[i] = 'A';
				break;
			case 1:
				object->name[i] = 'B';
				break;
			case 2:
				object->name[i] = 'C';
				break;
			case 3:
				object->name[i] = 'D';
				break;
			case 4:
				object->name[i] = 'E';
				break;
			}
		}
	}
}