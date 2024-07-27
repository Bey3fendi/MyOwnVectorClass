#include <iostream>
#include <string>
#include <chrono>
#include "vector_class.h"  // Ensure this path is correct

class ComplexObject {
public:
    ComplexObject(int v = 0) : value(v) {}
    int getValue() const { return value; }
private:
    int value;
};

void testLargeVectorPerformance() {
    std::cout << "Testing large vector performance:" << std::endl;
    VectorClass<int> largeVec;
    const int numElements = 1000000;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        largeVec.push_back(i);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << "Time to add " << numElements << " elements: " << diff.count() << " s" << std::endl;
    std::cout << "Final size: " << largeVec.size() << ", capacity: " << largeVec.getcapacity() << std::endl;

    std::cout << std::endl;
}

void testEdgeCases() {
    std::cout << "Testing edge cases:" << std::endl;
    VectorClass<int> edgeVec;

    // Test on empty vector
    std::cout << "Empty vector size: " << edgeVec.size() << std::endl;
    edgeVec.pop();  // Should handle gracefully
    std::cout << "After pop on empty vector, size: " << edgeVec.size() << std::endl;

    // Test get on empty vector
    try {
        edgeVec.get(0);
    }
    catch (...) {
        std::cout << "Caught exception when getting from empty vector" << std::endl;
    }

    // Add and remove many elements
    for (int i = 0; i < 1000; ++i) {
        edgeVec.push_back(i);
    }
    for (int i = 0; i < 1000; ++i) {
        edgeVec.pop();
    }
    std::cout << "After adding and removing 1000 elements, size: " << edgeVec.size()
        << ", capacity: " << edgeVec.getcapacity() << std::endl;

    std::cout << std::endl;
}

void testComplexObject() {
    std::cout << "Testing with complex object:" << std::endl;
    VectorClass<ComplexObject> complexVec;

    for (int i = 0; i < 5; ++i) {
        complexVec.push_back(ComplexObject(i * 10));
    }

    std::cout << "Vector contents:" << std::endl;
    for (size_t i = 0; i < complexVec.size(); ++i) {
        std::cout << "Element " << i << " value: " << complexVec.get(i).getValue() << std::endl;
    }

    std::cout << std::endl;
}

void testMixedOperations() {
    std::cout << "Testing mixed operations:" << std::endl;
    VectorClass<int> mixedVec;

    for (int i = 0; i < 10; ++i) {
        mixedVec.push_back(i);
    }

    mixedVec.pop();
    mixedVec.pop();
    mixedVec.push_back(100);
    mixedVec.push(200, 5);
    mixedVec.pop();

    std::cout << "After mixed operations:" << std::endl;
    mixedVec.print();

    std::cout << std::endl;
}

int main() {
    testLargeVectorPerformance();
    testEdgeCases();
    testComplexObject();
    testMixedOperations();

    return 0;
}