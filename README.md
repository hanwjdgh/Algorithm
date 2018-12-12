# Algorithm

## cpp format

```bash
#include <iostream>
#include <ios>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    return 0;
}
```

## Time Complexity

### 1. What is time complexity

    - Time from input to output
    - Frequency of calling command

### 2. Description of the times

    - Θ(1) : Regular execution time regardless of the number of input data
    - Θ(logn) : Depending on the number of input data, the time gradually increases with time
    - Θ(n) : It takes a linear execution time depending on the number of input data
    - Θ(nlogn) : Splitting a big problem into a problem of a certain size and collecting it again
    - Θ(n^2) : When processing input data within a dual loop
    - Θ(n^3) : When processing input data within a triple loop

    Θ(logn) > Θ(n) > Θ(nlogn) > Θ(n^2) > Θ(n^3) > Θ(2^n) > Θ(n!)