# ParallelFinal
<p>Our own NumPy library using parallelism for the final project of CPS 376.</p>

To compile worseNumPy.cpp use the following command: c++ -O3 -Wall -shared -std=c++11 -fopenmp -fPIC $(python3 -m pybind11 --includes) WorseNumPy.cpp -o WorseNumPy$(python3-config --extension-suffix)

matrixSpeedTest.py and arraySpeedTest.py demonstrate the runtime of each method with different cores.
worseNumPyDemonstration.py demonstrates how this library can be used.
