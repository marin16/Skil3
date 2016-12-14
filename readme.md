#VLN1 Skil3 Hópur 10:
* Daði Sigursveinn Harðarson
* Garðar Sigurðsson
* Ívar Sveinn Loftsson
* Marín Viðarsdóttir
* Stefán Már Melstað

Github tengilar:  
[Skil 1](https://github.com/SoYman/skil1)
[Skil 2](https://github.com/dadisigursveinn/skil2)
[Skil 3](https://github.com/marin16/skil3)

#Database
The databese is hosted on a [Digital Ocean](https://www.digitalocean.com/) server. We use [PostgreSQL](https://www.postgresql.org/) wich means that your computer has to have [PostgreSQL](https://www.postgresql.org/) installed on your computer and make sure that Qt has the path to `bin` and `lib`.
1.  Install PostgreSQL
2.  Add the path to `bin` and `lib` under `Build Enviroment` in Qt

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

####Demonstrative Names
We will use descriptive names in our code so instead of writing something like:
```C++
a = b ∗ c ;
```
we will write something like:
```C++
weeklyPay = hoursWorked ∗ payRate ;
```
which describes way better what we are doing and eliminates the need put in explanative
comments.

###Commenting
We use comments to descripe functions in `.h` files, by writing the title of the function followed by a short description of the functon, parameters and description of what they are used for and return value, in a comment block above the function.  
```C++
/*
 * weeklyPay: used to calculate weekly pay.
 * params: int hours (hours worked), int rate (hourly pay).
 * returns: int weekly pay (hours * rate).
 */
int weeklyPay(int hours, int rate)
{
	return hours * rate;
}
```
We comment our code when it does not explain itself well enaugh and we feel like more information is needed. When commenting we usualy add `// Inline comments.` that explain our code, but if we need to write long texts we write them in `/* Code blocks. */`. Code blocks can also be used when we are commenting insame line as code, but we try to avoid doing that. 

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
* triggers
 * triggers are named like Tables but should end with `_trigger`
* Many\_to\_Many table
 * Connecting tables should be named `Table1` name followed by \_has\_`Table2` 
