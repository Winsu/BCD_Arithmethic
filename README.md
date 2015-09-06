# BCD_Arithmethic

This repository shows different operations with differents type of numbers to operate in BCD. It contains DigBCD and  ParBCD(a pair).
I'm currently working on creating a generic base to work with BCD numbers with any amount of digits.

#How to run it

It will run if the compiler is set to work with -std=c++11

#How to play with

On the main file the programme contains different examples that use DigBCD and ParBCD. You can compile one example or more, it's your choice. Before you do, you'll have to consider the type that the example is using and you'll have to declare a variable with a specific type according to the example that you use. You'll have to initialize the variable too.

To initialize a variable you'll have to use an integer from this enum:

enum DigBCD {c=uci(0),u=uci(1),d=uci(2),t=uci(3),q=uci(4),z=uci(5),x=uci(6),s=uci(7),o=uci(8),n=uci(9),E=uci(255)};



