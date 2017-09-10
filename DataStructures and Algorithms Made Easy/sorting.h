//
// Created by mdn on 09.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H

template <class T>
class sorting
{
private:
public:
    std::vector<T> generate_rand_array(std::vector<T> &array, int size);

    void quick_sort(std::vector<T> &array, int low, int high);
    void selection_sort(std::vector<T> &array, T size);
    void insertion_sort(std::vector<T> &array, T size);
    void bubble_sort(std::vector<T> &array, T size);
    void swap(T *low, T *high);
    void merge_sort(T[], T);

    int partition(std::vector<T> &array, int low, int high);
};


#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
