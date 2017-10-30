#include <iostream>
#include <math.h>

using namespace std;

const int SIZE = 10000000;

int findNextSimpleNumber(int nextNumber, int simpleNumArr[]);

int main()
{
	cout<<"start calculation"<<'\n';
    time_t startTime = time(0); 
		
	int* simpleNumbersArr = new int[SIZE];
	//	первые 2 простых числа добавляем вручную, 
	//  для удобства построения алгоритма поиска остальных чисел
	simpleNumbersArr[0] = 2; 
	simpleNumbersArr[1] = 3;
	
	int currentItem = simpleNumbersArr[1];		
	int sum = simpleNumbersArr[0] + simpleNumbersArr[1]; 
	for (int i = 2; i < SIZE; i++) 
	{   		
		int val = findNextSimpleNumber(currentItem, simpleNumbersArr);
		currentItem = val;
		simpleNumbersArr[i] = val;					
		sum += val;
    }  
	
    cout<< "sum = " << sum <<'\n';
	cout<< "time =" << time(0) - startTime << '\n';
	
	system("pause");
	return 1;
}

//метод поиска простого числа больше заданного
int findNextSimpleNumber(int currentNumber, int* simpleNumArr)
{
	if ((currentNumber % 2) == 0){
		currentNumber++;
	}
	bool isSimple = false;
	while (!isSimple)
	{
		currentNumber = currentNumber + 2;
		double maxMultiplier = sqrt(currentNumber);
		isSimple = true;	
		
		for (int i = 1; simpleNumArr[i] <= maxMultiplier && isSimple; i++ ){
			int ost = currentNumber % simpleNumArr[i];
			if (ost == 0){
				isSimple = false;				
				break;
			}
		}			
	}
	
	return currentNumber;
}
