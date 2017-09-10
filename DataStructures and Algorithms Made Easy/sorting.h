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
    void selection_sort(std::vector<T> &array, T size);
    void insertion_sort(std::vector<T> &array, T size);
    void bubble_sort(std::vector<T> &array, T size);
    void merge_sort(T[], T);
    void quick_sort(T[], T);

    std::vector<T> generate_rand_array(std::vector<T> &array, int size);
};


#endif //DATASTRUCTURES_AND_ALGORITHMS_MADE_EASY_SORTING_H
