# SPW-2019 E-COMMERCE PROJECT
This project uses "priority queues" to display the results of search for products.

The data for the objects(products) are written in the binary file mem.dat,this can be edited using the file initial.cpp . The 
program file is used to add/modify data to the binary file


"Class Item":
It is the data type used for representing a product. It has functions for initialising,displaying, and returning each of the values
stored in the object. Each object has the following data values:
->Type of the item(char array)
->Name of the item(char array)
->Brand name of the item(char array)
->price of object(long integer)
->Rating(float)
->Number of people who have rated the item(enables us to calculate the rating)

Main.cpp:
It is the primary program file of the project. The file contains the the definition of the above mentioned class and also the 
functions to search for type of item(or alternatively choose all available types of items) and print it in the following orders:
->increasing order of price
->Decreasing order of rating(each item is rated out of 5)
->Decreasing order of popularity(defined as price/rating)

It is able to do this by reading all the items off the binary file mem.dat and storing them as a vector. Then each time the item type
is mentioned the items of the given type are stored in a priority queue which is achieved through the STL implementation of priority
queue.

Then 2 of the required items are displayed and the user is prompted to answer whether he wants more items. The items are retrieved
in sorted order by popping the element in the priority queue.

Since the STL uses heap sort to form the priority queue we can achieve a complexity of O(k*logn).
