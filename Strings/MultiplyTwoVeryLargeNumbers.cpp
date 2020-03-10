//Two non-negative numbers represented as strings need to be multiplied
//Both numbers can be bigger than range of long long
//Approach: Multiplication as done on paper
//Digit wise multiplication and then addition
//https://www.interviewbit.com/problems/multiply-strings/

string addTwoStrings(string A, string B){
    int a=A.size();
    int b=B.size();
    int c=0;
    int s=max(a,b);
    s--;
    a--;
    b--;
    string ans=a>b?A:B;
    while(a>=0 && b>=0){
        int temp=A.at(a)+B.at(b)+c-2*'0';
        if(temp>9)
        {
            temp-=10;
            c=1;
        }
        else
        c=0;
        ans[s]=temp+'0';  
		a--;b--;s--;  
    }
    if(a>=0){
        while(a>=0){
            int temp=A.at(a)+c-'0';
            if(temp>9)
            {
                temp-=10;
                c=1;
            }
            else
            c=0;
            ans[s]=temp+'0';
            a--;s--;
        }
    }
    if(b>=0){
        while(b>=0){
            int temp=B.at(b)+c-'0';
            if(temp>9)
            {
                temp-=10;
                c=1;
            }
            else
            c=0;
            ans[s]=temp+'0';
            b--; s--;  
        }
    }
    if(c)
    ans='1'+ans;
    return ans;
}
string multiplyStringAndDigit(string A, int B){
    if(B==0)
    return "0";
    int c=0;
    for(int i=A.size()-1;i>=0;i--){
        int temp=(A.at(i)-'0')*B+c;
        if(temp>9)
        {
            c=temp/10;
            temp=temp%10;
        }
        else
        c=0;
        A[i]=temp+'0';
    }
    if(c){
	    char carry='0'+c;
	    A=carry+A;
	}
    return A;
}
string multiplyTwoStrings(string A, string B) {
    if(A.length()==0 || B.length()==0)
    return 0;
    string prev="";
    string zeros="";
    for(int i=B.size()-1;i>=0;i--){
        string ans=multiplyStringAndDigit(A,B.at(i)-'0');
        prev=addTwoStrings(ans+zeros,prev);
        zeros+='0';
    }
    //removing initial zeros 
    //only case A:0 and B:not zero
    int i=0;
    for(;i<prev.size();i++){
        if(prev.at(i)!='0')
        break;
    }
    prev=prev.substr(i);
    //to prevent empty string in above case
    if(prev.size()==0)
    return "0";
    return prev;
}

