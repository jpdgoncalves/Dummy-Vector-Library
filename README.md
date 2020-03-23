# Dummy Vector Library

## Introduction
This is a very small c library developed mainly to take out the rust in my C Programming skills.

The file containing the instructions of what the library needs to have will be available in the future in case someone wishes to do the project themselves.

## How to build the project
Just navigate into the repository directory and then use the command:

```bash
make all
```

If you only want to build the library you can do:

```bash
make build
```

Please note that this library depends on the math library which means if you wish to use this you will need to include it in your compilation process. Example:

```bash
gcc -Wall -std=c99 -o test/demo.out test/demo.c build//mvector.h build/libmvector.a -lm
```

## How to use it

Just include the header file into your source files like so

```c
#include "mvector.h"
```