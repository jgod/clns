//
//  main.cpp
//  clns
//
//  Created by Justin Godesky on 11/14/15.
//
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../clns.h"
using namespace jgod;

TEST_CASE("searching") {
  SECTION("strings") {
    SECTION("includes") {
      SECTION("value") {
        const auto C = std::vector<std::string>{"a", "b", "c"};
        REQUIRE(clns::includes(C, "b"));
      }

      SECTION("another collection") {
        auto a = std::vector<std::string>{"a", "b", "c"};
        auto b = std::vector<std::string>{"a", "b"};
        REQUIRE(clns::includes(a, b));
      }
    }
  }

  SECTION("numbers") {
    SECTION("includes") {
      SECTION("value") {
        const auto C = std::vector<int>{1, 2, 3};
        REQUIRE(clns::includes(C, 2));
      }

      SECTION("another collection") {
        auto a = std::vector<int>{1, 2, 3};
        auto b = std::vector<int>{1, 2};
        REQUIRE(clns::includes(a, b));
      }
    }
  }
}

TEST_CASE("modifying") {
  SECTION("compact") {
    SECTION("string") {
      auto src = std::vector<std::string>{"", "thing", "", ""};
      auto target = std::vector<std::string>{"thing"};
      clns::compact(src);
      REQUIRE(src == target);
    }

    SECTION("numbers") {
      auto src = std::vector<int>{0, 2, 0, 1};
      auto target = std::vector<int>{2, 1};
      clns::compact(src);
      REQUIRE(src == target);
    }
  }
}

TEST_CASE("sets") {

  SECTION("strings") {
    auto a = std::vector<std::string>{"dog", "bird", "cat"};
    auto b = std::vector<std::string>{"apple", "dog", "broom", "car"};

    SECTION("get union") {
      const auto UNIQUE = std::vector<std::string>{"apple", "bird", "broom", "car", "cat", "dog"};
      REQUIRE(clns::getUnion(a, b) == UNIQUE);
    }
    SECTION("get intersection") {
      const auto XION = std::vector<std::string>{"dog"};
      REQUIRE(clns::getIntersection(a, b) == XION);
    }
    SECTION("get difference") {
      const auto DIFF = std::vector<std::string>{"apple", "bird", "broom", "car", "cat"};
      REQUIRE(clns::getDifferences(a, b) == DIFF);
    }
  }

  SECTION("numbers") {
    auto a = std::vector<int>{3, 1, 2};
    auto b = std::vector<int>{5, 1, 6, 4, 3};

    SECTION("get union") {
      const auto UNIQUE = std::vector<int>{1, 2, 3, 4, 5, 6};
      REQUIRE(clns::getUnion(a, b) == UNIQUE);
    }
    SECTION("get intersection") {
      const auto XION = std::vector<int>{1, 3};
      REQUIRE(clns::getIntersection(a, b) == XION);
    }
    SECTION("get difference") {
      const auto DIFF = std::vector<int>{2, 4, 5, 6};
      REQUIRE(clns::getDifferences(a, b) == DIFF);
    }
  }
}
