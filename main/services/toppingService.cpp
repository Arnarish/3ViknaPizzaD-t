#include "toppingService.h"

void ToppingService::add_topping(const Topping& topping) {
    toppingwriter.append_to_file(topping);
    t = topping;
}

