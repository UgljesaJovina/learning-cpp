# Comments and compiling

## Comments

There are two types of comments in C++, same as C: `single-line` and `multi-line`;

Comments are used to, well, comment about the code; They are a directive that tells the compiler to skip them and is excluded from the compiled version of the code, meaning they're only used by humans in order to maintain a code base;

### Single-line comments

Made with double forward slashes, `//`, they make the rest of the line a comment which means that it gets ignored;

```cpp
cout << "Writing to console" << endl; // default way of writing output 
```

### Multi-line comments

Same purpose as single line, used when we have many things to comment out; Made with an opening and closing sign: `/*` and `*/`

``` cpp
/*
    This is a multiple line comment
    made so I don't need // on the start of every line
*/
```

## Compiling

C++ is a compiled language, meaning we need to turn it into an executable before being able to run it; In class we'll use the `CodeBlocks` enviroment for that, but if you don't want to use it and have the `gcc compiler` (comes preinstalled with linux) installed, the process is the same as with C, just a different command;

``` 
g++ *file-name*
```

This produces a file named `a;out` that is ready to be executed; If you want to change the name, you can use the `-o` flag, example:

```
g++ *script-file* -o *desired-output-file-name*
```

## Preprocessors and using directives

A preprocessor is a special instruction we give the compiler; Most commonly, we use the `#include` preprocssor to include **functions** and **classes** defined in other files so that the main file doesn't become bloated; Preprocessors start with a `#` and happen before the compilation even starts, most common ones are:

- `#include` - as stated before, it is used to include some definitions from other files like libraries or user made files; The most common library we'll use is `iostream` (input and output) and in order to include it we have to do `#include <iostream>`; We use `<>` for libraries since they're stored in special directories, but for user defined scripts we'll use `""`
- `#define` - used for creating a **macro**; Macros are reusable pieces of code that we can give an allias to because the preprocessor will go through the code and do `find and replace` over all defined macros; For example: `#define MAX_ARRAY_SPACE 100` will define a keyword **MAX_ARRAY_SPACE** and wherever it is found, it will get replaced with **100**
- `#ifdef/#ifndef` - conditionally compiles code if some macro is defined, has to end with an `#endif` directive; Example:

```cpp
#ifndef MAX_ARRAY_SPACE
// code...
#endif
```

The code here gets compiled only if **MAX_ARRAY_SPACE** exists;

- `#pragma` - directly tells the compiler what to do with this file; Will come in very useful with `classes`

### Using directives

I'm not sure how to explain so i'll just show;

```cpp
#include <iostream>
// contains classes, objects and functions tied to input and output

int main() {
    std::cout << "Some message" << std::endl;
    // cout is used for writing out some output, but we have to put "std::" before it
    // This is because cout is part of a 'namespace' called "std" and we have to tell C++ where to take cout from
}
```

A way to fix having to write what namespace the thing we want to use comes from, we can do:

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Some message" << endl;
}
```

We have now included everything from the std namespace, meaning we no longer need to specify it for `cout` and `endl`;

Another use for using:

```cpp
#include <iostream>

using std::cout;

int main() {
    int age;
    cout << "Enter your age: " << std::endl;
    std::cin >> age;
}
```

Here we only included `cout` from `std`, so everything else from the namespace still needs to be specified;