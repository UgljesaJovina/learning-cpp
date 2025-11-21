# Functions, templates and classes

## Functions

Functions are reusable blocks of code that execute said block when `called` with or without arguments, based on their definition; They **can** (don't need to) `return` a value, again, based on what they're needed for; General syntax looks something like tis: 
```cpp
T1 functionName(T2 param1, T3 param2 ... Tn paramN) {
    // code block
    return val; // optional based on return type
}
```

Each parameter we define will have to be passed when the function is called, and a function can return any value of type `T1` when it finishes; Example:

```cpp
int sum(int a, int b) {
    return a + b;
}
```

This function takes two `int` parameters, gets their sum and `returns` that value back to the caller; Example of calling this function:

```cpp
int x = 5, y = 10;

int z = sum(x, y); // z = 15
```

Calling the function means writing the `function_name` followed by a set of parenthesis in which we pass the parameters needed, and then using the value `returned` if there is any; A function doesn't need to `return` anything if the `return type` is specified as `void`; This tells the program that the return value is uncertain and thus can't be placed in a type; In any other situation, the `reutrn statement` is required; Example:

```cpp
void sayHello() {
    cout << "Hello" << endl;
}

sayHello(); // writes out 'Hello' and nothing else
```

### Using pointers and references with functions

There is 3 ways to pass a parameter to a function: 

- `by value` - makes a copy of the original value in memory, meaning that the original data cannot be changed from within the function body;
- `by address` - makes a copy of the address of the original value; This allows us to directly access the memory where the original data is stored, changing it directly; Doing this is called a `side effect` and can cause bugs if you're not careful;
- `by reference` - practically identical to passing by address; It makes a copy of the address of the original data, with the only difference being the syntax used to access said data;

Examples:

```cpp
void setValueTo6(int x) {
    x = 6;
    cout << "the address of x: " << &x << endl;
}

void add7(int *x) {
    *x += 7;
    cout << "the address of x: " << &x << endl;
}

void subtract3(int &x) {
    x -= 8;
    cout << "the address of x: " << &x << endl;
}

int main() {
    int a = 0, b = 1, c = 2;

    cout << "The address of a: " << &a << ", ";
    setValueTo6(a);
    cout << "The address of b: " << &b << ", ";
    add7(&b);
    cout << "The address of c: " << &c << ", ";
    subtract3(c);

    cout << "a: " << a << ", b: " << b  << ", c: " << c << endl;
}
```

Output:
```
The address of a: 0x7ffc7d3178cc, the address of x: 0x7ffc7d3178ac
The address of b: 0x7ffc7d3178d0, the address of x: 0x7ffc7d3178a8
The address of c: 0x7ffc7d3178d4, the address of x: 0x7ffc7d3178d4
a: 0, b: 8, c: -6
```

We can see that `a` did not get changed since we only changed the local object in the function, not the original; You can see this by the fact that `a` and `x` have different addresses; `b` got changes but we had to access it's value through the pointer passed; `c` got changed too but if we look at the addresses for `c` and `x` we notice they're the same; This isn't because the address magically appeared in the function, but rather because there is a hidden pointer created for the reference to work, we just can't access it; C++ compiler treats references as aliases, so when we write `x`, it's the same as writing `*x` if x was a pointer, and if we write `&x` its the same as writing just `x`; Example:

```cpp
void func(int a, int *b, int &c) {
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    cout << "&a: " << &a << ", &b: " << &b << ", &c: " << &c << endl;
    cout << "*a: " << "can't" << ", *b: " << *b << ", *c: " << "can't" << endl;
}

int a = 15;
func(a, &a, a);
```

Output:

```
a: 15,               b: 0x7ffdbccce3c4,  c: 15
&a: 0x7ffdbccce3ac, &b: 0x7ffdbccce3a0, &c: 0x7ffdbccce3c4
*a: can't,          *b: 15,             *c: can't
```

Notice how `b` and `&c` are the same, as well as `*b` and `c`;

Passing references and pointers like this can be dangerous due to the `side effects` of changing data outside their scope; This is why we have the `const` keyword; If we look at the function definition for something like `strlen`, a function that returns the length of a string passed to it, we can see that the parameter is of type `const char *__s`; This means that the poiner is readonly => `*__s = 'a'` is not allowed and will not compile; The same can be applied to references; We will also see this with the `copy constructor` in `classes`;

### Default parameter values

Not all functions need a value for each of their parameters, some values can have a default value; For example, we can have a function like this:

```cpp
void writeAndStore(char src[], char* dest = NULL) {
    cout << "Function: " << src << endl;
    
    if (dest) {
        strcpy(dest, src); 
        // function for copying a string from src to dest 
    }
}

int main() {
    char dest[100];

    writeAndStore("Some string");
    writeAndStore("Some string", dest);

    cout << "Main: " << dest << endl;
}
```

Output:

```
Function: Some string
Function: Some string
Main: Some string
```

Here we made a function that can work with only one parameter, the `src`; We made it so that the function will always write an output, and if needed, we can pass a destination to the function if we want to save a copy of the written string;

Default parameters always need to come last in the parameter list, the required parameters need to come first for the compiler to know how to parse the function call; Another example:

```cpp
void defaultFunction(int a = 5, int b = 6, int c = 7) {
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
}

int main() {
    defaultFunction();
    defaultFunction(8, 9);
}
```

Output:

```
a: 5, b: 6, c: 7
a: 8, b: 9, c: 7
```

If we want to set just the value of `c`, we can't without setting the values for `a` and `b` first;

### Function name overloading

Function name overloading means that we can define multiple behaviours for the same function name; For example if we want to have a function that prints out a whole number, we could create two implementations for it: one that takes an `int` and one that takes a `double`; In the double variation we can then round the number and write it out; Example:

```cpp

void printWhole(int a) {
    cout << "Int implementation: " << a << endl;
}

int printWhole(double d) {
    int retVal = round(d);
    cout << "Double implementation: " << retVal << endl;
    return retVal;

    // overloaded functions can have different return types
}

int main() {
    printWhole(5);
    printWhole(5.67);
}
```

Output: 
```
Int implementation: 5
Double implementation: 6
```

Functions defined in the same scope need to differ in their signature; A function signature consists of a `function name` and a `parameter list` (number and type of parameters);

This means that we can have a function `toPower` implemented as `int toPower(int x)` which would just square the number `x`, and also a `int toPower(int x, int y)` which would raise `x` to the power of `y`; I am aware this could have been done with a default value for `y` but I can't think of a better example rn;

## Classes, structs and unions

### Classes

Classes represent a way to combine multiple simple data types into one complex type with custom `data encapsulation` logic (what can and can't be accessed); They are a way for use to design a blueprint that mimics an object we want to represent through the use of `member variables` or `fields` and `member functions` or `methods`; Visually, it looks something like:

<img src="class_visual.png">

Source: [GeeksForGeeks](https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/)

Code example:

```cpp
enum Colour {
    NONE, RED, GREEN, BLUE, BLACK, YELLOW, WHITE, BROWN, SOME_COLOUR
};

class Dog {
    string name;
    Colour furColour;
    Colour eyeColour;
    double height;
    double weight;

public:
    string getName() { return name; }
    Colour getFurColour() { return furColour;}
    Colour getEyeColour() { return eyeColour;}
    double getHeight() { return height; }
    double getWeight() { return weight; }
};
```

Here, we defined 5 `member variables`, and 5 `member functions`; We can also see an `access modifier` **`public`**; Class definitions also need to end with a `;`;

#### Objects

Objects are `instantiated` classes; Since a class doesn't take any space in memory because it is just a blueprint, when we want to use it we need to instantiate it, meaning we have to take up memory for each `field` in the class; This means that we take up `32 bytes` for the string, `4` for `furColor` and another `4` for `eyeColour` and then `8` two times for `height` and `weight`; All in all, each `Dog` object when instantiated will require `56 bytes` of memory;

We can access data stored in an object using the `.` operator; Doing `object_name.field_name` or `object_name.method_name()` will attempt to access said field / call said function; I say attempt since `access modifiers` can restrict what we can and can't see on an object;

<hr>

**Access modifiers** are special tags we place inside a `class` or `struct` definition to change where they're members are visible from; `Access modifiers` include:

- `private` - the default modifier for all `class` members; It restricts access of private members outside the class itself; We can see that in our `Dog` example, we are able to read the values of `private fields` **name, furColour, eyeColour, height, weight** from their respective member function, but if we tried to read their values directly from `main`, we would instead get a compilation error;
- `public` - the default modifier for all `struct` members, also the only difference between the two; `public` fields allow for read/write permissions to anyone anywhere, and `public` methods can be called from anywhere, no restrictions;
- `protected` - will be explained in [inheritance](#inheritance)

Setting an access modifier for a field or function is done by doing `modifier_name:` on a line; After that line, every member will have said `access modifier` applied to it;

<hr>

**Instantiating**:

Instantiating is done through a `constructor`, a special method that is called when a new `instance` of a `class` is created; It is used to set initial values for `class` fields or do custom logic when a new `instance` get made; By default, if we don't specify anything C++ provides an `empty constructor`, a constructor that takes no parameters and does nothing; Example of calling an empty constructor:

```cpp
Dog d;
```

This will create a `Dog` instance in memory but will not set the values of fields, meaning that what we read out of them afterwards is completly **unpredictable**; Example:

```cpp
Dog d;
cout << d.getHeight() << endl << d.getWeight() << endl;
```

Output: 

```
2.11653e+214
6.95298e-310
```

This is because `height` and `weight` currently contain any bytes that were in memory before the object got made, and then try to interpret it as a double; We can create our own empty constructor to stop this `unpredictability` from happening; A constructor can be defined using just the `class_name` followed by parenthesis that list parameters required; Example:

```cpp
class Dog {
    // ...fields
public:
    Dog() {
        name = "";
        furColour = NONE;
        eyeColour = NONE;
        height = 0;
        weight = 0;
    }
};
```

Writing the values of `height` and `weight` now will give us `0` and `0`;

If we wanted to initialize our `Dog` with some value though, we would need to make a *"normal"* constructor, example:

```cpp
class Dog {
    // ...fields
public:
    // empty constructor
    Dog(string _name, Colour _furColour, 
        Colour _eyeColour, double _height, double _weight) 
    {
        name = _name;
        furColour = _furColour;
        eyeColour = _eyeColour;
        height = _height;
        weight = _weight;
    }
};
```

Since multiple constructors can exist for a single class, we need to make sure they differ in their `signature`, just like regular functions; Function signature consisted of a `name` and a `parameter list`, but since we don't have names for constructors, and instead just the return type, we need to make them different with the `parameter list`; This was done, since our first constructor has **0** parameters and our second has **5**; Example:

```cpp
Dog d1;
Dog d2("Brian", WHITE, BLACK, 110, 50);
```

This creates two objects, one using the default values for all fields like we set in the `default constructor`, and the other containing custom data we passed; If we were to make a function `writeDog`, we could see the difference:

```cpp
void writeDog(Dog d) {
    cout << "Name: " << d.getName()
        << ", fur colour: " << d.getFurColour()
        << ", eye colour: " << d.getEyeColour()
        << ", height: " << d.getHeight()
        << ", weight: " << d.getWeight() << endl;
}

int main() {
    writeDog(d1);
    writeDog(d2);
}
```

Doing this will give us the following output:

```
Name: , fur colour: 0, eye colour: 0, height: 0, weight: 0
Name: Brian, fur colour: 6, eye colour: 4, height: 110, weight: 50
```

We can see how the two object hold different data, but right now there is no way to change what they have contained within themselves since we only defined `getter` functions and no `setter` functions, and all our fields are `private`;

`Setter functions` for our dog would look something like:

```cpp
class Dog {
    // ....
public:
    void setName(string _name) { name = _name; }
    void setFurColour(Colour _furColour) { furColour = _furColour; }
    void setEyeColour(Colour _eyeColour) { eyeColour = _eyeColour; }
    void setHeight(double _height) { height = _height; }
    void setHeight(double _weight) { weight = _weight; }
}
```

We can now use these `setter functions` to set the individual values on an object after it was already created; It's worth noting that functions don't take up memory on an object, they're **not** a member of the object, they're a member of a class; Our `Dog` can have hundreds of functions defined for it, a `bark`, `loudBark`, `softBark`, `softerBark`, `softestBark` etc. and each `Dog` object created would still take up only `56 bytes`; We'll get to that in a bit;

Before that though, we need to fix the `writeDog` function since it is ***really*** bad; First of all, we are passing the object by value; This is inefficient since it means that we need to copy `56 bytes` onto the stack, and thus the recommended way is to copy by `adress` or by `reference`, which will copy over only `8 bytes` of data; Since this poses a potential `side effect` problem if not implemented carefully; We can use a `const pointer` or `const reference` to make the value `read-only`; Example:

```cpp
void writeDog(const Dog* d) {
    cout << "Name: " << d->getName()
        << ", fur colour: " << d->getFurColour()
        << ", eye colour: " << d->getEyeColour()
        << ", height: " << d->getHeight()
        << ", weight: " << d->getWeight() << endl;
}

void writeDog(const Dog &d) {
    cout << "Name: " << d.getName()
        << ", fur colour: " << d.getFurColour()
        << ", eye colour: " << d.getEyeColour()
        << ", height: " << d.getHeight()
        << ", weight: " << d.getWeight() << endl;
}
```

We have a couple of issues here, but before that, let's discuss the `pass by pointer` function; We can notice that we access our `getter functions` a bit differently now; Instead of doing the `.` operator, we are using the `->` operator; This is because the `.` requires an object to be used on and we are giving it a pointer; A way to go around this would be to do something like `(*d).getName()`, and this is exactly what `->` does, just quicker and prettier; 

In a way, it's simillar to the `[]` operator we use on `arrays`, just a shorter way to **dereference** a value and access a specific part of data; Fun *(impractical)* trick at the end of the segment :);

Now for the issues; Firstly, we can't have function overloads where one is `pass by reference` and the other `pass by value`; This is because the compiler doesn't know which one to invoke when we call `writeDog(d1)`, both fit the function call; The second issue is that this actually won't compile with our current implementation; Had we been accessing `fields` directly, there would be no issue with these two functions, but since we're doing it through a function, C++ has no way of knowing (currently) if the function is actually changing any state on the object;

<img src="const_error.png">

Had we called `obj->setName("someName")` to C++ that is practically the same thing; The way we can fix this issue is by redefining our `getters`; Currently, they look something like <br>`void getNmae() { return name; }`<br>If we wanted to tell C++ that this function does not change any state on the object is by using `const` on the `function body`, so something like `void getName() const { return name; }`; If we tried this with a `setter`, we would get an error since a `constnt body` cannot change member variables and can instead only change [static fields](#static-fields), [mutable fields](#mutable-fields), values passed through pointers;

Our new setters should look like this:

```cpp
string getName() const { return name; }
Colour getFurColour() const { return furColour;}
Colour getEyeColour() const { return eyeColour;}
double getHeight() const { return height; }
double getWeight() const { return weight; }
```

This will remove the error and allow `pass by pointer/reference` functions to ***`function`*** (🤣);