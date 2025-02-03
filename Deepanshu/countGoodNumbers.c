#include<stdio.h>


long long power(long long x, long long n,long long mod) {
    
    
    if(n == 0){
        return 1;
    }
    long long temp = power(x,n/2,mod);
    
    if(n%2 ==0){
        return (temp*temp)%mod;
    }else{
        return (x*temp*temp)%mod;
    }
    
}

int main(){
    long long  number;
    scanf("%lld",&number);
    
    long long mod = 1000000007;
    long long e = (number+1)/2;
    long long o = number/2;
    
    long long ans = (power(5,e,mod)*power(4,o,mod))%mod;
    
    printf("%lld",ans);
    
    
    return 0;
}