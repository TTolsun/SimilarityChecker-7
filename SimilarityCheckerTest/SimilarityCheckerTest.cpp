#include "pch.h"
#include "../SimilarityCheckerSource/SimilarityChecker.cpp"

TEST(LengthCheck, LengthCheck) {
	EXPECT_EQ(SimilarityChecker::checkLength("ASD", "DSA"), 60);
	EXPECT_EQ(SimilarityChecker::checkLength("A", "BB"), 0);
	EXPECT_EQ(SimilarityChecker::checkLength("AAABB", "BAA"), 19);
	EXPECT_EQ(SimilarityChecker::checkLength("AA", "AAA"), 30);
}

TEST(LengthCheck, SameAlphaCheck)
{
	EXPECT_EQ(SimilarityChecker::checkSameAlpha("ASD", "DSA"), 40);
	EXPECT_EQ(SimilarityChecker::checkSameAlpha("A", "BB"), 0);
	EXPECT_EQ(SimilarityChecker::checkSameAlpha("AAABB", "BAA"), 40);
	EXPECT_EQ(SimilarityChecker::checkSameAlpha("AA", "AAE"), 20);
}
