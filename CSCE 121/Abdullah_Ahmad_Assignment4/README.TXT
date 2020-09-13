Abdullah Ahmad
927009064
Sec: 532
Abdullah2808
Abdullah2808@tamu.edu

I certify that I have listed all the sources that I used to develop the solutions/code to
the submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help on this academic work.
Abdullah Ahmad 10/1/19

Drill 2:
swap_v doesn't change any of the values becaues it doesn't dereference it just changes the temporary copies
swap_r dereferences and changes the values, but it does not work with doubles because you are working with the initial variables not a copy
swap_cr doesn't run because you can't change the value of constant values
I commented out all the code that causes errors

Part 3 Fibonacci Sequence
In the integar data type 45 terms are printed and last term is 1836311903
In the long and long long data type 91 terms are printed and the last term is 7540113804746346429
Doing some google searching long is always at least 32 bits while long long is at least 64 bits and i'm assuming since i'm running a 64 bit operating system they would both be 64 bits
Converting 7540113804746346429 to binary you get 110100010100011110111011000111001100001111011001100111110111101 which is 64 bits so my assumption that long is also 64 bits is correct in this case
conversion website used : https://www.rapidtables.com/convert/number/binary-to-hex.html
research about long vs long long: https://stackoverflow.com/questions/6462439/whats-the-difference-between-long-long-and-long

Part 4 Octal recursive function
This part seemed hard to me initially because recursive functions just don't process right in my head, but after thinking about how I convert decimal to binary and applying those
same principles this was a piece of cake
Converting from decimal to octal:  https://www.wikihow.com/Convert-from-Decimal-to-Octal

Part 5 Vector
Function 1 I wrote in a way that it would be easy to turn into a recursive function. For the second function I basically thought of it like a for loop that would run a certain amount of times
and would swap element 0 with the last element then the element 1 with the last element - 1. Which is similar to how the first function runs
