Q: Is this legal ?


    int add( int a, int b ) { return a+b; }

    int add( int a, int b, int c=0 ) { return a+b+c; }

A: No, because calling:

    int A = add (1, 2);

Would be "ambiguous". Compiler doesn't know which function to call because the second function has a default value to the third parameter and thus it is possible to call it just like you would call the first function.