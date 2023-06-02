#include <string>

using namespace std;

class SimilarityChecker
{
public:
	static int checkLength(const string& str1, const string& str2)
	{
		string longStr{}, shortStr{};
		compareStringLength(str1, str2, longStr, shortStr);
		return calculateScore(longStr, shortStr);
	}

private:
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

	static int calculateScore(const string& longStr, const string& shortStr)
	{
		const auto gapValue = longStr.length() - shortStr.length();
		const auto divideValue = static_cast<float>(gapValue) / static_cast<float>(shortStr.length());
		return static_cast<int>((1.0f - divideValue) * 60.0f);
	}
};
