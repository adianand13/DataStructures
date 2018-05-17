Array
=========

<p align="justify">Array is an derived data type. It is derived by the combination of primary/secondary data types arranged in the sequential contiguous memory allocation. This sequential contiguous memory allocation helps by indexing every data in memory.</p>

<p align="justify">Since all the elements belongs to one particular data type, the computer keeps record of only first memory-cell and then rest others are fetched by their index value. This is also one major reason why almost all the programming language begin their array by 0 or 1.</p>

Formula For finding value at i-th positing 

For zero-biased indexing
<p align="justify">Base_address + (position*( sizeOf (data_type) ))</p>

For one-biased indexing (Algol 68, Matlab, Pascal, Fortran, Cobol, smalltalk, FoxPro)
<p align="center">Base_address + (position-1*( sizeOf (data_type) ))</p>

<p align="justify">Though these things are implicitly done in background by the compiler of the programing language, but this might come in handy if someone wants access values with the help of pointer.
By doing so, the programmer only needs to keep track of the address of the first unit of the memory cell in the array, while the rest can be calculated and fetched.</p>

Memory Representation of Multiple dimensional array
---------------

<p align="justify">Thermotical array can be of multiple dimensions, but these array in computer memory are arranged in the sequential manner. They are either arranged in row major or column major style.</p>

<p align="center">
  <img src="https://craftofcoding.files.wordpress.com/2017/02/rowcolumnarrays.jpg" width="650"/>
</p>

*Source-* _https://craftofcoding.wordpress.com/2017/02/03/column-major-vs-row-major-arrays-does-it-matter/_

###Row Major
 <p align="justify">In row major, the priority is given to row. That is, the values are stored in the order of their row. First row first then second row and so one.</p>

Formula For finding value at i-th row and j-th column in row major.
LOC[ i , j ] = Base_address + ( ( M*i + j ) * ( sizeOf (data_type) ))

###Column Major
<p align="justify">In column major, priority is given to the column first. That is, the values in the first column are stored first then in second column and so on.</p>

Formula For finding value at i-th row and j-th column in row major.
LOC[ i , j ] = Base_address + ( ( i + N*j ) * ( sizeOf (data_type) ))

<p align="center"><b><i>Where M and N are the size of the rows and column</b></i></p>


Limitations Of array
------------------------

<p align="justify">Although array can be very handy when it comes about maintaining the record of the values but it has its own limitation.</p>

<p align="justify">Since array is a contiguous memory allocation, once the size of the array is declared, the size cannot be changed. Furthermore, fixed size makes it impossible to add data in the middle of the array by pushing two value on either sides.</p>

<p align="justify">Array can store values belonging to only one data-type. This makes is useless when data needed to be stored can be of random type or multiple kinds.</p>
