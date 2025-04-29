#ifndef CAFE_H_
#define CAFE_H_

#include <ctype.h>

#include <stdexcept>
#include <vector>

#include "item.h"
#include "utils.h"
#include <iostream>

// stock inventory
// choose specific items
// checkout

class Cafe {
   private:
    std::vector<Item> *items;

   public:
    Cafe() { this->items = new std::vector<Item>(); };

    ~Cafe() { delete this->items; };

    void stock_item(const Item &item) {
        this->items->push_back(item);
    }

    Item get_item(const std::string &name) {
        std::string search_text = Utils::to_lower(name);
        std::cout << search_text << std::endl;
        for (Item i : *this->items) {
            if (i.description == search_text) {
                return i;
            }
        }
        throw std::runtime_error("No Item Found");
    }
};

#endif  // CAFE_H_
