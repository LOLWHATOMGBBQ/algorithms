#include <stdio.h>
// The following is for windows since mingw doesn't support getchar_unlocked
#ifdef _WIN32
#define getchar_unlocked getchar
#endif


/*
 * This is a file with faster input methods, only applicable to competitive
 * programming. There are a lot of safety things that are used in the standard
 * input functions, for example cin is tied to stdout which indicates that the
 * cout buffer is flushed before each io operation performed on cin
 */


// Scans an int (similar to scanf("%d", ptr))
// Note that this function is not guarunteed to work if the input exceeds
// 2^31 - 1 (does not check for overflow)
void scan_int(int &x)
{
    // Declare variables for input
    char c;
    bool neg = false;

    // Intially set the value of x to 0
    x=0;

    // Check if the first character is a - (negative sign)
    if ((c = getchar_unlocked())== '-')
        neg = true;
    else if (('0'<= c) && (c<='9'))
        x = (x << 3) + (x << 1) + c - '0';
    
    // (x << 3) + (x << 1) + c - '0' is equivalent to
    // x*8 + x*2 + (c - '0') which is equivalent to
    // 10*x + (c - '0')
    for(;('0'<= (c = getchar_unlocked())) && (c<='9'); ) {
	x = (x << 3) + (x << 1) + c - '0';
    }

    if (neg)
        x=~x + 1;
	return;
}


// Scans a string (similar to scanf("%s", ptr))
void scan_string(std::string &str)
{
    str = ""; // initialize empty string
    for(char c; 
	(c = getchar_unlocked()) && (c != -1 && c != '\n' && c != '\r'); 
	str+= c);
}
