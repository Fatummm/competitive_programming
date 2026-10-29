#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int MAGIC = chrono::steady_clock::now().time_since_epoch().count();

struct custom_hash {
  size_t operator()(int x) const {
    return x ^ MAGIC;
  }
};

// substitute for unordered_map
// uses much more memory, but works faster
template <class K, class V>
using fast_map = gp_hash_table<
  K
  , V
  , custom_hash
  , equal_to<K>
  , direct_mask_range_hashing<>
  , linear_probe_fn<>
  , hash_standard_resize_policy<
    hash_exponential_size_policy<>
    , hash_load_check_resize_trigger<>
    , true>
>;

// substitute for unordered_set
// uses much more memory, but works faster
template <class T>
using fast_set = gp_hash_table<
  T
  , null_type
  , custom_hash
  , equal_to<T>
  , direct_mask_range_hashing<>
  , linear_probe_fn<>
  , hash_standard_resize_policy<
    hash_exponential_size_policy<>
    , hash_load_check_resize_trigger<>
    , true
  >
>;