//
// Created by mdn on 09.09.17.
//

#include <cstdlib>
#include <random>
#include <iostream>

#include "sorting.h"

template<class T>
void sorting<T>::selection_sort(T *array, T size)
{
    int min;

    for (int i = 0; i < size -1; i++)
    {
        min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }

            T temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}

template<class T>
void sorting<T>::bubble_sort(T *array, T size)
{
    std::cout << "Basic Bubble Sort: \n";

    T *temp_array = array;
    T *temp_array2 = array;

    for (int pass = size - 1; pass >= 0; pass--)
    {
        for (int i = 0; i <= pass - 1; i++)
        {
            if (temp_array[i] > temp_array[i + 1])
            {
                T temp = temp_array[i];
                temp_array[i] = temp_array[i + 1];
                temp_array[i + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << temp_array[i] << " ";
    }

    std::cout << "\n\nOptimized Bubble Sort: \n";
    T pass, i, temp, swapped = 1;
    for (pass = size - 1; pass >= 0 && swapped; pass--)
    {
        swapped = 0;
        for (int i = 0; i <= pass - 1; i++)
        {
            if (temp_array2[i] > temp_array2[i + 1])
            {
                temp = temp_array2[i];
                temp_array2[i] = temp_array2[i + 1];
                temp_array2[i + 1] = temp;

                swapped = 1;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        std::cout << temp_array2[i] << " ";
    }
}

template<class T>
T* sorting<T>::generate_rand_array(T *array, int size)
{
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % size) + 1;
    }

    return array;
}

template<class T>
void sorting<T>::insertion_sort(T *array, T size)
{
    for (int i = 0; i < size; i++)
    {
        int x = array[i];
        int j = i;
        while (array[j - 1])
    }
}

int main()
{
    // This is the proper way to generate a random number in C++11, but for some reason an inconsistent segmentation
    // fault is happening whilst initializing the random_device.
    /*
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 10.0);

         for (int i=0; i<16; ++i)
             std::cout << dist(mt) << "\n";
     */

    int size;
    std::cout << "Enter a size for the array: ";
    std::cin >> size;

    sorting<int> sort_algthms;

    int *array;
    array = sort_algthms.generate_rand_array(array, size);

    sort_algthms.bubble_sort(&*array, size);

    return 0;
}