#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void printSort_IdNumber(int array[], int size) {
	int i;
	printf(" Sorted numbers :");
	for (i = 0; i < size; ++i) {
		printf("%d ", array[i]);
	}
	printf("\n");
}
void printSort_Name(char array[], int size) {
	int i;
	printf(" Sorted chars : ");
	for (i = 0; i < size; ++i) {
		printf("%c ", array[i]);
	}
	printf("\n");
}
//swap for int
void swap_IdNum(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;

}
//swap for char
void swap_Name(char* x, char* y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

void insertionSort_IdNum(int array[], int x)
{
	int i, key, j;
	for (i = 1; i < x; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}

void insertionSort_Name(char strng[], int x)
{
	int i, j;
	char key;
	for (i = 1; i < x; i++)
	{
		key = strng[i];
		j = i - 1;
		while (j >= 0 && strng[j] > key)
		{
			strng[j + 1] = strng[j];
			j = j - 1;
		}
		strng[j + 1] = key;
	}
}


void selectionSort_IdNumber(int array[], int size) {
	int i, j, currentMin;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin])
				currentMin = j;
		}
		swap_IdNum(&array[currentMin], &array[i]);
	}

}
void selectionSort_Name(char array[], int size) {
	int i, j, currentMin;
	for (i = 0; i < size - 1; ++i) {
		currentMin = i;
		for (j = i + 1; j < size; ++j) {
			if (array[j] < array[currentMin])
				currentMin = j;
		}
		swap_Name(&array[currentMin], &array[i]);
	}

}


void bubbleSort_IdNumber(int array[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap_IdNum(&array[j], &array[j + 1]);
			}
		}
	}
}

void bubbleSort_Name(char array[], int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {
		for (j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap_Name(&array[j], &array[j + 1]);
			}
		}
	}
}


void merge_IdNumber(int arr[], int left, int middle, int right)
{
	int i, j, l = 0;
	int temp[right - left + 1];

	for (i = left, j = middle + 1; (i <= middle) && (j <= right);)
	{
		if (arr[i] < arr[j]) {
			temp[l] = arr[i];
			i++;
			l++;
		}
		else {
			temp[l] = arr[j];
			j++;
			l++;
		}
	}

	while (i <= middle) {
		temp[l] = arr[i];
		i++;
		l++;
	}
	while (j <= right) {
		temp[l] = arr[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		arr[i] = temp[l];
	}

}

void merge_Name(char array[], int left, int middle, int right)
{
	int i, j, l = 0;
	char temp[right - left + 1];

	for (i = left, j = middle + 1; (i <= middle) && (j <= right);)
	{
		if (array[i] < array[j]) {
			temp[l] = array[i];
			i++;
			l++;
		}
		else {
			temp[l] = array[j];
			j++;
			l++;
		}
	}

	while (i <= middle) {
		temp[l] = array[i];
		i++;
		l++;
	}
	while (j <= right) {
		temp[l] = array[j];
		j++;
		l++;
	}
	for (i = left, l = 0; i <= right; i++, l++) {
		array[i] = temp[l];
	}

}
void  mergeSort_IdNumber(int array[], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		mergeSort_IdNumber(array, left, mid);
		mergeSort_IdNumber(array, mid + 1, right);

		merge_IdNumber(array, left, mid, right);

	}
}
void mergeSort_Name(char array[], int left, int right) {
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;

		mergeSort_Name(array, left, mid);
		mergeSort_Name(array, mid + 1, right);
		merge_Name(array, left, mid, right);

	}
}





int main() {


	printf(" tahir berk topcu      2018556065\n");


	//insertion 

	clock_t timer;
	timer = clock();
	int IdNum[] = { 2,0,1,8,5,5,6,0,6,5 };
	char Name[] = "tahir berk topcu";
	int IdNumSize = sizeof(IdNum) / sizeof(IdNum[0]);
	int NameSize = strlen(Name);
	insertionSort_IdNum(IdNum, IdNumSize);
	timer = clock() - timer;
	printSort_IdNumber(IdNum, IdNumSize);
	printf(" Running time of Insertion Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	insertionSort_Name(Name, NameSize);
	timer = clock() - timer;
	printSort_Name(Name, NameSize);
	printf(" Running time of Insertion Sort for Name:%f\n", ((double)(timer)) / CLOCKS_PER_SEC);


	//selection

	int IdNum2[] = { 2,0,1,8,5,5,6,0,6,5 };
	char Name2[] = "tahir berk topcu";
	int IdNumSize2 = sizeof(IdNum2) / sizeof(IdNum2[0]);
	int NameSize2 = strlen(Name2);
	selectionSort_IdNumber(IdNum2, IdNumSize2);
	timer = clock() - timer;
	printSort_IdNumber(IdNum2, IdNumSize2);
	printf(" Running time of Selection Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	selectionSort_Name(Name2, NameSize2);
	timer = clock() - timer;
	printSort_Name(Name2, NameSize2);
	printf(" Running time of Selection Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);


	//merge

	int IdNum3[] = { 2,0,1,8,5,5,6,0,6,5 };
	char Name3[] = "tahir berk topcu";
	int IdNumSize3 = sizeof(IdNum3) / sizeof(IdNum3[0]);
	int NameSize3 = strlen(Name3);
	mergeSort_IdNumber(IdNum3, 0, IdNumSize3 - 1);
	timer = clock() - timer;
	printSort_IdNumber(IdNum3, IdNumSize3);
	printf(" Running time of Merge Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	mergeSort_Name(Name3, 0, NameSize3 - 1);
	timer = clock() - timer;
	printSort_Name(Name3, NameSize3);
	printf(" Running time of Merge Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);



	//bubble

	int IdNum4[] = { 2,0,1,8,5,5,6,0,6,5 };
	char Name4[] = "tahir berk topcu";
	int IdNumSize4 = sizeof(IdNum4) / sizeof(IdNum4[0]);
	int NameSize4 = strlen(Name4);
	bubbleSort_IdNumber(IdNum4, IdNumSize4);
	timer = clock() - timer;
	printSort_IdNumber(IdNum4, IdNumSize4);
	printf(" Running time of Bubble Sort for ID Number: %f\n", ((double)(timer)) / CLOCKS_PER_SEC);

	bubbleSort_Name(Name4, NameSize4);
	timer = clock() - timer;
	printSort_Name(Name4, NameSize4);
	printf(" Running time of Bubble Sort for name: %f\n\n", ((double)(timer)) / CLOCKS_PER_SEC);




	return 0;
}