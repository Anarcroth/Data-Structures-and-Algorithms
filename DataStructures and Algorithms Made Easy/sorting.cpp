//
// Created by mdn on 09.09.17.
//

#include <cstdlib>
#include <random>
#include <iostream>

#include "sorting.h"

template<class T>
void sorting<T>::selection_sort(std::vector<T> &array, T size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
            {
                min = j;
            }

            if (min != i)
            {
                T temp = array[min];
                array[min] = array[i];
                array[i] = temp;
            }
        }
    }


    std::cout << "\n\nSelection Sort: \n";

    for (auto it = array.begin(); it != array.end(); it++)
    {
        std::cout << *it << " ";
    }
}

template<class T>
void sorting<T>::bubble_sort(std::vector<T> &array, T size)
{
    std::cout << "Basic Bubble Sort: \n";

    std::vector<T> temp_array = array;
    std::vector<T> temp_array2 = array;

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

    for (auto it = temp_array.begin(); it != temp_array.end(); it++)
    {
        std::cout << *it << " ";
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

    for (auto it = temp_array2.begin(); it != temp_array2.end(); it++)
    {
        std::cout << *it << " ";
    }
}

template<class T>
void sorting<T>::insertion_sort(std::vector<T> &array, T size)
{
    for (int i = 0; i < size; i++)
    {
        int x = array[i];
        int j = i;

        while (array[j - 1] > x && j >= 1)
        {
            array[j] = array[j - 1];
            j--;
        }

        array[j] = x;
    }

    std::cout << "\n\nInsertion Sort: \n";

    for (auto it = array.begin(); it != array.end(); it++)
    {
        std::cout << *it << " ";
    }
}

template<class T>
std::vector<T> sorting<T>::generate_rand_array(std::vector<T> &array, int size)
{
    srand(time(nullptr));

    for (int i = 0; i < size; i++)
    {
        array.push_back((rand() % size) + 1);
    }

    return array;
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

    signed int size;
    std::cout << "Enter a size for the array: ";
    std::cin >> size;

    sorting<int> sort_algthms;

    std::vector<int> array, array2, array3;

    array = sort_algthms.generate_rand_array(array, size);
    array2 = sort_algthms.generate_rand_array(array2, size);
    array3 = sort_algthms.generate_rand_array(array3, size);

    sort_algthms.bubble_sort(array, size);
    sort_algthms.insertion_sort(array2, size);
    sort_algthms.selection_sort(array3, size);

    return 0;
}