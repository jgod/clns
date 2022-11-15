# clns

Collection utility methods (header-only)

## requirements

C++11 compiler

## usage

```cpp
#include "clns.h"
using namespace jgod;

clns::includes({"a", "b", "c"}, "b") == true
clns::includes({1, 2, 3}, 3) == true // sorts first
clns::compact({"", "", "thing", ""}) == {"thing"}
clns::compact({0, 1, 0, 2}) == {1, 2}

// these sort first
clns::getUnion({2, 4}, {1, 3}) == {1, 2, 3, 4}
clns::getUnion({"a", "c"}, {"b", "d"}) == {"a", "b", "c", "d"}
clns::getIntersection({1, 2, 3}, {3, 4, 5}) == {3}
clns::getIntersection({"a", "b", "c"}, {"c", "d", "e"}) == {"c"}
clns::getDifferences({1, 2, 3}, {3, 4, 5}) == {1, 2, 4, 5, 6}
clns::getDifferences({"a", "b", "c"}, {"c", "d", "e"}) == {"a", "b", "d", "e"}
```

## license

Copyright Justin Godesky.
Released under the AGPLv3 License.
