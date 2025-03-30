// This template is to find ncr and npr in O(1) time after doing precomputation which will take O(n) time. Another thing is we are taking mod everytime because of the answer constraints.


class Factorial{
    vector<int>fac;
    int mod;
public:
    Factorial(int n, int m)
    {
        mod = m;
        fac.resize(n+1);
        fac[0] = 1;
        for(int i = 1; i <= n; i++)
            fac[i] = ((i%mod)*(fac[i-1]%mod))%mod;
    }

    int binpow(int a, int b)
    {
        if(b == 0)
            return 1;
        int res = binpow(a,b/2);
        if(b&1)
            return (((a*res)%mod)*(res))%mod;
        else
            return (res*res)%mod;
    }

    int inverse(int den)
    {
        return binpow(den,mod-2)%mod;
    }
    int ncr(int n, int r)
    {
        int nom = fac[n];
        int den = (fac[n-r]*fac[r])%mod;
        int denI = inverse(den);
        return (nom*denI)%mod;
    }
    int npr(int n, int r)
    {
        int nom = fac[n];
        int den = fac[n-r];
        int denI = inverse(den);
        return (nom*denI)%mod;
    }
};
