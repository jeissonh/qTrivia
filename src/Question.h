#ifndef QUESTION_H
#define QUESTION_H

#include <istream>
#include <limits>
#include <string>

class Question
{
  protected:
	std::string text;
	std::string answer;

  public:
	Question();
	virtual ~Question() { }

	friend std::istream& operator>>(std::istream& in, Question& question)
	{
		return question.read(in, true);
	}

	virtual std::istream& read(std::istream& in, bool skipEmptyLine)
	{
		std::getline(in, this->text);
		std::getline(in, this->answer);

		if ( skipEmptyLine )
			in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::string dummy;
		//std::getline(in, dummy);
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Question& question)
	{
		return out << '{' << question.text << "}[" << question.answer << ']';
	}

	virtual void print(std::ostream& out) const;

	bool ask();
	virtual bool isRightAnswer(const std::string& playerAnswer) const = 0;
};

#endif // QUESTION_H
