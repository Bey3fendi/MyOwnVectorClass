#pragma once
#include <iostream>

template<typename T> class VectorClass {
public:
	//default constructor which get initial capacity from heap memory which it is 1
	//also initialize the starting values of capacitiy en num of elements
	VectorClass() : array_(new T[1]), vector_capacity_(1), vector_current_num_of_elements_(0) {
		
	}
	//default destructor for delete the allocated memory when the out of scope happened
	//for prevent the memory leakage!
	~VectorClass() { delete[] array_; }

	//needed functions are down below

	/// <summary>
	/// insert the taken element to the last
	/// <summary>
	/// data: element which want to inserted into the vector
	void push_back(const T& data) 
	{
		try {
			if (vector_capacity_ > vector_current_num_of_elements_) {
				array_[vector_current_num_of_elements_] = data;
				vector_current_num_of_elements_++;
			}
			else {
				size_increment();
				array_[vector_current_num_of_elements_] = data;
				vector_current_num_of_elements_++;
			}
		} catch(...) { // refector this part with more appopriate error handling
			std::cerr << "There is a problem!" << std::endl;
		}
	}

	/// <summary>
	/// insert the taken element to the specified index
	/// <summary>
	/// data: element which want to inserted into the vector
	/// <summary>
	/// index: which index will be element added
	void push(const T& data, const int& index) {
		try {
			if (index < vector_capacity_) {
				array_[index] = data;
			}
		}
		catch (...) {
			std::cerr << "there is a problem" << std::endl;
		}
	}

	/// <summary>
	/// get the element in specified index
	/// <summary>
	/// index: which index will be get from vector
	T get(const int& index) {
		T value{};

		if (vector_current_num_of_elements_ != 0) {
			try {
				if (index < vector_capacity_) {
					value = array_[index];
				}
			}
			catch (...) {
				std::cerr << "there is a problem" << std::endl;
			}
			return value;
		}
		else {
			return NULL;
		}
	}

	/// <summary>
	/// delete the last element in vector
	void pop() {
		delete_last_element();
	}

	/// <summary>
	/// get the current size of the vector
	size_t size() {
		return vector_current_num_of_elements_;
	}

	/// <summary>
	/// get the current max capacity of the vector
	size_t getcapacity() {
		return vector_capacity_;
	}

	/// <summary>
	/// check vector empty or not!
	void empty() {
		return vector_current_num_of_elements_ == 0;
	}

	/// <summary>
	/// print the vector elements
	void print() {
		for (int i = 0; i < vector_current_num_of_elements_; ++i) 
		{
			std::cout << "index: " << i << " " << "value: " << array_[i] << std::endl;
		}
	}

private:
	/// <summary>
	/// increase the size of vector
	void size_increment()
	{
		size_t new_capacity = vector_capacity_ * 2;
		T* new_array = new T[new_capacity];

		for (size_t i = 0; i < vector_current_num_of_elements_; ++i) {
			new_array[i] = array_[i];
		}

		delete[] array_;
		array_ = new_array;
		vector_capacity_ = new_capacity;
	}

	void delete_last_element()
	{
		if (vector_current_num_of_elements_ == 0) {
			return;
		}

		T* new_array = new T[vector_capacity_];
		int64_t current_num_of_elements = vector_current_num_of_elements_;

		for (size_t i = 0; i < (current_num_of_elements - 1); ++i) {
			new_array[i] = array_[i];
		}

		delete[] array_;
		array_ = new_array;
		vector_current_num_of_elements_--;
	}

	//int pointer which will be stored the address of the vector!
	T* array_; 
    
	//capacity mean the total storage the vector have
	size_t vector_capacity_;

	size_t vector_current_num_of_elements_;
};
