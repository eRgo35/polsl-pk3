#include <iostream>
#include <sstream>
#include "../include/list.hpp"

int main()
{
    std::cout << "Miniprojekt PK 3" << std::endl;
    std::cout << "Temat: Lista Jednokierunkowa" << std::endl;

    List<int> exmaple_list;
    exmaple_list.push_front(35);
    exmaple_list.push_front(24);
    exmaple_list.push_front(24);
    exmaple_list.push_front(24);
    exmaple_list.push_front(26);

    std::cout << exmaple_list << std::endl;

    exmaple_list.pop_front();

    std::cout << exmaple_list << std::endl;

    std::cout << exmaple_list.at(3) << std::endl;

    exmaple_list.print_all();

    List<int> exmaple_list2;
    exmaple_list2.push_front(1);
    exmaple_list2.push_front(35);
    exmaple_list2.push_front(24);
    exmaple_list2.push_front(25);
    exmaple_list2.push_front(24);
    exmaple_list2.push_front(26);

    std::cout << "Find pos of 35:   " << exmaple_list2.find(35) << std::endl;

    std::cout << "Find pos of 24:   " << exmaple_list2.find(24) << std::endl;

    std::cout << "Find pos of 99:   " << exmaple_list2.find(99) << std::endl;

    std::cout << exmaple_list2 << std::endl;

    exmaple_list2.erase(2);

    std::cout << exmaple_list2 << std::endl;
    
    List<int> cin_list;
    std::stringstream test("10");
    
    test >> cin_list;
    cin_list.push_front(1);
    cin_list.push_front(35);
    cin_list.push_front(24);
    cin_list.push_front(25);

    std::cout << cin_list << std::endl;

    List<int> moved_list = std::move(cin_list);

    std::cout << cin_list << std::endl;
    std::cout << moved_list << std::endl;


    List<int> copied_list = moved_list;
    moved_list.pop_front();

    std::cout << copied_list << std::endl;
    std::cout << moved_list << std::endl;

    moved_list.insert(999, 2);

    std::cout << moved_list << std::endl;

    moved_list.push_back(999);
    moved_list.push_back(998);

    std::cout << moved_list << std::endl;

    int popped = moved_list.pop_back();
    std::cout << moved_list << std::endl;

    std::cout << popped << std::endl;
    std::cout << moved_list.pop_front() << std::endl;

    std::cout << moved_list.front() << std::endl;

    return 0;
}