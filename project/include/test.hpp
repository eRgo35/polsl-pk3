#ifndef TEST_HPP_INCLUDED
#define TEST_HPP_INCLUDED

#include <iostream>
#include <sstream>
#include <vector>

#include "list.hpp"
#include "colors.hpp"

void log_step(std::string message, bool major = false)
{
  if (major)
  {
     std::cout << BRIGHT_YELLOW << message << RESET << std::endl;
     return;
  }
  std::cout << BRIGHT_CYAN << message << RESET << std::endl;
}

template <typename T>
void test_list(std::vector<T> &test_vector)
{
    std::string type;

#ifndef _MSC_VER
    type = __PRETTY_FUNCTION__;
#else
    type = __FUNCSIG__;
#endif

    std::stringstream type_test("Testing for type: ");
    type_test << type;
    log_step(type_test.str(), true);

    log_step("1. Data pushing & printing");
    List<T> data_io;

    for (auto item : test_vector)
    {
        data_io.push_front(item);
    }

    std::cout << LIGHT_GRAY << data_io << std::endl;

    log_step("2. Data popping");
    data_io.pop_front();

    std::cout << LIGHT_GRAY << data_io << std::endl;

    log_step("3. Accessing by front() and at() index");

    std::cout << LIGHT_GRAY << data_io.front() << std::endl;
    std::cout << LIGHT_GRAY << data_io.at(3) << std::endl;

    log_step("4. Print all contents by method");
    data_io.print_all();

    log_step("5. Find an element location");
    std::cout << LIGHT_GRAY << "Position of " << test_vector[1] << ": " << data_io.find(test_vector[1]) << std::endl;

    log_step("6. Erase en element from the list");
    data_io.erase(2);
    std::cout << LIGHT_GRAY << data_io << std::endl;

    log_step("7. Serial stream input");
    std::stringstream stream;
    stream << test_vector[1];
    stream >> data_io;
    std::cout << LIGHT_GRAY << data_io << std::endl;

    log_step("8. List copying and moving");
    List<T> copied_list = data_io;
    List<T> moved_list = std::move(data_io);

    copied_list.pop_front();

    std::cout << LIGHT_GRAY << "Copied List:  " << copied_list << std::endl;
    std::cout << LIGHT_GRAY << "Moved List:  " << moved_list << std::endl;

    log_step("9. More data manipulation");

    moved_list.insert(test_vector[0], 2);
    std::cout << LIGHT_GRAY << moved_list << std::endl;

    moved_list.push_back(test_vector[0]);
    moved_list.push_back(test_vector[0]);
    moved_list.push_back(test_vector[0]);
    std::cout << LIGHT_GRAY << moved_list << std::endl;

    std::cout << LIGHT_GRAY << moved_list.pop_back() << std::endl;
    std::cout << LIGHT_GRAY << moved_list.pop_front() << std::endl;
    moved_list.erase(2);

    std::cout << LIGHT_GRAY << moved_list << std::endl;
}

class Song
{
private:
    int id;
    std::string artist;
    std::string album;
    std::string name;
    std::string lyrics;
    int popularity;
    int year;

public:
    Song() : id(generateId()){};

    Song(std::string name, std::string artist) : name(name), artist(artist)
    {
        id = generateId();
    }

    int generateId()
    {
        static int nextId = 1;
        return nextId++;
    }

    bool operator==(Song &other)
    {
        if (id == other.getId())
            return true;
        return false;
    }

    int getId() const
    {
        return id;
    }
    void setId(int newId)
    {
        id = newId;
    }

    std::string getArtist() const
    {
        return artist;
    }
    void setArtist(std::string newArtist)
    {
        artist = newArtist;
    }

    std::string getAlbum() const
    {
        return album;
    }
    void setAlbum(std::string newAlbum)
    {
        album = newAlbum;
    }

    std::string getName() const
    {
        return name;
    }
    void setName(std::string newName)
    {
        name = newName;
    }

    std::string getLyrics() const
    {
        return lyrics;
    }
    void setLyrics(std::string newLyrics)
    {
        lyrics = newLyrics;
    }

    int getPopularity() const
    {
        return popularity;
    }
    void setPopularity(int newPopularity)
    {
        popularity = newPopularity;
    }

    int getYear() const
    {
        return year;
    }
    void setYear(int newYear)
    {
        year = newYear;
    }
};

#endif
