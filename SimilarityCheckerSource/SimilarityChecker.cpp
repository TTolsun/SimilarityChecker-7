#include <string>

class SimilarityChecker
{
public:
	static int checkLength(const std::string& str1, const std::string& str2)
	{
		std::string longStr{}, shortStr{};
		compareStringLength(str1, str2, longStr, shortStr);
		return calculateScore(longStr, shortStr);
	}

private:
	static void compareStringLength(const std::string& str1, const std::string& str2, std::string& longStr,
	                                std::string& shortStr)
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

	static int calculateScore(const std::string& longStr, const std::string& shortStr)
	{
		const auto gapValue = longStr.length() - shortStr.length();
		const auto divideValue = static_cast<float>(gapValue) / static_cast<float>(shortStr.length());
		return static_cast<int>((1.0f - divideValue) * 60.0f);
	}
};
