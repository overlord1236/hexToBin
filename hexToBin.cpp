// hexToBin

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH_INPUT "M:\\Study\\Fomin\\SM6\\LBS\\LB1\\LB_Visual\\hexToDec\\input.txt"
#define FILE_PATH_OUTPUT "M:\\Study\\Fomin\\SM6\\LBS\\LB1\\LB_Visual\\hexToDec\\output.txt"

#define F "1111"
#define E "1110"
#define D "1101"
#define C "1100"
#define B "1011"
#define A "1010"
#define x9 "1001"
#define x8 "1000"
#define x7 "0111"
#define x6 "0110"
#define x5 "0101"
#define x4 "0100"
#define x3 "0011"
#define x2 "0010"
#define x1 "0001"
#define x0 "0000"


char *inputString; 
char *outputString;


bool readInputString(char *);
char* symbolRecognize(char);
bool hexToBinConvert(void);
bool writeOutputString(char *);


int main()
{
	if (readInputString((char *)FILE_PATH_INPUT) == true) {
		hexToBinConvert();
	}
	else {
		puts((char*)"Cannot open input file!\n");
	}
	if (writeOutputString((char *)FILE_PATH_OUTPUT) == true) {
		puts((char*)"Result of convertation was write in file 'output.txt'\n");
	}
	system("pause");
	return 0;
}

/**
  * @brief Считавает значение из файла в строку 
  */
bool readInputString(char *filePath) {
	FILE *inputFile;
	int i = 0;
	long fileLength;
	inputFile = fopen(filePath, "r");
	fseek(inputFile, 0, SEEK_END);
	fileLength = ftell(inputFile);
	inputString = (char *)malloc(sizeof(char)*fileLength);
	fseek(inputFile, 0, SEEK_SET);
	while ((inputString[i] = fgetc(inputFile)) != '\n') {
		i++;
	}
	inputString[i] = '\0';
	puts((char *)inputString);
	fgets((char *)inputString, sizeof(inputString), inputFile);
	fclose(inputFile);
	return true;
}

/**
	* @brief Записывает значение в файл по указанному адресу
	*/
bool writeOutputString(char *filePath) {
	bool result = true;
	FILE *outputFile;
	outputFile = fopen(filePath, "w");
	result = fputs(outputString, outputFile);
	return !result;
}

/**
	* @brief Конвертирует строку "hex" в "bin"
	*/
bool hexToBinConvert(void) {
	int i, j=0;
	char delta = 0;
	char *temp;
	outputString = (char *)malloc(sizeof(char)*strlen(inputString)*4);
	for (i = 0; i < strlen(inputString); i++) {
		temp = symbolRecognize(inputString[i]);
		for (j=0; j < 4; j++) {
			outputString[j + delta] = *temp;
			temp++;
		}
		delta += sizeof(char)*4;
	}
	outputString[delta] = '\0';
	puts(outputString);
	return true;
}


/**
	* @brief Определяет символ исходной строки и возвращает указатель на строку состоящюю из 4 симолов
	*/
char* symbolRecognize(char symbol) {
	switch (symbol) {
		case 'A':
			return A;
			break;
		case 'B':
			return B;
		case 'C':
			return C;
		case 'D':
			return D;
		case 'E':
			return E;
		case 'F':
			return F;
		case '0':
			return x0;
		case '1':
			return x1;
		case '2':
			return x2;
		case '3':
			return x3;
		case '4':
			return x4;
		case '5':
			return x5;
		case '6':
			return x6;
		case '7':
			return x7;
		case '8':
			return x8;
		case '9':
			return x9;
		default:
			return (char *)symbol - '0';
	}
}
