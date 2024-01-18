#include <iostream>
#include <vector>
#include "../include/list.hpp"
#include "../include/test.hpp"

int main()
{
    std::cout << GREEN << "Miniprojekt PK 3" << std::endl
              << BRIGHT_GREEN << "Temat: Lista Jednokierunkowa" << RESET << std::endl
              << std::endl
              << BRIGHT_BLUE << "Part I - Test kompatybilności typów" << RESET << std::endl;

    std::vector<int> int_vector = {35, 12, 65, 98, 11, 90};
    test_list<int>(int_vector);

    std::vector<double> double_vector = {3.14159, 2.71, 1.41, 1.111, 69.420};
    test_list<double>(double_vector);

    std::vector<bool> bool_vector = {true, true, true, false, false, true, false};
    test_list<bool>(bool_vector);

    std::vector<std::string> string_vector = {"Lorem", "Ipsum", "Dolor", "Sit", "Amet"};
    test_list<std::string>(string_vector);

    std::cout << std::endl
              << BRIGHT_BLUE << "Part II - Test niestandardowych typów" << RESET << std::endl;
    
    log_step("1. Song class init", true);
    
    Song initald("Don't stop the music", "Lou Grant");
    std::stringstream initiald_info;
    initiald_info << initald.getId() << ". " << initald.getArtist() << " - " << initald.getName();
    log_step(initiald_info.str());

    Song jpop("スタイルのあった恋", "勇直子");
    std::stringstream jpop_info;
    jpop_info << jpop.getId() << ". " << jpop.getArtist() << " - " << jpop.getName();
    log_step(jpop_info.str());

    List<Song> song_list;
    song_list.push_front(jpop);
    song_list.push_front(initald);

    std::cout << LIGHT_GRAY << song_list.front().getName() << std::endl;

    std::cout << std::endl
              << BRIGHT_BLUE << "Part III - Test szybkości wzlgędem std::list" << RESET << std::endl;

    std::cout << std::endl
              << GREEN << "Wszystkie testy zostały zakończone pomyślnie!" << RESET << std::endl;
    return 0;
}