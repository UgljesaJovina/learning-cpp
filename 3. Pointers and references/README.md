# Pointers and references

## Pointers

(note: I am currently unable to make a valid visual representation of pointers so I highly encourage you to find an image online, I will make one when I have the time;)

`Pointers` are variables used for storing addresses - memory locations of other variables or heap allocated values; They themselves are variables, which means they also take some space in memory, how much depends on the system; On a `32-bit` system `pointers` take `32-bits` and on `64-bit` systems they take `64-bits`; Rather self explanitory;

This means that it is **possible**, and often **required** to have `pointers` that point to other `pointers`;

As with all other data types, `pointers` are just numbers whose value is interpreted in a special way, or for a special operation; Think of it like having a **memory location**, then an indentifier for that **memory location** in the form of a `variable name`, and finally a `value` stored on that **memory location**; 

Working with `pointers` requires the use of **unary** (used on only one varaible, compared to something like a `+`) operators `*` and `&`; Both of these operators can be used while declaring variables and have a different meaning when used like that, which often confuses people;

Declaring a pointer variable means writing a **data type** of what it points to, followed by `*` and a **variable name** for the `pointer`; 

```cpp
int *ip; // a pointer to an int variable

char *cp; // HANKK, HANKKKK, DON'T ABBREVIATE CYBERPUNK HANKKK

double *fortniteBattlepass; // pointers don't need to follow any kind of naming convention

void *somethingPointer; // one of the few use cases for the void keyword, this defines a pointer which will need to be !cast! to a valid type before being able to be used

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


|   memory address   | code identifier | value stored at the location |
| :----------------: | :-------------: | :--------------------------: |
| **0x7ffda9d54b94** |      **x**      |            **15**            |
| **0x7ffda9d54b98** |     **px**      |      **0x7ffda9d54b94**      |
| **0x7ffda9d54ba0** |     **ppx**     |      **0x7ffda9d54b98**      |

(those with a keen eye may have noticed how the **address** for px is exactly 4 bytes away from the **address** of x, because an int takes 4 byes, and how ppx is 8 bytes away from px because a pointer takes 8 bytes)

Simpler version of the table:

| memory address | code identifier | value stored at the location |
| :------------: | :-------------: | :--------------------------: |
|     **A0**     |      **x**      |            **15**            |
|     **A1**     |     **px**      |            **A0**            |
|     **A2**     |     **ppx**     |            **A1**            |

So far this seems very point<sub>(er)</sub>less, because we still haven't covered functions and the `*` operator; 

The **dereference operator**, or the **value of** operator, or the `*` operator takes an **address**, goes into memory, and comes back with the value stored at that **address**;

In the previous example, if we were to **dereference** `px`, we would get the value of `x` - **15**; But what would happen if we were to **dereference** `ppx`? We'd get the **address** to `x`, which we can **derefernce** again in order to get the same value of **15**;

Code Example:
```cpp
int x = 15;
int *px = &x;
int **ppx = &px;

cout << x << endl; // 15
cout << px << endl; // &x

cout << *px << endl; // 15
cout << *ppx << endl; // &x
cout << **ppx << endl; // 15
```

All of this will come in a lot handier when we talk about functions and classes; 

Example of pointer usage:

```cpp
int a = 15;

int *pa = &a;

*pa = 64; // sets the value of a

int b = *pa; // gets the value of a through pa

a = 33;

cout << b << " " << a << " " << *pa << endl;
```

Output: `64 33 33`

### Void Pointers

A void pointer can `reference` any object in memory, but before getting `dereferenced`, it neets to get `cast` into the correct type; Example:

```cpp
int x = 353;
void *vp = &x;

cout << *vp << endl; // compile error

cout << *(int*)vp << endl; // the pointer is cast into an int pointer, and then dereferenced to get the value

cout << *(char*)vp << endl; // this is also possible 
```

We use `void pointers` when we want to have multiple different value types referenced by the same pointer, but we have to keep track of what type we need to cast it to afterwards;

In the previous example, the output is `353` followed by the letter `a`. **Why?** If we look at the binary representation of the number `353` we can see that it is `0001 0110 0001`, meaning its bigger than `1 byte` and 1 byte is the `size of char`; This means that when we `cast` `vp` to a char pointer, it only took the lower 8 bits of the number, and evaluated them to `97`, which in the ascii table is the value for the letter `a`;

### Null pointer

The `null` pointer is a pointer that points to nothing; We use it denote a pointer whos value is currently unavailable or can't be read; Trying to read a value from a null pointer causes the infamous `null pointer exception` designed to protect our code from undefined behaviour; In C++ we set a pointer to null like so: `int *px = nullptr;`; A `null` pointer is basically just `0` (it technically has its own type, `std::nullptr_t`) but made to pop out when we read the code; This means that we can check if a pointer is **non-null** by doing `if (px)`;

## References

We've seen `pointers` and the alternate ways we can access the value of a variable, `references` help with the same thing but are much simpler to use (and a lot more restricted);

Where as `pointers` are a variable designed for holding a special kind of value - an address, references aren't a variable, they are an `alias`, a different way to name your variable;

```cpp
int a = 67;
int &ra = a;
int &rra = ra;

cout << a << "\t" << ra << "\t" << rra << endl;
cout << &a << "\t" << &ra << "\t" << &rra << endl;
```

Output:

```
67      67      67
0x7fffc87039d4  0x7fffc87039d4  0x7fffc87039d4
```

Here we can see that `ra` and `rra` have the same value and the same address as `a`; This means that unlike how we could have a `pointer to a pointer`, we can't have a `reference of a reference`, since they require a base memory location to begin with;

Couple of major differences include how we need to provide a value for the reference at the time of its creation, while a pointer can remain declared and not initialized; Pointers can also be re-assigned a value, while references can't; Example

```cpp
int a1 = 10, a2 = 15;
int *pa; // uninitialized

pa = &a1; // gets the address of a1
pa = &a2; // gets the address of a2

int b1 = 10, b2 = 15;
int &rb; // compile error

int &rb = b1; // references b1
rb = b2; // puts the value of b2 into b1 (b1 becomes 15)
```

If we come back to the table we made for the pointers, we can see how references behave:


|   memory address   | code identifier | value stored at the location |
| :----------------: | :-------------: | :--------------------------: |
| **0x7ffda9d54b94** | **x, rx, rrx**  |            **67**            |

We just made new identifiers for the same object in memory, compared to making new objects in memory;

References behave a little differently in functions, we'll see that;

## Arrays

Same as C, an array is a continuous block of data made to hold multiple values inside a single variable; An array under the hood is just a pointer pointing to the address of the first element in the array; That address can then be offset by `n` bytes to get all the other values; 

Syntax: `T var_name[n] = { initial_values }` - `T` is the data type of the elements in the array, `n` is the max amount of elements that can be stored inside this array and `initial_values` is a list of comma seperated values that will be used as the initial values for the array; If we set `initial_values`, `n` doesn't need to be set, but if we don't `n` is required;

Example:

```cpp
int arr[5] = { 1, 2, 3 };
int val = 15;
```

This will initialize the array with **5** slots, where the first **3** are `1, 2, 3` and the last **2** are `0`;

| memory address | code identifier | value stored at the location |
| :------------: | :-------------: | :--------------------------: |
|   **A0 + 0**   |   **arr[0]**    |            **1**             |
|   **A0 + 4**   |   **arr[1]**    |            **2**             |
|   **A0 + 8**   |   **arr[2]**    |            **3**             |
|  **A0 + 12**   |   **arr[3]**    |            **0**             |
|  **A0 + 16**   |   **arr[4]**    |            **0**             |
|     **A1**     |     **val**     |            **15**            |

Using **zero-based** indexing, we can access every element in the array from the first (at index **0**) to the last (index **(n - 1)**); Getting the size of the array can be done using `sizeof(arr) / sizeof(T)`; `sizeof(arr)` will get the total amount of bytes the array takes, in our case that would be <br>`5 (number of elements) * 4 (size of each element) = 20 (sizeof array)`, meaning that if we divide that by `sizeof(int)` we get **5**;

This is not the only way to make an array, we can also do it with the `new` keyword which will be mentioned in more detail when we come to `classes`; All the `new` keyword does is make the array get **allocated** on the **heap** instead of the **stack** (stack allocation is done like we showed previously); If an array is **stack allocated** it gets `deleted` from the memory **automatically**, while if its **heap allocated** we have to handle deallocation **manually** using the `delete[]` keyword; Example:

```cpp
int *arr = new int[5];

arr[0] = 5;
arr[1] = 17;

for (int i = 0; i < 5; i++) {
    cout << "The element at index i is: " << arr[i] << endl;
}

delete[] arr; // free up memory

```

If we were to change what arr points to, we would lose the reference for the values we **allocated** in **heap**, meaning we can't `delete` them afterwards; This can be devastating and lead to a common bug called a `memory leak` - when **heap allocated** space is not **deallocated** properly; For this reason, whenever we use `new` we should also have a `delete` for single values, or `delete[]` for arrays, but more on that in `classes` (it's also a good practice to set a deleted pointer to `null`);

One last note, since arrays are just fancy pointers under the hood, this means we can also access each of their elements like this:

```cpp
int *arr = new int[5] { 1, 2, 3, 4, 5 };

*(arr + 2) = 17; // changes the value of arr[2] to 17
// array now looks like: 1, 2, 17, 4, 5

cout << *(arr + 4) << endl; // writes 5

delete[] arr;
```

This works because `arr[i]` is just a different way to write the *"pointerized"* expression; `*(arr + 4)` works because it knows the pointer is of type `int`, meaning it is going to add `4 * sizeof(int)` to the base pointer `arr`; Had we dont something like: `*(int*)((char*)arr + 4)`, it would read out `2` - the second index in the array; Why? `(char*)arr` will cast arr to a `char pointer`, meaning that adding 4 will add `4 * sizeof(char) = 4` to the address, skiping only one integer; If we were to write this out, we wouldn't see anything since the ascii character with the value `2` doesn't have a visual representation; If instead of `2` we had `48`, output would be `0`; For this reason, before **dereferencing** the pointer, we have to cast it back to `(int*)` so it gets treated like a number, which will then write out `2`; If we were to do `*(int*)((char*)arr + 3)`, we would get `512`, because the value of `2` gets `shifted` by 8 places to the left, meaning it gets multiplied by `2^8 = 256`; Example showing everything I've yapped about here:

```cpp
int *arr = new int[5] { 1, 48, 3, 4, 5 };

cout << *(arr + 4) << endl; // 5
cout << ((char*)arr + 4) << endl; // 0
cout << *(int*)((char*)arr + 4) << endl; // 48
cout << *(int*)((char*)arr + 7) << endl; // 768

delete[] arr;
```