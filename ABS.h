//
// Created by huang on 5/28/2024.
//

#pragma once
using namespace std;

template<typename T>

class ABS {
private:
    int maxCap;
    int currSize;
    float scale = 2.0;
    T *array;

public:
    ABS() {
        maxCap = 1;
        currSize = 0;
        array = new T[maxCap];
    }

    ABS(int capacity) {
        maxCap = capacity;
        currSize = 0;
        array = new T[maxCap];
    }

    ABS(const ABS &d) {
        maxCap = d.getMaxCapacity();
        currSize = d.getSize();
        array = d.getData();
    }

    ABS &operator=(const ABS &d) {
        if(this != &d) {
            maxCap = d.getMaxCapacity();
            currSize = d.getSize();
            array = d.getData();
        }
        return *this;
    }

    ~ABS() {
        delete[] array;
    }

    void push(T data) {
        if(currSize == maxCap) {
            maxCap = maxCap*scale;
            T *newArray = new T[maxCap];

            for(int i = 0; i < currSize; i++) {
              newArray[i] = array[i];
            }

            delete[] array;
            array = newArray;

        }

        array[currSize] = data;
        currSize += 1;

    }

    T pop() {
        if(currSize == 0) {
            throw runtime_error("Stack is empty");
        }

        T element = array[currSize-1];
        array[currSize-1] = T();
        currSize -= 1;

        if((float(currSize)/maxCap) < (1/scale)) {
            maxCap = maxCap/scale;
            T *newArray =  new T[maxCap];

            for(int i = 0; i < currSize; i++) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }

        return element;
    }

    T peek() {
        if(currSize == 0) {
            throw runtime_error("Stack is empty");
        }
        return array[currSize-1];
    }

    unsigned int getSize() {
        return currSize;
    }

    unsigned int getMaxCapacity() {
        return maxCap;
    }

    T* getData() {
        return array;
    }

};
