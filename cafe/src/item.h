#ifndef ITEM_H_
#define ITEM_H_

#include <utils.h>

#include <string>

class Item {
   public:
    float price;
    std::string description;

    Item(const float &price, const std::string &description) {
        this->price = price;
        this->description = Utils::to_lower(description);
    };
};

#endif  // ITEM_H_
