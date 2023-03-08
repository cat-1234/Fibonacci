template <int N, typename T>
class Fib : public Fib<N - 1, T> {
public:
    T prevValue;
    T value;
    constexpr Fib()
        : prevValue(static_cast<Fib<N - 1, T>*>(this)->value),
          value(static_cast<Fib<N - 1, T>*>(this)->prevValue + prevValue)
    {}
};

template <typename T>
class Fib<0, T> {
public:
    T value;
    constexpr Fib() : value(1) {}
};

template <typename T>
class Fib<1, T> {
public:
    T prevValue;
    T value;
    constexpr Fib() : prevValue(1), value(1) {}
};

template <int N, typename T>
constexpr T FibV = Fib<N, T>().value;

int main() {
  static_assert(FibV<0, int> == 1);
  static_assert(FibV<1, int> == 1);
  static_assert(FibV<2, int> == 2);
  static_assert(FibV<3, int> == 3);
  static_assert(FibV<4, int> == 5);
  static_assert(FibV<5, int> == 8);
  static_assert(FibV<6, int> == 13);
  static_assert(FibV<7, int> == 21);
  return EXIT_SUCCESS;
}
