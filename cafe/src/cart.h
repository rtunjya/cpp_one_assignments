#ifndef CART_H_
#define CART_H_

#include <vector>
#include "item.h"

class Cart
{
    public:
    std::vector<Item> items;

    Cart()
    {
        this->items = {};
    }

    void add_to_cart(const Item &item)
    {
        this->items.push_back(item);
    }
};

#endif // CART_H_
