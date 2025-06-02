#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <list>
#include <algorithm>
#include <functional>
#include <string>

/*
================================================================================
|   C++ Pointers to Functions & Lambdas - Study & Lab Summary
|-------------------------------------------------------------------------------
| - Function pointers allow dynamic invocation of functions.
| - Syntax: returnType (*ptrName)(paramTypes) = functionName;
| - Lambdas with no capture can be assigned to function pointers.
| - Lambdas with captures require std::function.
| - You can pass function pointers or std::function as parameters to functions,
|   including those that operate on classes, structs, STL containers, etc.
| - Data type for pointer to lambda (no capture): auto or explicit type.
| - Data type for pointer to lambda (with capture): std::function.
| - Examples below cover:
|     * Pointer to regular function
|     * Pointer to overloaded function (with explicit cast)
|     * Pointer to lambda (no capture) - explicit and auto
|     * std::function with lambda (with capture)
|     * Array of function pointers
|     * Passing function pointer to functions with various parameter types
|     * Using function pointer with std::sort
|     * Using function pointer with classes, structs, vectors, maps, lists, trees
================================================================================
*/

/*  ================================================================================
                        Declarations of Structs / Classes
    ================================================================================    */
struct Point
{
    int x, y;
    Point(int x_, int y_) : x(x_), y(y_) {}
};

class Person
{
public:
    std::string name;
    int age;
    Person(std::string n, int a) : name(n), age(a) {}
};

// Tree node and traversal with function pointer
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

/*  ================================================================================
                        Functions Prototypes
    ================================================================================    */
// Regular functions
int add(int a, int b);
int sub(int a, int b);
bool compare_desc(int a, int b);
bool compare_asc(int a, int b);

// --- Pointer to overloaded function (need explicit cast) ---
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }

// Function operating on struct
void print_point(const Point &p);

// Function operating on class
void print_person(const Person &p);

// Function operating on vector
void print_vector(const std::vector<int> &v);

// Function operating on map
void print_map(const std::map<std::string, int> &m);

// Function operating on list
void print_list(const std::list<std::string> &l);

// Function pointer as parameter for vector operation
void apply_to_vector(const std::vector<int> &v, void (*func)(int));

// Function pointer as parameter for class
void apply_to_person(const Person &p, void (*func)(const Person &)) { func(p); }

// Function pointer as parameter for struct
void apply_to_point(const Point &pt, void (*func)(const Point &)) { func(pt); }

// Tree node and traversal with function pointer
void inorder(TreeNode *root, void (*visit)(int));

/*  ================================================================================
                        Main Function - Entry Point
    ================================================================================    */
int main()
{
    // --- Pointer to regular function ---
    int (*calculator_ptr)(int, int) = add;
    std::cout << "add(10, 20) via pointer: " << calculator_ptr(10, 20) << std::endl;

    // --- Assigning different functions to the same pointer ---
    calculator_ptr = sub;
    std::cout << "sub(10, 20) via pointer: " << calculator_ptr(10, 20) << std::endl;

    // --- Pointer to overloaded function (need explicit cast) ---
    //      int multiply(int a, int b) { return a * b; }
    //      double multiply(double a, double b) { return a * b; }
    // Using explicit cast to point to the int version
    int (*mul_int_ptr)(int, int) = multiply;
    double (*mul_double_ptr)(double, double) = multiply;
    std::cout << "multiply(int):    " << mul_int_ptr(3, 4) << std::endl;
    std::cout << "multiply(double): " << mul_double_ptr(2.5, 4.0) << std::endl;

    // --- Pointer to lambda (no capture) ---
    auto lambda_add = [](int a, int b)
    { return a + b; };
    int (*lambda_ptr)(int, int) = lambda_add; // explicit type
    auto lambda_auto = lambda_add;            // auto type
    std::cout << "lambda_ptr(3,4):  " << lambda_ptr(3, 4) << std::endl;
    std::cout << "lambda_auto(3,4): " << lambda_auto(3, 4) << std::endl;

    // --- std::function with lambda (with capture) ---
    int offset = 10;
    std::function<int(int, int)> lambda_with_capture = [offset](int a, int b)
    { return a + b + offset; };
    std::cout << "lambda_with_capture(1,2): " << lambda_with_capture(1, 2) << std::endl;

    // --- Array of function pointers ---
    int (*ops[2])(int, int) = {add, sub};
    std::cout << "ops[0](5,2) = " << ops[0](5, 2) << ", ops[1](5,2) = " << ops[1](5, 2) << std::endl;

    // --- Passing function pointer to another function (vector) ---
    std::vector<int> v = {1, 2, 3};
    auto print_int = [](int x)
    { std::cout << x << " "; };
    apply_to_vector(v, print_int);
    std::cout << std::endl;

    // --- Passing function pointer to another function (class/struct) ---
    Person p("Alice", 30);
    apply_to_person(p, print_person);

    Point pt(7, 8);
    apply_to_point(pt, print_point);

    // --- Passing function pointer to map and list printing ---
    std::map<std::string, int> m = {{"one", 1}, {"two", 2}};
    print_map(m);

    std::list<std::string> l = {"apple", "banana", "cherry"};
    print_list(l);

    // --- Using function pointer with std::sort ---
    std::array<int, 6> nums{100, 99, 5, 180, 1000, 33};

    // ---
    std::sort(nums.begin(), nums.end(), compare_desc); // descending
    std::cout << "Sorted descending: ";
    for (auto element : nums)
        std::cout << element << " ";
    std::cout << std::endl;

    std::sort(nums.begin(), nums.end(), compare_asc); // ascending
    std::cout << "Sorted ascending: ";
    for (auto element : nums)
        std::cout << element << " ";
    std::cout << std::endl;

    // --- Tree traversal with function pointer ---
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    std::cout << "Tree inorder: ";
    inorder(root, print_int);
    std::cout << std::endl;
    delete root->left;
    delete root->right;
    delete root;

    // --- Array of pointers to lambdas (no capture) ---
    auto l_add = [](int a, int b)
    { return a + b; };
    auto l_sub = [](int a, int b)
    { return a - b; };
    int (*lambda_ops[2])(int, int) = {l_add, l_sub};
    std::cout << "lambda_ops[0](8,3): " << lambda_ops[0](8, 3) << ", lambda_ops[1](8,3): " << lambda_ops[1](8, 3) << std::endl;

    // --- Using std::function for any callable (function, lambda, functor) ---
    std::function<int(int, int)> fun = add;
    std::cout << "std::function add: " << fun(5, 6) << std::endl;
    fun = lambda_add;
    std::cout << "std::function lambda: " << fun(5, 6) << std::endl;

    return 0;
}

/*  ================================================================================
                        Functions Inplementations
    ================================================================================    */
// Regular functions
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
bool compare_desc(int a, int b) { return a > b; }
bool compare_asc(int a, int b) { return a < b; }

// Function operating on struct
void print_point(const Point &p) { std::cout << "Point(" << p.x << ", " << p.y << ")\n"; }

// Function operating on class
void print_person(const Person &p) { std::cout << "Person: " << p.name << ", age " << p.age << std::endl; }

// Function operating on vector
void print_vector(const std::vector<int> &v)
{
    std::cout << "Vector: ";
    for (auto x : v)
        std::cout << x << " ";
    std::cout << std::endl;
}

// Function operating on map
void print_map(const std::map<std::string, int> &m)
{
    std::cout << "Map: ";
    for (const auto &[k, v] : m)
        std::cout << k << ":" << v << " ";
    std::cout << std::endl;
}

// Function operating on list
void print_list(const std::list<std::string> &l)
{
    std::cout << "List: ";
    for (const auto &s : l)
        std::cout << s << " ";
    std::cout << std::endl;
}

// Function pointer as parameter for vector operation
void apply_to_vector(const std::vector<int> &v, void (*func)(int))
{
    for (auto x : v)
        func(x);
}

// Function pointer as parameter for class
void apply_to_person(const Person &p, void (*func)(const Person &))
{
    func(p);
}

// Function pointer as parameter for struct
void apply_to_point(const Point &pt, void (*func)(const Point &))
{
    func(pt);
}

// Tree node and traversal with function pointer
void inorder(TreeNode *root, void (*visit)(int))
{
    if (!root)
        return;
    inorder(root->left, visit);
    visit(root->val);
    inorder(root->right, visit);
}

/*
================================================================================
|   Interview Questions & Answers
|-------------------------------------------------------------------------------
| Q1: What is a function pointer? How do you declare and use it?
| A1: A variable that stores the address of a function. Syntax: int (*ptr)(int,int) = add;
|     Call with ptr(a,b).
|
| Q2: Can you point to a lambda? What about lambdas with captures?
| A2: Yes, if the lambda has no capture (e.g., [](int a,int b){return a+b;}). For lambdas with captures,
|     use std::function, not a raw function pointer.
|
| Q3: When would you use std::function instead of a raw function pointer?
| A3: When you want to store lambdas with captures, functors, or any callable object, not just plain functions.
|
| Q4: How do you pass a function pointer as a parameter to a function?
| A4: Declare the parameter as a function pointer type, e.g., void foo(int (*f)(int,int)).
|
| Q5: How do you use function pointers with STL containers (vector, map, etc.)?
| A5: Pass function pointers or lambdas to algorithms like std::sort, std::for_each, or your own functions.
|
| Q6: What is the type of a pointer to a lambda? What if you use auto?
| A6: For no-capture lambdas: int (*ptr)(int,int) = lambda; or auto ptr = lambda;
|     For lambdas with capture: use std::function<int(int,int)>.
|
| Q7: How do you use function pointers with classes, structs, or trees?
| A7: Pass function pointers to functions that operate on these types, e.g., traversal, printing, etc.
|
| Q8: Can you have an array of function pointers or lambdas?
| A8: Yes, as long as the signatures match. Example: int (*ops[2])(int,int) = {add, sub};
|
| Q9: What are the advantages and disadvantages of function pointers?
| A9: Advantages: dynamic dispatch, flexibility. Disadvantages: less type safety, harder to debug, can't store state (use lambdas/std::function for that).
================================================================================
*/