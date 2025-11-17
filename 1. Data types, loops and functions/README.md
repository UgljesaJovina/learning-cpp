# Data types

Starting with the basics, so far the **data types** we use will be mostly the same as in C; **Data types** are split into 3 groups, `Basic data types`, `Derived data types` and `User defined data types`;

## Basic data types

These are the same as in C, we have:

- `short` - a modifier for the `int` **data type** to force `16-bit` size, can be used by itself and means `short int`
- `int` - for `16 or 32-bit` integer numbers
- `long` - a modifier for the `int` **data type** to force `32-bit` size*, can be used by itself and means `long int`, can be used on itself (`long long` to make it `64-bit`)
- `float` - for `32-bit` floating point numbers
- `double` - for `64-bit` floating point numbers (double precision)
- `char` - for characters, `8-bit`
- `wchar_t` - for wide characters, `16-bit` / `32-bit`
- `unsigned` - a modifier used on previous **data types** in order to make them **positive-only**, used by itself is the same as `unsigned int`
- `bool` - for `true`/`false` values, this is the first difference compared to C, since in C bool didn't exist as an explicit **data type**
- `void` - for when the value is uncertain (could be anything, could be nothing, used mainly for `pointers` and function as a return type)

\* `long int` and `int` depend on system structure, for example, on windows long int will be `32-bit` for compatability reasons, while on linux it will be `64-bit`; Mostly unimportant information :) (if you want to check the size of some variable, there is a builtin operator `typeof(*type*)` that can help you)

## Derived data types

We have:

- `arrays` - continuous blocks of data
- `pointers` - special variables that store the address of a certain data type
- `references` - similar to `pointers` but also very different, explained here<sup>[[1](#pointers-and-references)]</sup>
- `functions` - for reusable code blocks
- `strings` - part of the standard library (`std::string`) very often used when working with `strings`, compared to the C-style `char[]`

## User defined data types

We have:

- `classes` - more about them in one of the other folders
- `structure` - same as C, used to define a custom data type with containing fields with their own names and data types, more about them in classes
- `union` - same as C, defines a data type with members where instead of having the memory get taken sequentially, only the largest data type takes space, more about them in classes
- `typedef` - same as C, provides an alias for a different data type
- `using` - for user defined `namespace's`, don't think its classifyable as its own data type, but yeah

## Usage

We use data types to declare variables - named adresses in our program that we can use to fetch data out of memory;

``` cpp
int main() {
    int age = 20;
    float height = 193.2;

    cout << age << endl;
    cout << height << endl; // IO explained in the next folder
}
```

This script will write out `20` on one line and `193.2` on the next;

## Pointers and references

(note: I am currently unable to make a valid visual representation of pointers so I highly encourage you to find an image online, I will make one when I have the time;)

`Pointers` are variables used for storing addresses - memory locations of other variables or stack allocated values; They themselves are variables, which means they also take some space in memory, how much depends on the system; On a `32-bit` system `pointers` are `32-bits` and on `64-bit` systems they are `64-bits`; Rather self explanitory;

This means that it is **possible**, and often **required** to have `pointers` that point to other `pointers`;

As with all other data types, `pointers` are just numbers whose value is interpreted in a special way, or for a special operation; Think of it like having a **memory location**, then an indentifier for that **memory location** in the form of a `variable name`, and finally a `value` stored on that **memory location**; 

Working with `pointers` requires the use of **unary** (used on only one varaible, compared to something like a `+`) operators `*` and `&`; Both of these operators can be used while declaring variables and have a different meaning when used like that which often confuses people;

Declaring a pointer variable means writing a **data type** of what it points to, followed by `*` and a **variable name** for the `pointer`; 

```cpp
int *ip; // a pointer to an int variable

char *cp; // HANKK, HANKKKK, DON'T ABBREVIATE CYBERPUNK

double *fortniteBattlepass; // pointers don't need to follow any kind of naming convention

void* somethingPointer; // one of the few use cases for the void keyword, this defines a pointer which will need to be !cast! to a valid type before being able to be used

T *tp; // here we declare a pointer called tp for type of T
```

Even though all of these `pointers` point to **data types** of different sizes, the pointer variables are all the same size, since the value they need to store is an address the size of `32 to 64` bits; Again, a pointer is just a variable used for storing a value of a memory address (a block of bytes) that can represent anything; We see that with casting pointers which we'll get to shortly;

Assignig values to pointer variables requires us to have an address to store inside them; In order to get the **address** of a variable we need to use the `&` - the **address of** operator; It is a unary operator that turns type `T` into type `T*`;

```cpp
int x = 15;

int *px = &x;

int **ppx = &px;
```

The value stored inside *px* now is **the address of** *x*, and the value stored in *ppx* is **the address of** *px*; Hopefully the table below will help you understand better, there is also a script file ***pointers-and-references.cpp*** you can compile and run in order to clear things up;


|memory address    |code identifier|value stored at the location|
|:---:             |:---:          |:---:                       |
|**0x7ffda9d54b94**|**x**          |**15**                      |
|**0x7ffda9d54b98**|**px**         |**0x7ffda9d54b94**          |
|**0x7ffda9d54ba0**|**ppx**        |**0x7ffda9d54b98**          |

(those with a keen eye may have noticed how the address for px is exactly 4 bytes away from the address of x, because an int takes 4 byes, and how ppx is 8 bytes away from px because a pointer takes 8 bytes)

Simpler version of the table:

|memory address    |code identifier|value stored at the location|
|:---:             |:---:          |:---:                       |
|**A0**            |**x**          |**15**                      |
|**A1**            |**px**         |**A0**                      |
|**A2**            |**ppx**        |**A1**                      |

So far this seems very pointless, because we still haven't covered functions and the `*` operator; The **dereference operator**, or the **value of** operator, or the `*` operator takes an address, goes into memory, and comes back with the value stored at that address;

