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
    void selection_sort(T *array, T size);
    void insertion_sort(T *array, T size);
    void bubble_sort(T array[], T size);
    void merge_sort(T[], T);
    void quick_sort(T[], T);

    T* generate_rand_array(T *array, int size);
};


#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
