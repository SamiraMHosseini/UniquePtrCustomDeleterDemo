# Understanding C++: Smart Pointers, Custom Deleters, and Object Lifetime Control
This repository hosts a concise example illustrating some of the advanced concepts of C++ such as smart pointers, custom deleters, and controlling object lifetimes. The code features a Base class which is designed to be managed using a std::unique_ptr with a custom deleter.

# Code Explanation
The Base class has a private constructor and destructor, which means objects of this class can only be created and destroyed within member functions of the class itself. This is an example of controlling object lifetime and encapsulating the responsibility of object management within the class.

The static Base::Create method is used to create Base objects. This method returns a std::unique_ptr<Base> with a custom deleter.

The std::unique_ptr is a smart pointer, which is a class template in C++ that provides the functionality of a pointer but also automatically manages the memory for the object it points to. This is an example of RAII (Resource Acquisition Is Initialization), a common idiom in C++.

A custom deleter (Base::Destroy) is provided to the std::unique_ptr, which is a function that is called to delete the object when the std::unique_ptr goes out of scope. This custom deleter is necessary because the destructor of Base is private.
