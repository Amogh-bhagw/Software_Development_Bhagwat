### Assessment for Lab 06

#### Total score: _50_ / _100_

Run on February 18, 13:18:58 PM.


#### System Files and Directory Structure

+ Pass: Check that directory "labs" exists.

+ Pass: Check that directory "labs/lab06_gdb" exists.

+ Pass: Change into directory "labs/lab06_gdb".

+  _10_ / _10_ : Pass: Replace doInterestingThing(1999); with doInterestingThing(1999);doInterestingThing(2018); in main.cc.




#### Test that code compiles and creates the exectuable

+  _30_ / _30_ : Pass: Check that make compiles.



+  _10_ / _10_ : Pass: Check that file "date" exists.


#### Test Output Execution

+  _0_ / _10_ : Fail: Program executes flawlessly.

<pre> ... A set of Dates ... 
default date is: January 1, 1900
date d2 is: April 19, 1998
date d3 is: April 19, 1998
 ... Now print out 4 dates in reverse time order ... 
date is: January 1, 1993
date is: January 1, 1992
date is: January 1, 1991
date is: January 1, 1990
the first date is: January 2, 1990
 ... A set of Dates ... 
default date is: January 1, 1900
date d2 is: April 19, 1999
date d3 is: April 19, 1999
 ... Now print out 4 dates in reverse time order ... 
date is: January 1, 1993
</pre>



+  _0_ / _5_ : Fail: Check for correct output.

    Files are not equal.
diff: date.output: No such file or directory




+ Pass: Replace i <= with i < in main.cc.



+ Pass: Check that make compiles.



+  _0_ / _20_ : Fail: Most of the program works.

<pre> ... A set of Dates ... 
default date is: January 1, 1900
date d2 is: April 19, 1998
date d3 is: April 19, 1998
 ... Now print out 4 dates in reverse time order ... 
date is: January 1, 1993
date is: January 1, 1992
date is: January 1, 1991
date is: January 1, 1990
the first date is: January 2, 1990
 ... A set of Dates ... 
default date is: January 1, 1900
date d2 is: April 19, 1999
date d3 is: April 19, 1999
 ... Now print out 4 dates in reverse time order ... 
date is: January 1, 1993
</pre>



+  _0_ / _15_ : Fail: Check for correct output.

    Files are not equal.
diff: date.output: No such file or directory




#### Total score: _50_ / _100_

