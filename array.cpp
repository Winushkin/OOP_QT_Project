#include "array.h"
#include "iostream"



Array::Array(int length){
    if (length < 0){
        this->length = 0;
        cout << "Неверно введена длина\n"
                     "длина = 0";
    }
    this->length = length;
    arr = new number[length];
}


Array::~Array() {
    delete []arr;
}


int Array::getLength() {
    return this->length;
}


void Array::fill() {
    for (int i = 0; i < length; i++) {
        cin >> *(arr + i);
    }
}


bool Array::resize(int newLength) {
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


bool Array::changeElement(int index, number value) {
    if(index >= length && index <= 0){
        return false;
    }
    *(arr + index) = value;
    return true;
}


void Array::printArray() {
    std::cout << "Массив: ";
    for(int i = 0; i < length; i++){
        cout<< *(arr + i) << " ";
    }
    std::cout << "\n";
}


number Array::averageValue() {
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


number Array::SKO() {
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


void Array::shakerSort(bool reverse) {
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
