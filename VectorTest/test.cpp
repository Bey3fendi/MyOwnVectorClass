#include "pch.h"
#include "C:\Users\FURKAN\source\repos\MyOwnVectorClass\MyOwnVectorClass\vector_class.h"

TEST(VectorTest, Empty_Vector_Size_Check) {
  VectorClass<int> vec;
  vec.push_back(1);
  EXPECT_EQ(vec.size(), 1);
}