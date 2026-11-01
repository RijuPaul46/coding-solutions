class Solution {
public:
    #define ll long long
    ll MAX=1e9;
    ll max=(ll)sqrt(MAX);
    //1 cannot be there ... consec not allowed atleast +2
    // 2-4-6
    // x if x is even then +2 work if x is prime then next elm 2*x 
    // if isprime return -1
    // spf + while inc -spf while decreasing
    // let say spf=3  then x is odd 3*(x)==n then 3*(x-1)==n-3  x-1 must be even
    // ll spf[MAX];
    // bool isPrime(ll n){
    //     for(int i=2;i*i<=n;i++){
    //         if((n%i)==0) return 0;
    //     }
    //     return 1;
    // }
    vector<int>primes;
    vector<int>isPrime;
    void preCompute(){
        isPrime[0]=isPrime[1]=0;
        for(int i=2;i<=max;i++){
            if(isPrime[i]){
                primes.push_back(i);
                for(int j=i+i;j<=max;j+=i){
                    isPrime[j]=0;
                }
            }
        }
    }
    ll spf(ll n){
        
        if(n<=2)return n;
        for(auto &prm:primes){
            if(prm==n)return 1;
            if(prm*prm>n)return 1;
            if((n%prm) ==0)return prm;
        }
        return 1;
    }
    long long minimumMaxValue(int n, int index, int value) {
        if(value==1)return -1;
        isPrime.resize(max+1,1);
        preCompute();
        ll sp=spf(1ll*value);
        // cout<<sp<<endl;
        if(index!=0){
        if(sp==1)return -1;
        ll prev=(value-sp)/2;
            
        if(prev< index)return -1;
        }
        ll add=sp;
        if(sp==1)add=value;
        ll rem=n-index-1;
        return (ll)(value+add+2ll*(rem-1));
    }
};