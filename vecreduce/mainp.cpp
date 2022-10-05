#include <iostream>
#include <chrono>

void init_array(int* a, int N, int val)
{
    for (int i = 0; i < N; ++i)
    {
        a[i] = val;
    }
}

int main(int argc, char* argv[])
{
    int N;
    int aval;
    int bval;
    int sum = 0;
    if (argc != 4)
    {
        std::cerr << "usage: " << argv[0] << " <N> <a> <b>" << std::endl;
        return 1;
    }

    N = atoi(argv[1]);
    aval = atoi(argv[2]);
    bval = atoi(argv[3]);

    int* a = new int[N];
    int* b = new int[N];

    init_array(a, N, aval);
    init_array(b, N, bval);

    auto start_time = std::chrono::system_clock::now();

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i)
    {
        sum += a[i] + 2 * b[i];
    }

    auto end_time = std::chrono::system_clock::now();
    std::cout << "sum: " << sum << std::endl;
    std::cout << "execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count()/1000.0 << " seconds" << std::endl;

    return 0;
}
