#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include <vector>
#include <algorithm>
#include <numeric>

#include "Algorithms/Sorting/BubbleSort.h"

using namespace testing;

TEST(BubbleSort, ItemsInDescendingOrder)
{
    const size_t elementsCount = 10;
    std::vector<int> data(elementsCount);
    std::iota(data.rbegin(), data.rend(), 0);

    bubbleSort(data);
    EXPECT_THAT(data, WhenSortedBy(std::less<int>(), data));
}
