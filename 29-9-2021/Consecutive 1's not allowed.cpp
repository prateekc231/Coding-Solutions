ll countStrings(int n) {
	    ll a[n], b[n];
	    ll mod = 1000000007;
	    a[0]=b[0]=1;
	    for(int i=1;i<n;i++){
	        a[i] = (a[i-1]%mod + b[i-1]%mod)%mod;
	        b[i] = a[i-1]%mod;
	    }
	    return (a[n-1]+b[n-1])%mod;
	}
