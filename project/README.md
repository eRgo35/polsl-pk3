# One-way Linked List
## Description
This is a basic program that tests one-way linked list library created by Michał Czyż

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

