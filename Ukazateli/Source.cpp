#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include<Windows.h>
using namespace std;

void DeletArr(char** arr, int count) {
	for (int i = 0; i < count; i++)
	{
		delete arr[i];
	}
	delete[]arr;
}
void ReversFile(char* fileName, char** arr, int count) {
	FILE* f2;
	if (fopen_s(&f2, fileName, "w") == NULL) {
		for (int i = count - 1; i >= 0; i--)
		{
			fputs(arr[i], f2);
			if (i == count - 1) {
				fputs("\n", f2);
			}
		}
		fclose(f2);
	}
}

void CopyString(char* fileName, char** arr) {
	int i = 0;
	FILE* f1;
	char str[255];
	if (fopen_s(&f1, fileName, "r") == NULL) {
		while (!feof(f1)) {
			fgets(str, 255, f1);

			arr[i] = new char[255];
			strcpy(arr[i], str);
			i++;
		}
		fclose(f1);
	}
}

int Count_lines(char* fileName) {
	FILE* f1;
	char str[255];
	int count = 0;
	if (fopen_s(&f1, fileName, "r") == NULL) {
		while (!feof(f1)) {
			fgets(str, 255, f1);
			count++;
		}
		fclose(f1);
	}
	return count;
}

int main() {
	setlocale(LC_ALL, "ru");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	int menu;
	do {
		cout << "Enter Task:" << endl;
		cin >> menu;
		cin.ignore();
		
		switch (menu) {

		case 1: {
			/* Задание 1:
Дано два текстовых файла. Выяснить, совпадают ли их строки.
Если нет, то вывести несовпадающую строку из каждого файла.
*/
			FILE* F1, * F2, * F3;
			char myStr1[250];
			char myStr2[250];
			if (fopen_s(&F1, "F1.txt", "r") == NULL && fopen_s(&F2, "F2.txt", "r") == NULL && fopen_s(&F3, "F3.txt", "w") == NULL) {


				while (!feof(F1) && !feof(F2)) {
					fgets(myStr1, 250, F1);
					fgets(myStr2, 250, F2);
					if (strcmp(myStr1, myStr2) != NULL) {
						fputs(myStr1, F3);
						printf("%s", myStr1);
						fputs(myStr2, F3);
						printf("%s", myStr2);
					}
				}
				//fprintf(F3, "F3.txt");
				cout << endl;
				fclose(F1);
				fclose(F2);
				fclose(F3);
			}
			else
				printf("Error");
		}
			  break;
		case 2: {
			/*Дан текстовый файл. Необходимо создать новый файл и записать в него следующую
			статистику по исходному файлу:
Количество символов
Количество строк
Количество гласных букв
Количество согласных букв
Количество цифр.
*/
			FILE* Stats, * Chek;
			char myStr[250];
			char sBuf[250];
			int count_line = 0;
			int count_digit = 0;
			int count_str = 0;
			int count_vow = 0;
			int count_con = 0;
			char vowels[7] = { 'a','e','i','o','u','y','\0' };
			//char consonants[22] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z','\0' };
			char consonants[] = "b,c,d,f,g,h,j,k,l,m,n,p,q,r,s,t,v,w,x,y,z";
			if (fopen_s(&Stats, "Stats.txt", "r") == NULL && fopen_s(&Chek, "Chek.txt", "w") == NULL)
			{
				while (!feof(Stats))
				{
					fgets(myStr, 250, Stats);
					count_line++;
					for (size_t i = 0; i < strlen(myStr); i++)
					{
						count_str++;
						if (isdigit(myStr[i]))
							count_digit++;
						else {
							if (strchr(vowels, myStr[i]))
								count_vow++;
							else if (strchr(consonants, myStr[i]))
								count_con++;
						}
					}
				}

				printf("Количество строк:%i \n", count_line);
				printf("Количество символов:%i \n", count_str);
				printf("Количество цифр:%i \n", count_digit);
				printf("Количество гласных:%i \n", count_vow);
				printf("Количество согласных:%i \n", count_con);


				//запись
				_itoa(count_line, sBuf, 10);
				strcat(sBuf, " count of lines\n");
				fputs(sBuf, Chek);
				_itoa(count_digit, sBuf, 10);
				strcat(sBuf, " count of digit\n");
				fputs(sBuf, Chek);
				_itoa(count_str, sBuf, 10);
				strcat(sBuf, " count of str\n");
				fputs(sBuf, Chek);
				_itoa(count_vow, sBuf, 10);
				strcat(sBuf, " count vowels\n ");
				fputs(sBuf, Chek);
				_itoa(count_con, sBuf, 10);
				strcat(sBuf, " count consonants\n");
				fputs(sBuf, Chek);

				fclose(Stats);
				fclose(Chek);
			}
			else
				printf("Error");
		}
			  break;
			  case 3: {
			  	/*Дан текстовый файл. Необходимо переписать его строки в другой файл. 
			  	Порядок строк во втором файле должен быть обратным по отношению к порядку 
			  	строк в заданном файле.*/
				  char file_Name[] = "file6.txt";
				  char file_Name2[] = "file7.txt";
				  int count_lines = Count_lines(file_Name);
				  printf("%i count of lines\n", count_lines);
				  char** arr = new char* [count_lines];
				  CopyString(file_Name, arr);
				  ReversFile(file_Name2, arr, count_lines);
				  DeletArr(arr, count_lines);
				 
				  
					
				 
				  
			  		
			  }
			  	  break;
		}
	} while (menu != 0);
}
