#include <string>
#include <set>

using namespace std;

class SimilarityChecker
{
public:
	static int checkLength(const string& str1, const string& str2)
	{
		string longStr{}, shortStr{};
		compareStringLength(str1, str2, longStr, shortStr);
		return calculateLengthScore(longStr, shortStr);
	}

	static int checkSameAlpha(const std::string& str1, const std::string& str2)
	{
		return calculateSameAlphaScore({ str1, str2 });
	}

private:
	struct CharSet
	{
		std::set<char> strSet{}, str1Set{}, str2Set{};

		CharSet(const std::string& str1, const std::string& str2)
		{
			for (const auto& ch : str1)
			{
				strSet.insert(ch);
				str1Set.insert(ch);
			}
			for (const auto& ch : str2)
			{
				strSet.insert(ch);
				str2Set.insert(ch);
			}
		}
	};

	static void compareStringLength(const string& str1, const string& str2, string& longStr,
	                                string& shortStr)
	{
		if (str1.length() > str2.length())
		{
			longStr = str1;
			shortStr = str2;
		}
		else
		{
			longStr = str2;
			shortStr = str1;
		}
	}

	static int calculateLengthScore(const string& longStr, const string& shortStr)
	{
		const auto gapValue = longStr.length() - shortStr.length();
		const auto divideValue = static_cast<float>(gapValue) / static_cast<float>(shortStr.length());
		return static_cast<int>((1.0f - divideValue) * 60.0f);
	}

	static int calculateSameAlphaScore(const CharSet& charSet)
	{
		const auto totalCnt = charSet.strSet.size();
		int sameCnt{};
		for (const auto& ch : charSet.str1Set)
		{
			if (charSet.str2Set.count(ch))
				sameCnt++;
		}
		return static_cast<int>((static_cast<float>(sameCnt) / static_cast<float>(totalCnt)) * 40.f);
	}
};
