The files for Homework2, Exercise3

File instructions:

- products.hpp: the **updated** header file and implementation of different product types, including **Future** class.
- productservice.hpp: the **updated** header file and implementation of product services, including **FutureProductService** class. Also, it contains the updated methods for **BondProductService** and **IRSwapProductService** as required in exercise 3.
- test_products.cpp: the testing file for the newly implemented Future and FutureProductService class.

Run the code:

- Run the **test_products.cpp** using g++ to see the test outputs. Don't forget to link to the **Boost** library!
- To run the code: g++ -std=c++11 test_products.cpp -o test -I C:/boost/include/boost-1_80 -L C:/boost/lib -lws2_32 -lwsock32
- Note: the path after -I and -L should be the **include and lib paths** for the locally installed Boost library. 
