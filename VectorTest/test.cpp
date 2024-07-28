#include "pch.h"
#include "C:\Users\FURKAN\source\repos\MyOwnVectorClass\MyOwnVectorClass\vector_class.h"


class ComplexObject {
public:
    ComplexObject(int v = 0) : value(v) {}
    int getValue() const { return value; }
private:
    int value;
};

TEST(VectorTest, Empty_Vector_Size_Check) {
  VectorClass<int> vec;
  vec.push_back(1);
  EXPECT_EQ(vec.size(), 1);
}

TEST(VectorTest, Large_Vector) {
    VectorClass<int> largeVec;
    const int numElements = 1000000;

    for (int i = 0; i < numElements; ++i) {
        largeVec.push_back(i);
    }

	EXPECT_EQ(largeVec.size(), 1000000);
}

TEST(VectorTest, Get_Empty_Vector) {
    VectorClass<int> vec;
    EXPECT_EQ(vec.get(0), NULL);
}

TEST(VectorTest, Delete_Element_Empty_Vector) {
    VectorClass<int> vec;
    vec.pop();
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, Add_And_Remove_Many_Elements_From_Vector) {
    VectorClass<int> vec;
    for (int i = 0; i < 1000; ++i) {
        vec.push_back(i);
    }
    for (int i = 0; i < 1000; ++i) {
        vec.pop();
    }
    EXPECT_EQ(vec.size(), 0);
}

TEST(VectorTest, Add_And_Remove_Complex_Object) {
    VectorClass<ComplexObject> vec;

    for (int i = 0; i < 5; ++i) {
        vec.push_back(ComplexObject(i * 10));
    }

    EXPECT_EQ(vec.get(0).getValue(), 0);
    EXPECT_EQ(vec.get(1).getValue(), 10);
    EXPECT_EQ(vec.get(2).getValue(), 20);
    EXPECT_EQ(vec.get(3).getValue(), 30);
    EXPECT_EQ(vec.get(4).getValue(), 40);
    EXPECT_EQ(vec.size(), 5);
}

TEST(VectorTest, Mixed_actions_In_Vector) {
    VectorClass<int> mixedVec;

    for (int i = 0; i < 10; ++i) {
        mixedVec.push_back(i);
    }

    mixedVec.pop();
    mixedVec.pop();
    EXPECT_EQ(mixedVec.size(), 8);
    mixedVec.push_back(100);
    EXPECT_EQ(mixedVec.size(), 9);
    mixedVec.push(200, 5);
    EXPECT_EQ(mixedVec.get(5), 200);
    mixedVec.pop();
    EXPECT_EQ(mixedVec.size(), 8);
}



