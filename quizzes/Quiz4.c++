/*
NI: Quiz #4
*/

/* -----------------------------------------------------------------------
 1. Taken independently, which of the following lines does compile and
    which of the following lines does not compile?
*/

int main () {
          int i  = 2;
    const int ci = 2;

    const int*  p  = &i;
    int*  const pc = &ci;
    const int&  r  = i;

    return 0;}
