#include "iostream"



#ifndef OOPPRACTICE_ARRAY_H
#define OOPPRACTICE_ARRAY_H

template <class number>
class Array {
private:
    int length;
    number *arr;

public:
    Array(int length = 0);

    ~Array();

    int getLength();

    number getElem(int index);

    void fill();

    void pushBack(number elem);

    bool resize(int length);

    bool changeElement(int index, number value);

    void printArray();

    number averageValue();

    number SKO();

    void shakerSort(bool reverse = false);

};

template <class number>
Array<number>::Array(int length){
    if (length < 0){
        this->length = 0;
        std::cout << "Неверно введена длина\n"
                "длина = 0";
    }
    this->length = length;
    arr = new number[length];
}

template <class number>
Array<number>::~Array() {
    delete []arr;
}

template <class number>
int Array<number>::getLength() {
    return this->length;
}

template <class number>
void Array<number>::fill() {
    for (int i = 0; i < length; i++) {
       std::cin >> *(arr + i);
    }
}


template <class number>
bool Array<number>::resize(int newLength) {
    if (newLength < 0){
        return false;
    }
    number* resizeArr = new number[newLength];
    for(int i = 0; i < newLength; i++){
        *(resizeArr + i) = *(arr + i);
    }
    length = newLength;
    delete []arr;
    arr = resizeArr;
    return true;
}

template <class number>
void Array<number>::pushBack(number elem) {
    resize(getLength() + 1);
    *(arr + getLength() - 1) = elem;
}

template <class number>
bool Array<number>::changeElement(int index, number value) {
    if(index >= length && index <= 0){
        return false;
    }
    *(arr + index) = value;
    return true;
}

template <class number>
number Array<number>::getElem(int index) {
    return *(arr + index);
}

template <class number>
void Array<number>::printArray() {
    std::cout << "Массив: ";
    for(int i = 0; i < length; i++){
        std::cout<< *(arr + i) << " ";
    }
    std::cout << "\n";
}

template <class number>
number Array<number>::averageValue() {
    number sum = 0;
    if (length == 0){
        return sum;
    }
    for(int i = 0; i < length; i++){
        sum += *(arr + i);
    }
    sum /= ((double)length);
    return sum;
}

template <class number>
number Array<number>::SKO() {
    number avg = averageValue();
    number skoValue = 0;
    if (length <= 1){
        return skoValue;
    }
    for(int i = 0; i < length; i++){
        skoValue += pow( *(arr + i) - avg, 2);
    }
    skoValue /= ((double)length - 1);
    skoValue = pow(skoValue, 0.5);
    return skoValue;
}

template <class number>
void Array<number>::shakerSort(bool reverse) {
    bool swapped = true;
    int start = 0;
    int end = length - 1;

    while (swapped) {
        swapped = false;

        if(!reverse){
            for (int i = start; i < end; ++i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }else{
            for (int i = start; i < end; ++i) {
                if (arr[i] < arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }

        if (!swapped) {
            break;
        }

        swapped = false;
        --end;

        if(!reverse){
            for (int i = end - 1; i >= start; --i) {
                if (arr[i] > arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }else{
            for (int i = end - 1; i >= start; --i) {
                if (arr[i] < arr[i + 1]) {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        }

        ++start;
    }
}


#endif
