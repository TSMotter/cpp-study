# OOP

Object-oriented programming (OOP) is a programming paradigm that is based on the concept of "objects", which can contain data and code that manipulates that data. OOP languages are designed to encapsulate code and data into objects, and provide a way for objects to interact with one another through methods.

- There are several key characteristics that define object-oriented programming:

- Encapsulation: Encapsulation refers to the idea of bundling data and methods that operate on that data within a single unit, or object. This is meant to protect the data from outside access and manipulation, and to provide a clear interface for interacting with the object.

- Abstraction: Abstraction refers to the act of exposing only the essential features of an object, while hiding the details of its implementation. This allows objects to be used without the need to understand how they are implemented.

- Inheritance: Inheritance is a way to create a new class that is a modified version of an existing class. The new class is called the subclass, and the existing class is the superclass. The subclass can add or modify the behavior inherited from the superclass.

- Polymorphism: Polymorphism refers to the ability of a class to take on multiple forms. This can be achieved through inheritance, where a subclass can override or extend the methods of its superclass, or through the use of interfaces, which allow a class to implement a set of methods that are defined in an interface.
  - Polymorphism is a way of achieving runtime polymorphism, where the behavior of an object can change depending on its type. This is typically accomplished through inheritance, where a subclass can override or extend the methods of its superclass, or through the use of interfaces, which allow a class to implement a set of methods that are defined in an interface.

  - On the other hand, templates are a way of achieving compile-time polymorphism, where the code is generated for multiple data types at compile time. This is done by writing a template function or class that includes one or more "template parameters", which represent the types that the template can work with. When the template is used, the compiler generates a specialized version of the template for the specific data types that are being used.

  - In C++, templates and polymorphism can both be used to achieve code reuse and flexibility, but they work in different ways and serve different purposes. Templates are primarily used for generating code for multiple data types, while polymorphism is primarily used for creating objects with varying behavior.