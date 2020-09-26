#include "pch.h"
#include <iostream>
#include <windows.h>
#include <string.h>

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc == 1)
	{
		system("wmic service get Name, DisplayName, State /format:list");
		printf_s("Для вывода полной информации о конкретной службе запустите программу с параметрами /i \"Имя службы\", для вывода списка драйверов запустите с параметром /d\n");
		system("pause");
	}
	else if (strcmp(argv[1], "/i") == 0)
	{
		if (argc == 2)
		{
			printf_s("Не указано имя службы\n");
			system("pause");
		}
		else
		{
			char str[255];
			const char* fir = "wmic service where (Name = '";
			const char* end = "') get /format:list";
			sprintf_s(str, "%s%s%s", fir, argv[2], end);
			system(str);
			system("pause");
		}
	}
	else if (strcmp(argv[1], "/d") == 0)
	{
		system("wmic sysdriver get Name, DisplayName, State /format:list");
		system("pause");
	}
	else
	{
		system("pause");
		return 0;
	}
}

