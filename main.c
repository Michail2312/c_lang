#include "stdio.h"
#include "string.h"
#include "stdbool.h"

void increment(int *num)
{
	++*num;
}

void decrement(int *num)
{
	--*num;
}

int main()
{
	int number;
	char userInput[1];
	bool finish = false;
	printf("Программа 'счетчик' запущена\n");
	printf("Введите целое число: ");
	scanf("%d", &number);
	while(!finish)
	{
		printf("Ваше число сейчас равно %d\n", number);
		printf("Что сделать с числом?\n");
		printf("Увеличить => +\n");
		printf("Уменьшить => -\n");
		printf("Выйти => q\n");
       	scanf("%s", userInput);
		if(strcmp(userInput, "q") == 0)
        {
            printf("Выход из программы\n");
            finish = true;
			break;			
		}
		else if(strcmp(userInput, "+") == 0)
		{
			//number = ++number;
			increment(&number);
		}
		else if(strcmp(userInput, "-") == 0)
		{
			// number = --number;
			decrement(&number);
		}
		else 
		{
			printf("Неизвестная команда\n");
			return 1;
		}
	}
	return 0;
};


