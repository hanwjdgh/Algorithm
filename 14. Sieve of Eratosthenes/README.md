# Sieve of Eratosthenes

- Pseudocode
```bash
void Eratos(int n){
	bool* PrimeArray;

	if(n<=1) 
    return;

	PrimeArray=new bool[n+1];
	
	for(int i=2; i<=n; i++) 
    PrimeArray[i]=true;
	
	for(int i=2; (i*i)<=n; i++){
		if(PrimeArray[i]){
			for(int j=i*i; j<=n; j+=i) 
            PrimeArray[j]=false;
		}
	}
}
```
- Time Complexity : N<sup>2</sup>