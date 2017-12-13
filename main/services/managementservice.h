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
#include "../services/locationservice.h"

#include "../exceptions/FileReadException.h"
#include "../exceptions/FileEmptyException.h"
#include "../exceptions/FileWriteException.h"
#include "../exceptions/FileExistsException.h"
#include "../exceptions/InvalidSizeException.h"
#include "../exceptions/InvalidNameException.h"
#include "../exceptions/InvalidPriceException.h"
#include "../exceptions/InvalidCategoryException.h"
#include "../exceptions/InvalidLocationException.h"
#include "../exceptions/InvalidPostcodeException.h"


#include <iostream>
using namespace std;

class ManagementService {
    public:
        void create_new_topping(string name, int price);
        void create_new_base(string name, int size, int price);
        void create_new_menu_item(string name, int b, vector<int> t);
        void create_new_product(string name, int price, int category);
        void add_new_store_location(string new_location, int postcode);

        vector<Base> get_all_bases();
        vector<Topping> get_all_toppings();

    private:
        BaseIO baseio;
        ToppingIO toppingio;
        MenuIO menuio;
        ProductIO productio;
        LocationService location_service;
};

#endif
