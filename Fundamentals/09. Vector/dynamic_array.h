#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

	typedef struct {
    		int *data;       
    		size_t size;     
    		size_t capacity; 
	} DynamicArray;

	void initArray(DynamicArray *arr, size_t initial_capacity);
	void push_back(DynamicArray *arr, int value);
	void insert(DynamicArray *arr, size_t index, int value);
	void erase(DynamicArray *arr, size_t index);
	void printArray(DynamicArray *arr);
	void freeArray(DynamicArray *arr);

