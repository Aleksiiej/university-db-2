#include "Menu.hpp"
#include "DatabaseMock.hpp"
#include <gtest/gtest.h>
class MenuFixture : public ::testing::Test {
public:
  testing::NiceMock<DatabaseMock> db;
  Menu menu{db};
};
