#include "toppingService.h"
//sendir topping beint �i write eins og er
void ToppingService::add_topping(const Topping& topping) {
    tw.append_to_file(topping);
}

//vantar a� gera input villucheck
