# Input and Output

## Basic Output

In `C++`, output is usually done thorugh the use of the `cout` object found in the `<iostream>` header; `cout` is not a function, unlike many other programing languages (like `C` and `printf`), but rather just an object representing the standard output stream we can write to using the `insertion operator <<`, or the funcitons like `put` and `write` (never used (for standard output)); Example:

```cpp
int god = 20;
cout << "I am ";
cout << god;
cout << " years old";
```

This will write `I am 20 years old`, handling the conversion from `int` to `string` automatically; It will not put a `newline` character by itself, instead writing everything to the same line; There are two main ways to handle going to the new line, the newline character `'\n'`, or the [manipulator](#manipulators) `endl`;

Writing to the newline by itself isn't currently the only problem, but this looks hideous; We can fix that by chaining `<<` operators on the same `cout` object; Example:

```cpp
int val1 = 67, val2 = 69;

cout << "The value of val1 is: " << val1 << "\n";
cout << "The value of val2 is: " << val2 << endl;
```

The output is:
```
The value of val1 is: 67
The value of val1 is: 69
```

on 2 different lines; Functionally, `\n` and `endl` are very similar, the difference will be explained in the manipulators section;