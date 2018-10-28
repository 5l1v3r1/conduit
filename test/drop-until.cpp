#include "gtest/gtest.h"
#include <conduit/count.hpp>
#include <conduit/drop-until.hpp>

using namespace conduit;

TEST(Seq, dropUntil) {
  auto i = 4;
  
  auto transform = dropUntil([](auto x) { 
    return x > 3; 
  });
  
  for (auto x : transform(count(0))) {
    EXPECT_EQ(i, x);
    ++i;
    if (i == 8) 
      break;
  }

  EXPECT_EQ(i, 8);
}

