#include <iostream>
#include <memory>

// Define a struct called Base
struct Base
{
	// This static method creates a Base object and returns a unique_ptr to it. 
	// The unique_ptr uses a custom deleter defined in the same struct.
	static std::unique_ptr<Base, void (*)(Base*)> Create()
	{
		std::cout << "Create gets invoked\n";
		// A new Base object is created with 'new', and it's immediately placed in a unique_ptr.
		// The custom deleter, Base::Destroy, is provided as the second template argument to unique_ptr.
		return std::unique_ptr<Base, void (*)(Base*)>(new Base(), Base::Destroy);
	}

	// This static method is the custom deleter for Base objects.
	// It takes a pointer to a Base object, and deletes it.
	static void Destroy(Base* pBase)
	{
		//Bookkeeping
		std::cout << "Destroy gets invoked\n";
		delete pBase;
	}

protected:
	// The constructor and destructor are protected, which means objects of type Base 
	// can only be created and destroyed from within member functions of the class or derived classes.
	Base() = default;  // Default constructor
	~Base() = default; // Default destructor

};
struct Derived : Base {
	Base::Base;

};
int main()
{
	// Create a Base object using the static Create method.
	// The returned unique_ptr (with custom deleter) is stored in pB.
	const auto upBase = Base::Create();
	std::cout << "From main()\n";
	// When upBase goes out of scope here at the end of main, the Base object will be automatically deleted
	// using the custom deleter, Base::Destroy.
	Derived d;
}
