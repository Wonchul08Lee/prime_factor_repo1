#include "gmock/gmock.h"
#include "primefactor.cpp"
using namespace std;

TEST_F(PrimeFixture, Of1) {
	expected = {};
	EXPECT_EQ(expected, prime_factor.of(1));
}
