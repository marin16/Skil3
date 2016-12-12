#VLN1 Skil3 Hópur 10:
* Daði Sigursveinn Harðarson
* Garðar Sigurðsson
* Ívar Sveinn Loftsson
* Marín Viðarsdóttir
* Stefán Már Melstað

Github tengill:  
https://github.com/dadisigursveinn/Skil2

#Database
The database is locaded in the build directory and is named `csdb`, the database is automaticaly generated when you don't have a database already.  
We provide a sample database that you can move to the build directory and a `insert.sql` file that you can run on the database to get the sample data.
```shell
sqlite3 csdb
sqlite> .read insert.sql
sqlite>
```

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
