#include <stdexcept>
#include <string>

using namespace std;

struct Result {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question)
		: question(question) {
	}

	bool isDuplicatedNumber(string guessNumber) {
		return guessNumber[0] == guessNumber[1] ||
			guessNumber[0] == guessNumber[2] ||
			guessNumber[1] == guessNumber[2];
	}

	bool isIncludeChar(const string& guessNumber) {
		for (char ch : guessNumber) {
			if (ch >= '0' && ch <= '9') continue;
			return true;
		}
		return false;
	}

	void assertIllegalArgument(string guessNumber) {
		if (guessNumber == "") {
			throw std::invalid_argument("값을 넣어야함");
		}
		if (guessNumber.length() != 3) {
			throw std::invalid_argument("자리수 오류");
		}
		if (isIncludeChar(guessNumber)) {
			throw std::invalid_argument("숫자로만 구성되어 있지 않음");
		}
		if (isDuplicatedNumber(guessNumber)) {
			throw std::invalid_argument("중복수 금지");
		}
	}

	Result guess(string guessNumber) {
		assertIllegalArgument(guessNumber);

		if (guessNumber == question) {
			return { true, 3, 0 };
		}
	}

private:
	string question;
};
