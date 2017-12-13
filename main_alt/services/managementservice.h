#ifndef MANAGEMENTSERVICE_H
#define MANAGEMENTSERVICE_H

#include "../models/base.h"
#include "../models/topping.h"
#include "../models/pizza.h"
#include "../models/product.h"
#include "../models/location.h"
#include "../repositories/baseio.h"
#include "../repositories/toppingio.h"
#include "../repositories/menuio.h"
#include "../repositories/locationio.h"
#include "../repositories/productio.h"
#include "../services/Locationservice.h"


#include "../exceptions/InvalidNameException.h"
#include "../exceptions/InvalidPriceException.h"
#include "../exceptions/InvalidSizeException.h"
#include "../exceptions/InvalidCategoryException.h"
#include "../exceptions/FileExistsException.h"
#include "../exceptions/FileWriteException.h"
#include "../exceptions/FileReadException.h"


#include <iostream>
using namespace std;

/* TODO: add all this shit

 1.  New pizza base
 2.  New topping
 3.  New menu item
 4.  New product
 5.  New pick-up location
 6.  Exit
*/

class ManagementService {
    public:
        void create_new_topping(string name, int price);
        void create_new_base(string name, int size, int price);
        void create_new_menu_item();
        void create_new_product();
        void add_new_store_location();

    private:
        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
        ProductIO prodio;
        LocationService LocServ;
};

#endif
