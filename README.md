# Process Synchronization In C++
This repository contains a sample code of process synchronization in C++, executable in ubuntu based systems.

## Getting Started
The program takes an integer between 10 and 100 as input from the user. Then creates two processes, first process prints the first half of the integers one by one, then the other process prints the remaining. Each process when printing the number also prints its process ID. Process start and end messages should also be printed. Following is an example run:

```
Enter a number between 10-100: 11
>>>starting process 1 the process ID is:6755
process 1: 1 , the process ID is:6755
process 1: 2 , the process ID is:6755
process 1: 3 , the process ID is:6755
process 1: 4 , the process ID is:6755
process 1: 5 , the process ID is:6755
>>>ending process 1, the process ID is:6755
>>>starting process 2 the process ID is:6757
process 2: 6 , the process ID is:6757
process 2: 7 , the process ID is:6757
process 2: 8 , the process ID is:6757
process 2: 9 , the process ID is:6757
process 2: 10 , the process ID is:6757
process 2: 11 , the process ID is:6757
>>>ending process 2, the process ID is:6757
```

#### Before you Start
You must have `g++` compiler and `make` installed on your system before testing.


## Install g++ and make on Ubuntu
Start by updating the packages list:
```
sudo apt update
````

Install the `build-essential` package by typing:
```
sudo apt install build-essential
```

The command installs a bunch of new packages including `gcc`, `g++` and `make`.

You may also want to install the manual pages about using GNU/Linux for development:
```
sudo apt-get install manpages-dev
```

To validate that the G++ compiler is successfully installed, use the `g++ --version` command which prints the G++ version:
```
g++ --version
```

## How to Build and Run
Just run `make` from the root of this repository. A binary called `exec.out` will be produced. To run this file, enter the following:
```
./exec.out
```

## License
Copyright (c) 2021 shakayhere

Permission is hereby granted, free of charge, to any person obtaining a copy of this code, to deal in any Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software.
