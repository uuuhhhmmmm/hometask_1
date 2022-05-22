#include <iostream>
#include "sort.h"
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

const char* SortFiles[7] = {"BubbleSort.txt","InsertionSort.txt","SelectionSort",
                            "QuickSort.txt","ShellSort.txt",
                            "merge_sort_ascending.txt", "GnomeSort.txt"};
void (*SortIndex[7])(int*, int) = {BubbleSort,InsertionSort,SelectionSort,
                                   QuickSort,ShellSort, merge_sort_ascending, GnomeSort};

int main() {
    ofstream file[7];
    float k = 1.75;
    for(int i = 0; i < 7; i++){
        file[i].open(SortFiles[i], ios::out);
        int size = 100;
        unsigned long long TimeTotal_ms = 0;
        while(TimeTotal_ms <1e7){
            int* array = new int[size];
            FillRandom(array, size);
            int* copy1 = new int[size];
            int* copy2 = new int[size];
            memcpy(copy1, array, size);
            memcpy(copy2, array, size);
            auto start = high_resolution_clock::now();
            SortIndex[i](copy1, size);
            SortIndex[i](copy2, size);
            auto stop = high_resolution_clock::now();
            TimeTotal_ms = duration_cast<microseconds>(stop-start).count();
            TimeTotal_ms /=2;
            file[i] << size << "\t" << TimeTotal_ms << "\n";
            delete[] array;
            delete[] copy1;
            delete[] copy2;
            size *= k;
        }
        file[i].close();
    }
    return 0;
}
