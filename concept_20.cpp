#include <iostream>
#include <vector>
#include <type_traits>
#include <concepts>
#include <numeric>

// https://www.cppstories.com/2016/02/notes-on-c-sfinae/
using namespace std;

template <typename T>
concept numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

template <typename T>
requires numeric<T>
constexpr double Sum(std::vector<T> const &vec)
{
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum;
    // return sum / static_cast<double>(vec.size());
}

template <typename T>
requires numeric<T>
constexpr double Average2(std::vector<T> const &vec)
{
    const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    return sum / static_cast<double>(vec.size());
}
// User defined function
int myfun(int x, int y)
{
    // for this example we have taken product
    // of adjacent numbers
    return x * y;
}

int main()
{
    std::vector ints{1, 2, 3, 4, 5};
    // std::cout << Average2(ints) << '\n';
    int sum = 0;
    int a[] = {5, 10, 15};

    // Simple default accumulate function
    cout << "\nResult using accumulate: ";
    cout << accumulate(a, a + 3, sum) << endl;

    cout << accumulate(a, a + 3, sum, std::minus<int>()) << endl;

    return 0;
}
