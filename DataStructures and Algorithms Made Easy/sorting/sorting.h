//
// Created by mdn on 09.09.17.
//

#ifndef DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
#define DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H

template<class T>
class sorting
{
private:
public:
    std::vector <T> generate_rand_array(std::vector <T> &array, int size);

    void selection_sort(std::vector <T> &array, T size);

    void insertion_sort(std::vector <T> &array, T size);

    void bubble_sort(std::vector <T> &array, T size);

    int partition(std::vector <T> &array, int low, int high);

    void quick_sort(std::vector <T> &array, int low, int high);

    void swap(T *low, T *high);

    void merge(std::vector <T> &array, int left, int middle, int right);

    void merge_sort(std::vector <T> &array, int left, int right);

    void display(std::vector <T> &array);
};


#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
