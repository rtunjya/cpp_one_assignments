#ifndef REGISTER_H_
#define REGISTER_H_

#include<map>
#include <vector>

#include "item.h"

enum CurrencyType {
    BENJAMIN,
    TWENTY_DOLLAR,
    TEN_DOLLAR,
    FIVE_DOLLAR,
    DOLLAR,
    QUARTER,
    DIME,
    NICKEL,
    PENNY
};

class Currency {
   public:
    constexpr static float get_currency_value(CurrencyType type) {
        switch (type) {
            case BENJAMIN:
                return 100.00;
            case TWENTY_DOLLAR:
                return 20.00;
            case TEN_DOLLAR:
                return 10.00;
            case FIVE_DOLLAR:
                return 5.00;
            case DOLLAR:
                return 1.00;
            case QUARTER:
                return .25;
            case DIME:
                return .10;
            case NICKEL:
                return .05;
            case PENNY:
                return .01;
        }
    }
};

class Register {
   public:
   std::map<CurrencyType, int> checkout(const std::vector<Item> &items)
   {
       return {};
   }
};

#endif  // REGISTER_H_
