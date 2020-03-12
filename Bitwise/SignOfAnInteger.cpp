//eg 10 stored as 0000 1010
//-10 is stored as 1 111 0110 sit bit + 2's complement of 000 1010
//In right shift all bits from left start filling with sign bit
// 1 111 0110 becomes 1111 1111 
// A negative number converted back to 2's complement form 1 000 0001
//Hence -1 whenever a number is negative

// During bit manipulations sign bit is used as normal bit and all operations occur on it
//if sign bit is 1 negative number, interpret as 2's complement

//In right shift all bits from left start filling with sign bit

//https://medium.com/@shashankmohabia/bitwise-operators-facts-and-hacks-903ca516f28c
//https://www.hackerearth.com/practice/notes/bit-manipulation/
#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	if(n>>31==-1){
		cout<<"Negative";
	}
	else{
		if(-n>>31==-1)
			cout<<"Positive";
		else
			cout<<"Zero";
	}
	return 0;
}
