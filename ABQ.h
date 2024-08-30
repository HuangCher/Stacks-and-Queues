//
// Created by huang on 5/30/2024.
//

#pragma once
using namespace std;

template<typename T>

class ABQ {
private:
    int maxCap;
    int currSize;
    float scale = 2.0;
    T *array;

public:
    ABQ() {
        maxCap = 1;
        currSize = 0;
        array = new T[maxCap];
    }

    ABQ(int capacity) {
        maxCap = capacity;
        currSize = 0;
        array = new T[maxCap];
    }

    ABQ(const ABQ &d) {
        maxCap = d.getMaxCapacity();
        currSize = d.getSize();
        array = d.getData();
    }

    ABQ &operator=(const ABQ &d) {
        if(this != &d) {
            maxCap = d.getMaxCapacity();
            currSize = d.getSize();
            array = d.getData();
        }
        return *this;
    }

    ~ABQ() {
        delete[] array;
    }

    void enqueue(T data) {
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

    T dequeue() {
        if(currSize == 0) {
            throw runtime_error("Stack is empty");
        }

        T element = array[0];
        array[0] = T();
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

        for(int i = 0; i < currSize; i++) {
            array[i] = array[i+1];
        }

        return element;
    }

    T peek() {
        if(currSize == 0) {
            throw runtime_error("Stack is empty");
        }
        return array[0];
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
