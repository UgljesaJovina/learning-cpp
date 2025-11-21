# Input and Output

## Basic Output

In `C++`, output is usually done thorugh the use of the `cout` object found in the `<iostream>` header; `cout` is not a function, unlike many other programing languages (like `C` and `printf`), but rather just an object representing the **standard output stream** we can write to using the `insertion operator <<`, or the funcitons like `put` and `write` (never used (for **standard output**)); Example:

```cpp
int age = 20;
cout << "I am ";
cout << age;
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

on 2 different lines; Functionally, `\n` and `endl` are very similar, the difference will be explained in the [manipulators](#manipulators) section;

I've mentioned the **standard output steam** a couple of times already, but in most cases that means the console; If you're running the program on linux, you can actually redirect what is considered the **standard ouput** by writing something like `./a.out > output.txt`; This will create (if it doesn't exist) a file called `output.txt` and put all the output of the program into said file;

The `write` and the `put` functions are `member functions` (mentioned in classes) of the `cout` object; There exist more member functions than just these two, they will be mentioned later; Usage example:

```cpp
char s[] = "Faculty of Technical Sciences";
char a = 'a';

cout.write(s, 15);
cout.put(a);
```

This outputs: `Faculty of Techa` - the first 15 characters of the string and then the character `a` in the same line; If we wanted different lines we would have to do:

```cpp
    char s[] = "Faculty of Technical Sciences";
    char a = 'a';

    cout.write(s, 15);
    cout.put('\n');

    cout.put(a);
    cout.put('\n');
```

If we want to print the whole string, we either have to guess the number of characters inside it (don't forget that, like in C, they are null (`'\0'`) terminated) and set that as the second parameter for write, or use the `strlen` function found in the `cstring` header file; If we put a really big number like `100`, the output would look something like this:

```
Faculty of Technical SciencesP�GZwzF<D�;���d��ʡ�YwH�d���OZ��]
                                                             �\H�d�
a
```

This happens because the program is trying to read the memory we didn't set, and so it tries to convert random bytes into characters that are often **undefined**;

One of the reasons write is almost never used for regular program output is because it doesn't handle type conversion implicitly; If you look at how the function is declared, you will find: `write(const char* __s, streamsize __n);`; **Streamsize** is basically just a `long long`, a `64-bit signed` number, but the first parameter `REQUIRES` a string pointer; This means that if we wanted to print out a number, we would first need to create a string that can contain each digit, convert each digit to a character manually, and then write it to the output;

## Basic Input

Just like how `cout` can be thought of as a counterpart to `printf`, we can think of `cin` as a counterpart to `scanf`; It is used to take input from the `standard input stream` of the program (can be redirected on linu using `<` like the output); We can then store the value read into a variable without having to think about conversion since it is handled for us; Example:

```cpp
int age;

cout << "How old are you: ";
cin >> age;
```

Compared to `cout` that used the `insertion operator`, `cin` uses the `extraction operator >>`;

Just like `cout`, we can chain multiple `extraction operators` to a single `cin` object, so if we needed to input for example a first and last name of a person, we could do it like this:

```cpp
char name[100], surname[100];

cin >> name >> surname;
cout << name << " " << surname << endl;
```

Like `cout` this isn't the only way to read input from the input stream, but is the most common when working with a console; Having said that we also have: 

- `get(char *s, streamsize n)` - reads up to the next `n` characters; Working with the `extraction operator` will stop at a white space (`' '`, `'\n'`), but using get will continue;
- `getline(char *s, streansize n)` - same as get, but will stop either when it reads `n` characters, or reads a `'\n'` or `EOF` (end of file)
- `clear()` - clears the error flags fo an input stream; Sometimes when, for example, a wrong type is read from the input, the buffer will close up because of the issue; This funciton resets it and allows us to continue reading from that stream;
- `sync()` - clears the input buffer, avoiding issues where characters remain stuck inside it;
- `ignore(int n)` - same as sync, but will clear only the next `n` characters;

## Escape characters

Escape characters are special characters that tell the program how to format the output, main examples:

- `\n` - inserts a new line in place of the `\n`
- `\t` - makes a **tab** characters, basically just a bunch of spaces
- `\\` - writes a `\` character
- `\"` - write the `"` character
- `\'` - write the `'` character
- `\r` - moves the cursor to the begining of the current line, allowing us to change what was already written
- `\0` - null character; Terminates strings in C and C++

## Manipulators

Manipulators are like special instructions for the input/output buffers on how they should read/write their data; We have already seen one, the `endl` manipulator; They can be used in function form, getting called as a member function of `cout`, or can be used after the `insertion operator`; Most manipulators are found in the `<iostream>` header, but some are from the `<ios>` and `<iomanip>` headers;

### Output manipulators

- `endl` - puts a newline character into the output buffer and `flushes` it, outputing all the buffered bytes immediatelly; Output buffers will sometimes pool characters so they can be output all at the same time instead of sequentially;
- `precision(int n)` - part of `<iomanip>`, sets the precision of floating point numbers written to the output stream; Inline version is `setprecision(int n)`; Examples:
```cpp
float a = 5.743;
cout.precision(2);
cout << a << endl; 

float b = 42.784;
cout << setprecision(2) << b << endl;
```
This will output `5.7` and `43` since it just limits (and rounds) the total number of digits, not just the decimal part; For that we need another manipulator, `fixed`;

- `fixed` - an inline manipulator used before the `setprecision` manipulator to make the precision be applied to the decimal part of the number; Example;

```cpp
float a = 570.43852;
cout << fixed << setprecision(2) << a << endl;
```

This outputs `570.44` like expected; It's also worth noting that these modifiers **stay active until they're overriden**; This means that any other floating point number we try to write is going to be rounded at **2** digits;

- `bitset<N>(long long val)` - while not specifically a manipulator, it can be used as one of the main ways to write a whole number's binary representation; The `N` represents the **amount** of bits you want to write, while `val` is the value you want to convert into bits; It requires including the `<bitset>` header; Example:

```cpp
int a = 55;
cout << bitset<8>(a) << endl;
```

The output is: `00110111`;

- `setbase(int base)` - part of `<iomanip>`, used to represent numbers in octal, decimal or hexadecimal notation; `base` can be either `8`, `10` or `16`;
- `showbase` - prints out `0x` or `0` for `hexadecimal` and `octal` numbers;
- `boolalpha` - makes `bool` values write out as `true`/`false`
- `noboolalpha` - makes `bool` values write out as `1`/`0` (default behaviour)
- `setw(int n)` - found in `<iomanip>`, sets the default width of the **next** write; Unlike `fixed` and `setprecision`, it only works for the next output; It will write at least `n` characters to the output, padding the output as nececary; You can use `setfill` to controll what character is used for padding (the default is a **space** `' '`) and `left` or `right` to control which part of the *"block"* that data is gonna take; Example:

```cpp
cout << setw(5) << 5 << endl;
cout << setw(5) << left << setfill('-') << 5 << endl;
cout << setw(5) << 5 << endl;
cout << setw(5) << right << 5 << endl;
cout << setw(5) << "24 karat gold" << endl;
```

The output:

```cpp
    5
5----
5----
----5
24 karat gold
```

Explanation: The default side `setw` chooses is `right`, and the default padding character is `space`; On the next line we change the padding character to `-` and the side to `left`; The third line has the same properties since `setfill` and `side` persist between writes; In the 4th line we bring it back to the right and the right line is too long for the allocated space to have an effect;


### Input manipulators

- `setbase(n)` - controls how the input number will be interpreted, allows for inputing numbers in the hexadecimal or octal format;
- `boolalpha` - allows input of bool values with `true`/`false`
- `noboolalpha` - reverts
- `ws` - discards all white space