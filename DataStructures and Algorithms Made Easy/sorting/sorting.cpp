/**
 * COS: FDS
 * sorting.cpp
 * Purpose: Sort a vector of integers using multiple sorting algorithms
 *
 * @author: Martin Nestorov
 * @version: 0.1.0 12/09/2017
 */

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
}

template<class T>
void sorting<T>::quick_sort(std::vector<T> &array, int low, int high)
{
    if (high > low)
    {
        int pivot = partition(array, low, high);
        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}

template<class T>
int sorting<T>::partition(std::vector<T> &array, int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

template<class T>
void sorting<T>::swap(T *low, T *high)
{
    int t = *low;
    *low = *high;
    *high = t;
}

template<class T>
void sorting<T>::merge_sort(std::vector<T> &array, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        merge_sort(array, left, middle);
        merge_sort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

template<class T>
void sorting<T>::merge(std::vector<T> &array, int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<T> L(n1), R(n2);

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];

    for (j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        } else
        {
            array[k] = R[j];
            j++;
        }

        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
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

template<class T>
void sorting<T>::display(std::vector<T> &array)
{
    for (int &it : array)
    {
        std::cout << it << " ";
    }
}
/*
int main()
{
    // This is the proper way to generate a random number in C++11 and above.
    /*
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_real_distribution<double> dist(1.0, 10.0);

         for (int i=0; i<16; ++i)
             std::cout << dist(mt) << "\n";
     *//*

    signed int size;
    std::cout << "Enter a size for the array: ";
    std::cin >> size;

    sorting<int> sort_algthms;

    std::vector<int> array, array2, array3, array4, array5;

    array = sort_algthms.generate_rand_array(array, size);
    array2 = sort_algthms.generate_rand_array(array2, size);
    array3 = sort_algthms.generate_rand_array(array3, size);
    array4 = sort_algthms.generate_rand_array(array4, size);
    array5 = sort_algthms.generate_rand_array(array5, size);

    sort_algthms.bubble_sort(array, size);

    std::cout << "\n\nInsertion Sort: \n";
    sort_algthms.insertion_sort(array2, size);
    sort_algthms.display(array2);

    std::cout << "\n\nSelection Sort: \n";
    sort_algthms.selection_sort(array3, size);
    sort_algthms.display(array3);

    std::cout << "\n\nQuick Sort: \n";
    sort_algthms.quick_sort(array4, 0, size);
    sort_algthms.display(array4);

    std::cout << "\n\nMerge Sort: \n";
    sort_algthms.merge_sort(array5, 0, size - 1);
    sort_algthms.display(array5);

    return 0;
}*/