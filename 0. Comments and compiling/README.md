# Comments

There are two types of comments in C++, same as C: `single-line` and `multi-line`;

Comments are used to, well, comment about the code; They are a directive that tells the compiler to skip them and is excluded from the compiled version of the code, meaning they're only used by humans in order to maintain a code base;

## Single-line comments

Made with double forward slashes, `//`, they make the rest of the line a comment which means that it gets ignored;

```cpp
cout << "Writing to console" << endl; // default way of writing output 
```

## Multi-line comments

Same purpose as single line, used when we have many things to comment out; Made with an opening and closing sign: `/*` and `*/`

``` cpp
/*
    This is a multiple line comment
    made so I don't need // on the start of every line
*/
```

# Compiling

C++ is a compiled language, meaning we need to turn it into an executable before being able to run it; In class we'll use the `CodeBlocks` enviroment for that, but if you don't want to use it and have the `gcc compiler` (comes preinstalled with linux) installed, the process is the same as with C, just a different command;

``` 
g++ *file-name*
```

This produces a file named `a;out` that is ready to be executed; If you want to change the name, you can use the `-o` flag, example:

```
g++ *script-file* -o *desired-output-file-name*
```