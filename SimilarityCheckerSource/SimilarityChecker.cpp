#include <string>
#include <set>

class SimilarityChecker
{
public:
	static int checkSameChar(const std::string& str1, const std::string& str2)
	{
		return calculateScore({str1, str2});
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

	static int calculateScore(const CharSet& charSet)
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
