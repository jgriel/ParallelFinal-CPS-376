# ParallelFinal

Our own NumPy library using parallelism for the final project of CPS 376.

To compile worseNumPy.cpp use the following command: 
```
c++ -O3 -Wall -shared -std=c++11 -fopenmp -fPIC $(python3 -m pybind11 --includes) WorseNumPy.cpp -o WorseNumPy$(python3-config --extension-suffix)
```

matriTiming.py and arrayTiming.py demonstrate the runtime of each method with different cores as well as the runtime of NumPy performing the same operations.
worseNumPyDemonstration.py demonstrates how this library can be used.
