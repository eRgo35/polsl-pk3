#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <chrono>

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

    std::cout << "Location of jpop: [" << song_list.find(jpop) << "]" << std::endl;

    std::cout << LIGHT_GRAY << song_list.at(1).getName() << RESET << std::endl;

    log_step("2. Custom array of arrays", true);

    std::cout << std::endl
              << BRIGHT_BLUE << "Part III - Test szybkości wzlgędem std::list" << RESET << std::endl;

    log_step("1. Memory limits (on 1'000'000 random elements)", true);

    std::random_device rand_dev;
    std::mt19937 generator(rand_dev());
    std::uniform_int_distribution<int> distr(-2'147'483'648, 2'147'483'647);

    // push_back
    {
        std::list<int> standard_list;
        List<int> list;

        auto standard_start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1'000'000; i++)
        {
            standard_list.push_back(distr(generator));
        }
        auto standard_end = std::chrono::high_resolution_clock::now();
        auto standard_duration = std::chrono::duration_cast<std::chrono::milliseconds>(standard_end - standard_start);

        std::cout << "std::list push_back() fill time: " << standard_duration.count() << " ms" << std::endl;

        auto list_start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1'000'000; i++)
        {
            list.push_back(distr(generator));
        }
        auto list_end = std::chrono::high_resolution_clock::now();
        auto list_duration = std::chrono::duration_cast<std::chrono::milliseconds>(list_end - list_start);

        std::cout << "List push_back() fill time: " << list_duration.count() << " ms" << std::endl;
    }
    // push_front
    {
        std::list<int> standard_list;
        List<int> list;

        auto standard_start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1'000'000; i++)
        {
            standard_list.push_front(distr(generator));
        }
        auto standard_end = std::chrono::high_resolution_clock::now();
        auto standard_duration = std::chrono::duration_cast<std::chrono::milliseconds>(standard_end - standard_start);

        std::cout << "std::list push_front() fill time: " << standard_duration.count() << " ms" << std::endl;

        auto list_start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < 1'000'000; i++)
        {
            list.push_front(distr(generator));
        }
        auto list_end = std::chrono::high_resolution_clock::now();
        auto list_duration = std::chrono::duration_cast<std::chrono::milliseconds>(list_end - list_start);

        std::cout << "List push_front() fill time: " << list_duration.count() << " ms" << std::endl;
    }


    log_step("2. Access limits", true);

    log_step("3. find() limits", true);

    std::cout << std::endl
              << GREEN << "Wszystkie testy zostały zakończone pomyślnie!" << RESET << std::endl;
    return 0;
}