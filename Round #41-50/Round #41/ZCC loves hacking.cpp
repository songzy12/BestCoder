#include <iostream>  
#include <cstring>  
#include <cstdio>  
#include <algorithm>  
#define MAX 100007  
#define MOD 998244353  
// https://en.wikipedia.org/wiki/Pentagonal_number_theorem
using namespace std;  
  
int five ( int x )  
{  
    return x*(3*x-1)/2;  
}  
  
int dp[MAX];  
int q[MAX];  
int sum[MAX];  
  
void init ( )  
{  
    dp[0] = 1;  
    for ( int i = 1 ; i < MAX ; i++ )  
    {  
        for ( int j = 1 ; ; j++ )  
        {  
            int k = five(j);  
            if ( k > i ) break;  
            if ( j&1 ) dp[i] = dp[i] + dp[i-k];  
            else dp[i] = dp[i] - dp[i-k];  
            dp[i] %= MOD;  
            k = five(-1*j);  
            if ( k > i ) break;  
            if ( j&1 ) dp[i] = dp[i] + dp[i-k];  
            else dp[i] = dp[i] - dp[i-k];  
            dp[i] %= MOD;  
        }  
        dp[i] = (dp[i]%MOD+MOD)%MOD;  
    }  
    /*for ( int i = 1 ; i < 10 ; i++ ) 
        printf ( "%d " , dp[i] ); 
    puts("");*/  
    q[0] = dp[0];  
    for ( int i = 1 ; i < MAX ; i++ )  
    {  
        q[i] = dp[i];  
        for ( int j = 1 ; ; j++ )  
        {  
            int k = five(j)*2;  
            if ( k > i ) break;  
            if ( j&1 ) q[i] -= dp[i-k];  
            else q[i] += dp[i-k];  
            q[i] %= MOD;  
            k = five(-1*j)*2;  
            if ( k > i ) break;  
            if ( j&1 ) q[i] -= dp[i-k];  
            else q[i] += dp[i-k];  
            q[i] %= MOD;  
        }  
        q[i] = (q[i]%MOD+MOD)%MOD;  
    }  
    /*for ( int i = 0 ; i < 10 ; i++ ) 
        printf ( "%d " , q[i] ); 
    puts ("");*/  
    sum[0] = q[0];  
    for ( int i = 1 ; i < MAX ; i++ )  
        sum[i] = (sum[i-1] + q[i])%MOD;  
}  
  
int t,n,c,l,r;  
// sum[i]: number of ways to decompose i into sum of different integers
int main ( )  
{  
    init();  
    scanf ( "%d" , &t );  
    while ( t-- )  
    {  
        scanf ( "%d%d%d%d" , &n , &c , &l , &r );  
        l -= c;  
        r -= c;  
        n--;  
        if ( l == 0 ) printf ( "%d\n" , sum[r] );  
        else printf ( "%d\n" , ((sum[r] - sum[l-1])%MOD+MOD)%MOD );  
    }  
  
} 