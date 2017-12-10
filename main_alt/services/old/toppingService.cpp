#include "toppingService.h"
//sendir topping beint æi write eins og er
void ToppingService::add_topping(const Topping& topping) {
    tw.append_to_file(topping);
}

//vantar að gera input villucheck
