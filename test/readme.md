To compile the tests use:
g++ -I /home/andrew/googletest/include -L /home/andrew/googletest/mybuild/ -pthread LinkedListTest.cpp -lgtest ../src/data_structures/linked_list.cpp -o ../bin/LinkedListTest.out
