#include "pch.h"
#include "../SimilarityCheckerSource/SimilarityChecker.cpp"

TEST(LengthCheck, SameCharCheck)
{
	EXPECT_EQ(SimilarityChecker::checkSameChar("ASD", "DSA"), 40);
	EXPECT_EQ(SimilarityChecker::checkSameChar("A", "BB"), 0);
	EXPECT_EQ(SimilarityChecker::checkSameChar("AAABB", "BAA"), 40);
	EXPECT_EQ(SimilarityChecker::checkSameChar("AA", "AAE"), 20);
}
