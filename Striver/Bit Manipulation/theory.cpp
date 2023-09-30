// Theory:

// 6 operators : (& | ~ ^ >> <<) 

// XOR Operator : if there are even number of 1s, gives 0
//                if there are odd number of 1s, gives 1

// a XOR a = 0

// >> x will remove the last x bits  (>> => Right Shift)
// Right shift of a number by x = division of number by 2 raised to power x
// Right shift never causes overflow

// Left shift of a number by x = multiplication of number by 2 raised to power x
// Left shift beyond a limit(for a given number) can cause overflow and yield negative values


// XOR Applications 
// Swapping of two numbers using XOR 


//XOR of all numbers from 1 to N is :
    // 0 if N = 4*x+3
    // 1 if N = 4*x+1
    // N if N = 4*x
    // N+1 if N = 4*x+2

// Given a range L to R, the XOR is getXor(l-1)^getXor(r) where getXor(i) is the xor of first i numbers

// Applications of AND operator
// To check if a number is odd or not, see if its 1st bit is set (number & 1 !=0 )

// To check if the ith bit of a number N is set or not 
    // use (N>>i & 1) OR
    // Create a mask with all bits set to 0 and ith bit set to 1 and take (mask&N !=0)mask is nothing but 1<<i 

// To Extract the ith bit of a number N, do ((N & 1<<i)>>i)


// Applications of OR Operator
// To set the ith bit of a number N do (N | 1<<i)

// To clear the ith bit of a number N do (N & ~(1<<i))

// To remove the last set bit of a number N from the right see code 
//(Learning from above questions : Think in terms of 
    //bits ki kaisa binary number create kar de(Using Bit Masking) and kaun sa operator use kare ki answer aa jaaye
    //in terms of numbers ki kis number ke saath karna par answer aa jayega)

// To check if a number is a power of 2 do (N & N-1 ==0)
// To count the number of set bits in a number, see code 

// if no carry invoved(i.e 1 is not present at the same position in both the numbers) a+b=a|b
// else a+b = a|b + a&b 