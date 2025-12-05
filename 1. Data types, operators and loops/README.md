# Data types, operators and loops

## Data types

Starting with the basics, so far the **data types** we use will mostly be the same as in C; **Data types** are split into 3 groups, `Basic data types`, `Derived data types` and `User defined data types`;

### Basic data types

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
- `enum` - has it's own [section](#enums)

\* `long int` and `int` depend on system structure, for example, on windows `long int` will be `32-bit` for compatability reasons, while on linux it will be `64-bit`; Mostly unimportant information :) (if you want to check the size of some variable, there is a builtin operator `typeof(*type*)` that can help you)

### Derived data types

We have:

- `arrays` - continuous blocks of data, you can find more [here](https://github.com/UgljesaJovina/learning-cpp/tree/main/3.%20Pointers%20and%20references#arrays)
- `pointers` - special variables that store the address of a certain data type
- `references` - similar to `pointers` but also very different, explained [here](https://github.com/UgljesaJovina/learning-cpp/tree/main/3.%20Pointers%20and%20references#references)
- `functions` - for reusable code blocks
- `strings` - part of the standard library (`std::string`) very often used when working with `strings`, compared to the C-style `char[]`

### User defined data types

We have:

- `classes` - more about them in one of the other folders
- `structure` - same as C, used to define a custom data type with containing fields with their own names and data types, more about them in classes
- `union` - same as C, defines a data type with members where instead of having the memory get taken sequentially, only the largest data type takes space, more about them in classes
- `typedef` - same as C, provides an alias for a different data type
- `using` - for user defined `namespace's`, don't think its classifyable as its own data type, but yeah

### Usage

We use data types to declare variables - named adresses in our program that we can use to fetch data out of memory;

*Output explained [here](https://github.com/UgljesaJovina/learning-cpp/tree/main/2.%20Input%20and%20Output)

``` cpp
int main() {
    int age = 20;
    float height = 193.2;
    bool handsomeAndModest = true;

    cout << age << endl;
    cout << height << endl; 
    cout << handsomeAndModest << endl;
}
```

This script will write out `20` on the first line, `193.2` on the second and `1` on the third;

The one gets output because bool values `true` and `false` are nothing but `1` and `0` under the hood;

## Operators

Just like C, C++ doesn't differ much in terms of operators. We can split them into groups like so:

### Arithmetic operators

- `+` - adds two operands together and outputs their sum
- `-` - substracts the right operand from the left and outputs the result
- `*` - multiplies two operands and outputs the result (also has a unary version that is very different)
- `/` - divides the left operand by the right and outputs the result
- `%` - returns the remainder of integer division between the left and right operands

The above operators can be combined with the asignment operator (`=`) in order to shorten the expression (`a = a + b` ==> `a += b`)

- `++` - unary operator that increments the value by one
- `--` - unary operator that decrements the value by one

### Relational operators

Each relational operator outputs a bool value, a `true` or a `false`, which will be important later;

- `==` - outputs true if the left and right operands are equal
- `!=` - outputs true if the left and right operands are **not** equal
- `>` - checks if the left operand is greater than the right
- `>=` - checks if the left operand is greater than or equal to the right
- `<` - checks if the left operand is less than the right
- `<=` - checks if the left operand is less than or equal to the right

### Logical operators

- `&&` - logical ***and***, checks if the left and right operand are a **non-zero** value (or `true`, basically the same thing) and outputs `true` if they are
- `||` - logical ***or***, checks if either of the operands is a non zero value and outputs `true`
- `!` - unary operator that turns any **non-zero** value **zero**, and the **zero** value into **one**
  
### Bitwise operators

I'm not sure if this is in the scope of the class, but I think they're important;

- `&` - binary and, outputs a new number after performing an `and` over every single bit of the left and right operand; Example: `6 & 3 == 2`; 6 in binary is `110` and 3 is `011`, we can see only the middle bit of both numbers is flipped so it is the only one flipped in the result aswell; This is a core concept used in all the other **bitwise** operators;
- `|` - binary or, whenever there is a bit in either of the operands that is flipped, the same bit will be flipped in the result; Ex.: `10 | 3 == 11`, `7 | 5 == 7`
- `^` - binary xor, only the bits present **explicitly** in either of the operands, not both, not none, will be present; Ex.: `5 ^ 3 == 6`
- `<<` - left shift operator shifts the bits of the left operand by the amount given as the right, effectively multiplying it by a power of two; `x << y <=> x * 2^y`; Ex.: `5 << 1 == 10`, `5 << 4 == 80`
- `>>` - right shift operator works very similarly, but instead of multiplying we divide the number by a power of two; Ex.: `64 >> 4 == 4`, `25 >> 2 == 6`, the rightmost bits have been pushed out
- `~` - one's complement, or the `binary not`, is a unary operand that inverts every bit of the number; Ex.: `~5 == -6`, `~17 == -18`; This happens because when fliping every bit in the number, we also flip the first bit which decides the sign of the number (will it be positive - `0`, or negative - `1`); Had for example the `5` been an unsigned number, we would have gotten `4294967290`;

### Ternary operator

This group has only one operator, the `?`; It is made up of 3 parts, the `condition`, `val1` and `val2`; It has the form of: `condition ? val1 : val2`; The ternary operator will check the condition, if the value is **non-zero**, the output will be `val1`, otherwise it is `val2`;

Example:
```cpp
int x = 15;
int y = x < 20 ? x : 20; // y will be 15 in this case since we're working with static values, but this is a nice example of how we can limit a value to a certain range
```

### Miscelaneous operators

There are only two operators (I can mention right now at least) in this group, and they are the `sizeof` and the `casting` operators;

- `sizeof` - outputs the size in bytes of some **type** or **variable**, used like: `sizeof(type)` or `sizeof(var_name)`; It looks like a function call, but it is not since it gets processed during compile time and just swapped for a static value that represents the size calculated;
- `(type)var` - the casting operator is really useful especially after we get to the whole OOP part; It is a unary operator used like `(type)var_name`; It converts a variable into a different type **IF POSSIBLE**, otherwise throws an exception; The variable that was used stays the same, but the output will be of the desired type; Example:
```cpp
char c = 'U';
int cValue = (int)c; // 85
```

## Conditions and loops

### Conditions

- `if-else` - the most basic version of doing conditional work there is; We use the `if-else` blocks to run conditionally run parts of the program, provided the conditions are met; Syntax:

```cpp
if (condition1) {
    // execute if condition1 is non-zero
} else if (condition2) {
    // execute if condition2 is non-zero, and all the previous were 0
} else {
    // execute if all other conditions were zero
}
```

As we can see, the `if-else` block is made with the if keyword at the begining, a pair of **parenthesies** containing a boolean value, and a pair of **curly braces** containing the block of code that is to be executed if the boolean value evaluates to `true` (note that if the block contains only one line of code, the curly braces don't need to be written); 

The `if` block can exist by itself, executing if the condition is met; In order to have more complex conditions we can attach an infinite amount of `else-if` blocks (yandere-dev) and one `else` block; The statements get checked **sequentially** and when a `non-zero` value is found, that block gets executed and that `if-chain` statement is finished;

Example:

```cpp
int age = 70;

if (age >= 18) cout << "Of age" << endl;
else if (age >= 65 ) cout << "Senior" << endl;
else cout << "Infant?" << endl;

// Output: Of age
```

Here, since the less specific check was first, we can never reach the `else if (age >= 65)` since the `if (age >= 18)` will always take effect first; 

Correct way:

```cpp
float grade = 2.7;

if (grade >= 4.5) cout << "A" << endl;
else if (grade >= 3.5) cout << "B" << endl;
else if (grade >= 2.5) cout << "C" << endl;
else if (grade >= 1.5) cout << "D" << endl;
else cout << "F" << endl;
// outputs 'C'
```

- The other way to do conditional (kinda) logic is to use a `switch-case` tree; Syntax example:

```cpp
switch (variable) {
    case val1:
        // code block...
        break;
    case val2:
        // code block...
        break;
    ...
    case valn:
        // code block...
        break;
    default:
        // code block...
        break;
}
```

`Switch` is a lot more restrictive compared to `if` since each case can match only by `==`; A case can be entered if `vairable == valx` and has to end with a `break` in order to denote it's own code block; The `default` block is similar to the `else` block since it is executed only if all else fails;

### Loops

Loops are conditional statements that repeat their code block as long as their condition is fulfiled;

- `while` - `while (condition) { //code block }`; Ex.:

```cpp
int x = 1;

while (x <= 5) {
    cout << "The current value of x is: " << x << endl;
    x++;
}
```
The output is:
```
The current value of x is: 1
The current value of x is: 2
The current value of x is: 3
The current value of x is: 4
The current value of x is: 5
```

On each iteration of the loop, the value of `x` gets checked, if its less than or equal to **5** it prints out the string, increments `x` and then repeats the process;


- `do-while` - same as `while` but is guaranteed to run at least once;

Syntax:
```cpp
int x = 10;
do {
    cout << "The current value of x is: " << x << endl;
    x--;
} while (x >= 20);
```

This loop will run once and output;

```
The current value of x is: 10
```

If we were to use a normal while loop, there wouldn't even be an output since the condition could never be met;

- `for` - the for loop is most commonly used, but its syntax is basically just synthetic sugar for a while loop; Syntax:

```cpp
for (*before the loop*; condition; *after each iteration*) {
    // code block...
}
```

In a while loop, we had to define a counter variable before entering the `loop` (in our case `x`) and then had to change that variable in some way on each `iteration` of the `loop` to stop it from going `infinite`; The for loop is basically the same, except it is all contained within the parenthesis for the loop definition; Example:

```cpp
int n = 10;
for (int i = 0; i < n; i++) {
    cout << "The current value of i is: " << i << endl;
}
```

The output is:

```
The current value of i is: 0
The current value of i is: 1
...
The current value of i is: 9
```

This is the same as what we had with the `while loop`; We can see the simillarities even closer if i were to write the loop like this:

```cpp
int n = 10, i = 0;
for (; i < n; ) {
    cout << "The current value of i is: " << i << endl;
    i++;
}
```

Here we can notice the for loop can exist with only the condition part of the definition; The `int i = 0` could have been replaced with any statement that we want to run before the first iteration of the loop; The `i++` could have been replaced with anything we want to run after each iteration of the loop; For example:

```cpp
for (int n = 10, i = 0; i < n; cout << i << endl, i++) { }
```

This will write numbers `from 0 to 9` without us having put anything in the body of the `for loop`;

#### Break and continue

`Break` and `continue` are keywords used for manipulating the order in which loops get executed; If we hit a `break`, the loop immediately stops, stopping the current iteration and not starting a new one; For example:

```cpp
// we want to read user input until they enter "0"

int a = -1;
while (true) { // always non-zero => infinite loop
    cout << "Enter a value" << endl;
    cin >> a;

    if (a == 0) break;
}
```

Our infinite loop will only stop when the user enters a zero;

`continue` works simillarly, but also very differently; When the loop hits a `continue` block, it skips the current iteration (executing the third clause in a for loop) and immediately goes back to the start of the loop; For example:

```cpp
for (int i = 0; i < 10; i++) {
    if (i == 6 || i == 7) continue;
    cout << i << endl;
}
```

Here the loop will write all numbers `0-9`, except for `6` and `7`, because we finish their iteration before they can get to `cout`;

### Enums

Enums synthetic sugar for regular whole numbers; We often run into a problem while programing where we need a value to contain the current state of some object, for example, a **traffic light**; A traffic light has 3 states, `RED`, `YELLOW` and `GREEN`; We need a way to distinguish between these, so lets say we make an int to hold the current state of the traffic light;

```cpp
int trafficLightState = 0; // this means red
trafficLightState = 1; // just yellow
trafficLightState = 2; // green
```
This is a convention we would have to follow for the entire program, and not just we, but anyone working with us on the same project; This is not only `error-prone` but also impossible to maintain; This is why the programming gods gave us `enums`; We can define one like so:

```cpp
enum TrafficLightState {
    RED, YELLOW, GREEN
}; // note the ; at the end
```

After we define the enum, we can make a variable of its type:

```cpp
int main() {
    TrafficLightState currentState = YELLOW;
    cout << currentState;
}
```

This will print out `1`, because an enum is just a name that will get replaced by a number; When the compiler looks at our code, wherever it sees `YELLOW`, it is gonna replace it with `1`, `GREEN` => `2` and so on;

What if we want to have custom values on our `enum` members? We would need to define it in the enum's definition:

```cpp
enum TrafficLightState {
    RED, YELLOW = 5, GREEN
};
```

Now, `RED` is `0` (has the default value), `YELLOW` is `5` and `GREEN` is `6`, since any undefined value will just increment itself based on the previous value; This means that if we do:

```cpp
enum TrafficLightState {
    RED = 1, YELLOW = 0, GREEN
};
```

This will make `GREEN` and `RED` have the same value `1`, which is `not particullarly useful`;

By default, an enum is just a `4 byte` integer number, but we can change it when defining the enum:

```cpp
enum E1 : char {
    VAL1, VAL2
}

enum E2 : short {
    VAL3, VAL4 
}

enum E3 : long {
    VAL5, VAL6
}
```

The size of `E1` now is `1 byte`, `E2` is `2 bytes` and the size of `E3` is `8 bytes`;

#### Enums as flags

***!!!Rather advanced!!!***

So we know that enums are just numbers under the hood, and those numbers are made up of bits; Now, what if we wanted to define an array of properties that an object can have; I'll use `Linux's file system` as an example;

On linux, each user has some level of access to each file on the system; Those levels of access are: `read`, `write` and `execute`; We could model it like so:

```cpp
class File {
    bool canRead = false;
    bool canWrite = false;
    bool canExecute = false;
};
```

And while this works, what happens if we have `30` of these `flags` that an object can have; Not only would we have to make even more variables, but we would also need to keep track of them (technically, an array works fine, but then we have magic numbers that we need to use for indexing the array in oreder to get the value of each flag); Not only is this tedious, but it takes much more space than needed; Each flag can either be `set` or `not set`, but each bool has to be `1 byte` meaning `256` different values instead of just `2`;

In order to get around this limitation, we can use a `flags enum`, a special kind of enum in which every single value is a power of two; So for our example we could have:

```cpp
enum FilePermissions {
    EXECUTE = 1, WRITE = 2, READ = 4
};

class File {
    FilePermissions permissions;
};
```

Now we have a single variable holding all the permissions for our specific user, but how can we access them? Using bit operations, we can check if a user has some privilege, or give/remove the privilege if needed; For example, let's make a couple of functions inside our `File` class:

```cpp
class File {
    string path;
    FilePermissions permissions;
public:
    string Read() {
        if (permissions & READ == 0) {
            cout << "You do not have required permissions";
            throw Exception;
        }
        // ... reading logic ...
    }


    void Write(string newContent) {
        if (permissions & WRITE == 0) {
            cout << "You do not have required permissions";
            throw Exception;
        } 
        // ... writing logic ...
    }

    void Execute() {
        if (permissions & EXECUTE == 0) {
            cout << "You do not have required permissions";
            throw Exception;
        } 
        // ... executing logic ...
    }
};
```

Here, we use the `binary and` (`&`) operator to check if some permissions exists in the permissions field; If the permission we need is there, the returned value will be `non-zero` (same as the value from our enum);

What if we want to grant a specific permissions, or remove it?

```cpp
    void AddPermission(FilePermissions perms) {
        permissions |= perms;
    }
    

    void RemovePermission(FilePermissions perms) {
        permissions &= ~perms;
    }
```

Tbh, I'm not sure how to write a coherent explanation for this part, I suggest you just write it down on a paper and try it for yourself if you're interested;