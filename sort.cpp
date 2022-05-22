

#include "sort.h"
#include <cstdlib>
#include <set>
#include <ctime>


void BubbleSort(int* array, int size){
    int temp;
    for(int i = 0; i<size; i++) {
        for(int j = i+1; j<size; j++)
        {
            if(array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
void InsertionSort(int* array, int size){
    for(int k=1; k<size; k++)
    {
        int temp = array[k];
        int j= k-1;
        while(j>=0 && temp <= array[j])
        {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
    }
}
int SmallestPosition(int* array,int i, int size){
    int ele_small,position,j;
    ele_small = array[i];
    position = i;
    for(j=i+1;j<size;j++)
    {
        if(array[j]<ele_small)
        {
            ele_small = array[j];
            position=j;
        }
    }
    return position;
}
void SelectionSort(int* array, int size){
    int pos,temp,pass=0;
    for(int i=0;i<10;i++)
    {
        pos = SmallestPosition(array, i, size);
        temp = array[i];
        array[i]=array[pos];
        array[pos] = temp;
        pass++;
    }
}
void merge_sort_ascending(int *a, int n){
    int step = 1;  // шаг разбиения последовательности
    int *temp = (int*)malloc(n * sizeof(int)); // дополнительный массив
    while (step < n)  // пока шаг меньше длины массива
    {
        int index = 0;    // индекс результирующего массива
        int l = 0;      // левая граница участка
        int m = l + step;  // середина участка
        int r = l + step * 2;  // правая граница участка
        do
        {
            m = m < n ? m : n;  // сортируемый участок не выходит за границы последовательности
            r = r < n ? r : n;
            int i1 = l, i2 = m; // индексы сравниваемых элементов
            for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
            {
                if (a[i1] < a[i2]) { temp[index++] = a[i1++]; } // заполняем участок результирующей последовательности
                else { temp[index++] = a[i2++]; }
            }
            // Или i1 < m или i2 < r - только один из операторов while может выполниться
            while (i1 < m) temp[index++] = a[i1++]; // заносим оставшиеся элементы сортируемых участков
            while (i2 < r) temp[index++] = a[i2++]; // в результирующий массив
            l += step * 2; // перемещаемся на следующий сортируемый участок
            m += step * 2;
            r += step * 2;
        } while (l < n); // пока левая граница сортируемого участка - в пределах последоватльности
        for (int i = 0; i < n; i++) // переносим сформированный массив обратно в a
            a[i] = temp[i];
        step *= 2; // увеличиваем в 2 раза шаг разбиения
    }
}
void QuickSort(int* a, int _size){
    int last = _size-1;
    int first = 0;
    if (first < last)
    {
        int left = first;
        int right = last;
        int middle = a[_size / 2];

        do
        {
            while (a[left] < middle)
            {
                left++;
            }
            while (a[right] > middle)
            {
                right--;
            }

            if (left <= right)
            {
                int tmp = a[left];
                a[left] = a[right];
                a[right] = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        if (right > 0)
        {
            QuickSort(a, right+1);
        }
        if (left < _size)
        {
            QuickSort(&a[left], _size-left);
        }
    }
}
void ShellSort(int* array, int size){
    for(int step = size/2; step > 0; step /= 2)
    {
        for (int i = step; i < size; i += 1)
        {
            int j = i;
            while(j >= step && array[j - step] > array[i])
            {
                swap(array[j], array[j - step]);
                j-=step;
            }
        }
    }
}
void GnomeSort(int* array, int size){
    for ( int i = 1; i < size; ) {
        if ( array[i-1] <= array[i] ) {
            ++i;
        }
        else {
            std::swap( array[i-1], array[i] );
            --i;
            if ( i == 0 ) {
                i = 1;
            }
        }
    }
}
void FillRandom(int* array, int size){
    srand(time(0));
    for(int i = 0; i< size; i++)
        array[i] = rand();
}
