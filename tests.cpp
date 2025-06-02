#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "main.cpp"

TEST_CASE("Point: Structure definition and initialization") {
    SECTION("Size checks") {
        Point p;
        REQUIRE(sizeof(p.x) == sizeof(double));
        REQUIRE(sizeof(p.y) == sizeof(double));
    }
     SECTION("Direct initialization") {
        Point p = {3.7, 2.8};
        REQUIRE(p.x == Approx(3.7));
        REQUIRE(p.y == Approx(2.8));
    }
}

TEST_CASE("Reflect: Reflect over X-axis") {
    Point P = {3.0, 4.0};
    Point reflected = reflect(P, 'x');
    REQUIRE(reflected.x == Approx(3.0));
    REQUIRE(reflected.y == Approx(-4.0));
}
TEST_CASE("Reflect: Reflect over Y-axis") {
    Point P = {3.0, 4.0};
    Point reflected = reflect(P, 'y');
    REQUIRE(reflected.x == Approx(-3.0));
    REQUIRE(reflected.y == Approx(4.0));
}
TEST_CASE("Reflect: Reflect negative coordinates") {
    Point P = {-2.5, -1.5};
    Point reflectedX = reflect(P, 'x');
    REQUIRE(reflectedX.x == Approx(-2.5));
    REQUIRE(reflectedX.y == Approx(1.5));

    Point reflectedY = reflect(P, 'y');
    REQUIRE(reflectedY.x == Approx(2.5));
    REQUIRE(reflectedY.y == Approx(-1.5));
}
