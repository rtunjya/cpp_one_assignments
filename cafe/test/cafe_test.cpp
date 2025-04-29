#include "../src/cafe.h"

#include <gtest/gtest.h>

#include "../src/item.h"
#include "../src/utils.h"

TEST(CAFE_INVENTORY_ADD_ITEM_TEST, BasicAssertion) {
    Item apple = Item(1.50, "Apple");

    Cafe c = Cafe();

    c.stock_item(apple);

    Item returned = c.get_item("Apple");

    ASSERT_EQ(returned.description, apple.description);
}

TEST(TO_LOWER_TEST, BasicAssertions) {
    std::string s = "TEST";

    std::string s2 = Utils::to_lower(s);
    ASSERT_EQ("test", s2);
}

TEST(CAFE_INVENTORY_ITEM_CASE_SENSITVE_TEST, BasicAssertions) {
    Item apple = Item(1.50, "Apple");

    Cafe c = Cafe();

    c.stock_item(apple);
    Item returned = c.get_item("apple");

    ASSERT_EQ(returned.description, apple.description);
}
