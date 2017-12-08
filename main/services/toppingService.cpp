#include "toppingService.h"

void ToppingService::add_topping(const Topping& topping) {
    tw.append_to_file(topping);
}

