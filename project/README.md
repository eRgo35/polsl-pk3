# Singly Linked List
## Description
This is a basic program that tests singly linked list library created by Michał Czyż

## Libraries
This project utilizes `cmake`.

## Usage
To build the program follow steps below:

1. Install required dependencies
```
$ paru -S base-devel cmake git
```

2. Clone the repository
```
$ git clone git@github.com:eRgo35/polsl-pk3.git
```

3. Navigate to the `build` directory inside the clonned repository
```
$ cd polsl-pk3/project/build
```

4. Build the program
```
$ cmake ..
```

5. Start the program
```
$ ./project
```

6. (Optional) Check memory leaks
```
$ valgrind --leak-check=full -v --track-origins=yes ./project
```

## Stats

Date : 2024-01-25 15:44:12

Directory polsl-pk3/project

Total : 6 files,  583 codes, 55 comments, 166 blanks, all 804 lines

| language | files | code | comment | blank | total |
| :--- | ---: | ---: | ---: | ---: | ---: |
| C++ | 5 | 551 | 55 | 155 | 761 |
| Markdown | 1 | 32 | 0 | 11 | 43 |
