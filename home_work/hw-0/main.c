#include "stdio.h"
#include "string.h"
#include "stdbool.h"


bool is_found_substr(char *symb_first, char *symb_second)
{
	// Вспомогательная функция для поиска подстроки. Вернет true или false
	char substing_AB[2] = "AB"; //Шаблон подстроки
	char substing_CD[2] = "CD"; //Шаблон подстроки
	if(*symb_first == substing_AB[0] && *symb_second == substing_AB[1] || *symb_first == substing_AB[1] && *symb_second == substing_AB[0])
	{
		return true;
	}
	if(*symb_first == substing_CD[0] && *symb_second == substing_CD[1] || *symb_first == substing_CD[1] && *symb_second == substing_CD[0])
	{
		return true;
	}
	return false;
}

int delete_substr(char str[], int len_str)
{
	// Функция для формирования новой строки из входящей без найденных подстрок
	// Возвращает длину новой строки
	char is_empty_str[0] = ""; // Если в результате получилась пустая строка
	char result_str[len_str]; // Для сохранения полученной новой строки
	int idx = 0; // Индекс для прохода в цикле по входящей строке
	int idx_res_str = 0; // Индекс для формирования новой строки

	while (idx < len_str)
	{
		if(is_found_substr(&str[idx], &str[idx+1]) || is_found_substr(&str[idx], &str[idx-1]))
		{
			++idx;
			continue;
		}

		result_str[idx_res_str] = str[idx];
		++idx_res_str;
		++idx;
	}		
	if(idx_res_str == 0)
	{
		return sizeof is_empty_str;
	}
	return strlen(result_str);
}

int main()
{	
	char template_first[] = "CDABFSDFPOIAB"; // Тестовый шаблон  
	char template_second[] = "FCDAEBFSCDDFPCDABOIABIOU"; // Тестовый шаблон 	
	char template_third[] = "CDABCDAB"; // Тестовый шаблон 
	printf("%d\n",delete_substr(template_first, strlen(template_first)));
	printf("%d\n",delete_substr(template_second, strlen(template_second)));
	printf("%d\n",delete_substr(template_third, strlen(template_third)));
	return 0;
};


