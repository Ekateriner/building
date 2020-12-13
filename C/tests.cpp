#include <gtest/gtest.h>
#include "A/index.h"
#include "B/lib.h"

template <typename T>
class ListTestCase : public ::testing::Test {};

template <typename T>
class ObjectTestCase : public ::testing::Test {};

typedef ::testing::Types<int, float, double> MyTypes;
TYPED_TEST_CASE(ListTestCase, MyTypes);

TYPED_TEST(ListTestCase, create) {
    List<TypeParam> list;
    list.push_back(0);
    list.push_back(1);
    ASSERT_EQ(list.pop_back(), 1);
}

TYPED_TEST_CASE(ObjectTestCase, MyTypes);
TYPED_TEST(ObjectTestCase, change){
    Object<TypeParam> obj;
    obj.set(0);
    obj.set(1);
    ASSERT_EQ(obj.get(), 1);
}