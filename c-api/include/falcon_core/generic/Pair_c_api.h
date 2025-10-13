#ifdef __cplusplus
extern "C" {
#endif

// Define all the type pairs you need
#define PAIR_TYPES            \
  X(int, int, IntInt)         \
  X(float, float, FloatFloat) \
  X(int, float, IntFloat)     \
  /* Add more as needed */

// Generate typedefs
#define X(T1, T2, NAME) typedef void* Pair##NAME##Handle;
PAIR_TYPES
#undef X

// Generate function declarations
#define X(T1, T2, NAME)                                                \
  Pair##NAME##Handle Pair##NAME##_create(T1 first, T2 second);         \
  void               Pair##NAME##_destroy(Pair##NAME##Handle handle);  \
  T1                 Pair##NAME##_first(Pair##NAME##Handle handle);    \
  T2                 Pair##NAME##_second(Pair##NAME##Handle handle);   \
  bool Pair##NAME##_equal(Pair##NAME##Handle a, Pair##NAME##Handle b); \
  bool Pair##NAME##_not_equal(Pair##NAME##Handle a, Pair##NAME##Handle b);
PAIR_TYPES
#undef X

#ifdef __cplusplus
}
#endif
