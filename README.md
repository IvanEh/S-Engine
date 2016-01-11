# Overview
  # STUB
  
# Guidelines
Some guidelines that I want to follow while writing the project:

- Project layout
  - root container for source is src/ folder
  - organizing modules into packages(aka dirs)
  - all the headers should go into header/ directories
  
- Language style
  - C++11
  - {}-initialization over ()-init and assignment =
  - simple objects with the least dependencies on each other
  - the field should be public only if all the possible values are correct. Provide setters and getters anyway.
  - class names - pascal case, methods, functions and fields - camel case. Simple structs, namespaces - snake case
  - soft tabs - 4 spaces
  - use #pragma once guard for simplicity
  - order on includes: related header, C/C++ library, libraries, project's headers
  - if possible - do not seperate definition and declaration
  - use explicit for conversion operators
  - use struct only for PODs that only carries data holding logic
  - composition(is-kind-of) over inheritance(is-a). Do not use private inheritance
  - multiple inheritance only for Interfaces
  - define overloaded operators only if their meaning is obvious
  - declaration order: using, typedefs, static constants, fields, static fields, ctors, dctors, methods
  - input arguments = const references or values, output = pointers
  - default arguments are allowed on non-virtual functions
  - casting - static_cast or brace {} init for conversion

