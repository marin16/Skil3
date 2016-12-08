#VLN1 Hópur 10:
* Daði Sigursveinn Harðarson
* Garðar Sigurðsson
* Ívar Sveinn Loftsson
* Marín Viðarsdóttir
* Stefán Már Melstað

Github tengill:  
https://github.com/dadisigursveinn/Skil2

##C++ coding conventions
###Namings
* PascalCase
  * Classes
* camelCase
  * Parameter
  * Properties
  * Enum types
  * Enum values
  * Namespaces
  * Public class properties
  * Public class functions
* lowercase
  * File names
* \_camelCase that begins with underscore
  * Private class properties
  * Private class functions
####Demonstrative Na:mes
We will use descriptive names in our code so instead of writing something like:
```C++
a = b ∗ c ;
```
we will write something like:
```C++
weekly_pay = hours_worked ∗ pay_rate ;
```
which describes way better what we are doing and eliminates the need put in explanative
comments.

##SQL coding conventions
###Namings
* lowercase
  * all sql keywords
* PascalCase
  * Table names
* camelCase
  * table variables
* views
  * views are named like Tables but should end with `_view`
