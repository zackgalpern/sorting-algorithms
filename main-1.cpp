#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <chrono>
using namespace std;
using namespace::chrono;

void readFile(ifstream& file, int array[], int size) {
    int count = 0;
    int x;

    while (count < size && file >> x)
        array[count++] = x;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[(high+low)/2];
    int i = (low - 1);

    for(int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return (i+1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int index = partition(arr, low, high);

        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
        //cout << arr[index] << endl;
    }
}

void insertionSort(int arr[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = arr[i];
        j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int n) {
    int j, min_index;

    for(int i = 0; i < n-1; i++) {
        min_index = i;
        for(j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[min_index], arr[i]);
    }
}


int main() {
    ifstream k_10_1_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_1.txt");
    ifstream k_10_1_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_1.txt");
    ifstream k_10_1_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_1.txt");

    int arr1_1[10000];
    int arr1_2[10000];
    int arr1_3[10000];
    int size1 = sizeof(arr1_1) / sizeof(arr1_1[0]);

    readFile(k_10_1_1, arr1_1, size1);
    readFile(k_10_1_2, arr1_2, size1);
    readFile(k_10_1_3, arr1_3, size1);

    cout << "10000 ELEMENTS - RANDOM" << endl;

    clock_t time1 = clock();
    insertionSort(arr1_1, size1);
    clock_t time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr1_2, size1);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr1_3, 0, 10000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_10_2_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_2.txt");
    ifstream k_10_2_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_2.txt");
    ifstream k_10_2_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_2.txt");
    int arr2_1[10000];
    int arr2_2[10000];
    int arr2_3[10000];
    int size2 = sizeof(arr2_1) / sizeof(arr2_1[0]);

    cout << "10000 - Ascending" << endl;

    readFile(k_10_2_1, arr2_1, size2);
    readFile(k_10_2_2, arr2_2, size2);
    readFile(k_10_2_3, arr2_3, size2);

    time1 = clock();
    insertionSort(arr2_1, size2);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr2_2, size2);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr2_3, 0, 10000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_10_3_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_3.txt");
    ifstream k_10_3_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_3.txt");
    ifstream k_10_3_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data10000_3.txt");
    int arr3_1[10000];
    int arr3_2[10000];
    int arr3_3[10000];
    int size3 = sizeof(arr3_1) / sizeof(arr3_1[0]);

    cout << "10000 - Descending" << endl;

    readFile(k_10_3_1, arr3_1, size3);
    readFile(k_10_3_2, arr3_2, size3);
    readFile(k_10_3_3, arr3_3, size3);

    time1 = clock();
    insertionSort(arr3_1, size3);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr3_2, size3);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr3_3, 0, 10000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;

    ifstream k_20_1_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_1.txt");
    ifstream k_20_1_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_1.txt");
    ifstream k_20_1_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_1.txt");
    int arr4_1[20000];
    int arr4_2[20000];
    int arr4_3[20000];
    int size4 = sizeof(arr4_1) / sizeof(arr4_1[0]);

    cout << "20000 - Random" << endl;

    readFile(k_20_1_1, arr4_1, size4);
    readFile(k_20_1_2, arr4_2, size4);
    readFile(k_20_1_3, arr4_3, size4);

    time1 = clock();
    insertionSort(arr4_1, size4);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr4_2, size4);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr4_3, 0, 20000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_20_2_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_2.txt");
    ifstream k_20_2_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_2.txt");
    ifstream k_20_2_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_2.txt");
    int arr5_1[20000];
    int arr5_2[20000];
    int arr5_3[20000];
    int size5 = sizeof(arr5_1) / sizeof(arr5_1[0]);

    cout << "20000 - Ascending" << endl;

    readFile(k_20_2_1, arr5_1, size5);
    readFile(k_20_2_2, arr5_2, size5);
    readFile(k_20_2_3, arr5_3, size5);

    time1 = clock();
    insertionSort(arr5_1, size5);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr5_2, size5);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr5_3, 0, 20000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_20_3_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_3.txt");
    ifstream k_20_3_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_3.txt");
    ifstream k_20_3_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data20000_3.txt");
    int arr6_1[20000];
    int arr6_2[20000];
    int arr6_3[20000];
    int size6 = sizeof(arr6_1) / sizeof(arr6_1[0]);

    cout << "20000 - Descending" << endl;

    readFile(k_20_3_1, arr6_1, size6);
    readFile(k_20_3_2, arr6_2, size6);
    readFile(k_20_3_3, arr6_3, size6);

    time1 = clock();
    insertionSort(arr6_1, size6);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr6_2, size6);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr6_3, 0, 20000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_50_1_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_1.txt");
    ifstream k_50_1_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_1.txt");
    ifstream k_50_1_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_1.txt");
    int arr7_1[50000];
    int arr7_2[50000];
    int arr7_3[50000];
    int size7 = sizeof(arr7_1) / sizeof(arr7_1[0]);

    cout << "50000 - Random" << endl;

    readFile(k_50_1_1, arr7_1, size7);
    readFile(k_50_1_2, arr7_2, size7);
    readFile(k_50_1_3, arr7_3, size7);

    time1 = clock();
    insertionSort(arr7_1, size7);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr7_2, size7);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr7_3, 0, 50000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_50_2_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_2.txt");
    ifstream k_50_2_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_2.txt");
    ifstream k_50_2_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_2.txt");
    int arr8_1[50000];
    int arr8_2[50000];
    int arr8_3[50000];
    int size8 = sizeof(arr8_1) / sizeof(arr8_1[0]);

    cout << "50000 - Ascending" << endl;

    readFile(k_50_2_1, arr8_1, size8);
    readFile(k_50_2_2, arr8_2, size8);
    readFile(k_50_2_3, arr8_3, size8);

    time1 = clock();
    insertionSort(arr8_1, size8);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr8_2, size8);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr8_3, 0, 50000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;

    ifstream k_50_3_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_3.txt");
    ifstream k_50_3_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_3.txt");
    ifstream k_50_3_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data50000_3.txt");
    int arr9_1[50000];
    int arr9_2[50000];
    int arr9_3[50000];
    int size9 = sizeof(arr9_1) / sizeof(arr9_1[0]);

    cout << "50000 - Descending" << endl;

    readFile(k_50_3_1, arr9_1, size9);
    readFile(k_50_3_2, arr9_2, size9);
    readFile(k_50_3_3, arr9_3, size9);

    time1 = clock();
    insertionSort(arr9_1, size9);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr9_2, size9);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr9_3, 0, 50000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_100_1_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_1.txt");
    ifstream k_100_1_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_1.txt");
    ifstream k_100_1_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_1.txt");
    int arr10_1[100000];
    int arr10_2[100000];
    int arr10_3[100000];
    int size10 = sizeof(arr10_1) / sizeof(arr10_1[0]);

    cout << "100000 - Random" << endl;

    readFile(k_100_1_1, arr10_1, size10);
    readFile(k_100_1_2, arr10_2, size10);
    readFile(k_100_1_3, arr10_3, size10);

    time1 = clock();
    insertionSort(arr10_1, size10);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr10_2, size10);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr10_3, 0, 100000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;


    ifstream k_100_2_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_2.txt");
    ifstream k_100_2_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_2.txt");
    ifstream k_100_2_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_2.txt");
    int arr11_1[100000];
    int arr11_2[100000];
    int arr11_3[100000];
    int size11 = sizeof(arr11_1) / sizeof(arr11_1[0]);

    cout << "100000 - Ascending" << endl;

    readFile(k_100_2_1, arr11_1, size11);
    readFile(k_100_2_2, arr11_2, size11);
    readFile(k_100_2_3, arr11_3, size11);

    time1 = clock();
    insertionSort(arr11_1, size11);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr11_2, size11);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr11_3, 0, 100000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    cout << endl;

    ifstream k_100_3_1("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_3.txt");
    ifstream k_100_3_2("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_3.txt");
    ifstream k_100_3_3("/Users/zackgalpern/Desktop/Data Structures Projects/SortingAnalysis/data100000_3.txt");
    int arr12_1[100000];
    int arr12_2[100000];
    int arr12_3[100000];
    int size12 = sizeof(arr12_1) / sizeof(arr12_1[0]);

    cout << "100000 - Descending" << endl;

    readFile(k_100_3_1, arr12_1, size12);
    readFile(k_100_3_2, arr12_2, size12);
    readFile(k_100_3_3, arr12_3, size12);

    time1 = clock();
    insertionSort(arr12_1, size12);
    time2 = clock();
    cout << "Insertion Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    selectionSort(arr12_2, size12);
    time2 = clock();
    cout << "Selection Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

    time1 = clock();
    quickSort(arr12_3, 0, 100000);
    time2 = clock();
    cout << "QuickSort Time: " << ((float)(time2 - time1)/CLOCKS_PER_SEC) << " seconds" << endl;

}
