#include <chrono>
template <typename D = std::chrono::microseconds>
class Benchmark {
public:
    Benchmark() {
        start = std::chrono::high_resolution_clock::now();
    }
    typename D::rep elapsed() const
    {
        auto end = std::chrono::high_resolution_clock::now();
        auto result = std::chrono::duration_cast<D>(end - start);
        return result.count();
    }
private:
    std::chrono::high_resolution_clock::time_point start;
};
