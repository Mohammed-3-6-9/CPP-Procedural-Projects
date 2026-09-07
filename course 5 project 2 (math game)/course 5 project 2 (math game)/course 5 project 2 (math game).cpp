#include <iostream>
#include <cstdlib>
using namespace std;

enum enQuestionLevel { Easy = 1, Mid = 2, Hard = 3, Mix = 4 };
enum enOperationType { Add = 1, Sub = 2, Mul = 3, Div = 4, mix = 5 };
enum enPassOrFail { Fail, Pass };

struct stHellowQuestions
{
	short NumberOfQuestions;
	enQuestionLevel QuestionLevel;
	enOperationType OperationType;
};

stHellowQuestions HellowQuestions;

void FillstHellowQuestions(short NumOfQuestions, short QLevel, short OpType)
{
	::HellowQuestions.NumberOfQuestions = NumOfQuestions;
	::HellowQuestions.OperationType = (enOperationType)OpType;
	::HellowQuestions.QuestionLevel = (enQuestionLevel)QLevel;
}

void fHellowQuestions()
{
	short NumberOfQuestions, Ql, Op;

	cout << " Please Enter How Many Questions Do You Want To Answer ? ";
	cin >> NumberOfQuestions;

	cout << " Please Enter Question Level : ([1]--> Easy) - ([2]--> Mid) - ([3]--> Hard) - ([4]--> Mix) ? ";
	cin >> Ql;

	cout << " Please Enter Operation Type : ([1]--> Add) - ([2]--> Sub) - ([3]--> Mul) - ([4]--> Div) - ([5]--> Mix) ? ";
	cin >> Op;

	FillstHellowQuestions(NumberOfQuestions, Ql, Op);

}

int RandomNumber(int From, int To)
{
	return (rand() % (To - From + 1) + From);
}

int NumberByLevel(enQuestionLevel NumberLevel)
{
	switch (NumberLevel)
	{
	case enQuestionLevel::Easy:
		return RandomNumber(1, 10);
		break;
	case enQuestionLevel::Mid:
		return RandomNumber(11, 50);
		break;
	case enQuestionLevel::Hard:
		return RandomNumber(51, 100);
		break;
	case enQuestionLevel::Mix:
		return RandomNumber(1, 100);
		break;
	}
}

char OpTypeChar(enOperationType OperationType)
{
	short Number = 0;

	char OpTypeName[4] = { '+','-','*','/' };

	if (OperationType == 5)
	{
		Number = RandomNumber(0, 3);
		return OpTypeName[Number];
	}

	return OpTypeName[OperationType - 1];
}

int CheckAnswer(int Number1 , int Number2, enOperationType OperationType,int UserAnswer)
{
	int CorrectAnswer = 0;

	switch (OperationType)
	{
	case enOperationType::Add:
		CorrectAnswer = Number1 + Number2;
		break;
	case enOperationType::Sub:
		CorrectAnswer = Number1 - Number2;
		break;
	case enOperationType::Mul:
		CorrectAnswer = Number1 * Number2;
		break;
	case enOperationType::Div:
		CorrectAnswer = Number1 / Number2;
		break;
	}

	if (UserAnswer != CorrectAnswer)
	{
		system("color 4f");
		cout << "Wrong Answer :-(" << endl;
		cout << "The Right Answer = " << CorrectAnswer << endl;
		return 0;
	}
	else
	{
		system("color 2f");
		cout << "Right Answer :-)" << endl;
		return 1;
	}
	
}

enPassOrFail CheckPassOrFail(int Counter)
{
	if (Counter >= ((float)::HellowQuestions.NumberOfQuestions / 2))
	{
		return enPassOrFail::Pass;
		
	}
	else
	{
		return enPassOrFail::Fail;
	}
}

int StartRound()
{

	int Number1, Number2, Answer, Counter = 0;
	enOperationType Op = enOperationType::Add;

	for (int i = 1; i <= ::HellowQuestions.NumberOfQuestions; i++)
	{
		Number1 = NumberByLevel(::HellowQuestions.QuestionLevel);
		Number2 = NumberByLevel(::HellowQuestions.QuestionLevel);

		cout << "\nQuestion [" << i << "/" << ::HellowQuestions.NumberOfQuestions << "]\n" << endl;
		cout << Number1 << endl;

		if (::HellowQuestions.OperationType == enOperationType::mix)
		{
			Op = (enOperationType)RandomNumber(1, 4);
		}
		else
		{
			Op = ::HellowQuestions.OperationType;
		}

		cout << Number2 << "\t" << OpTypeChar(Op) << endl;
		cout << "-------------" << endl;
		cin >> Answer;

		Counter = Counter + CheckAnswer(Number1, Number2, Op, Answer);
	}

	return Counter;
}

void SetScreen()
{
	system("cls");
	system("color 0f");
}

string GetFailOrPassName(enPassOrFail PassOrFail)
{
	string FailOrPassName[2] = { "F A I L" , "P A S S" };

	return FailOrPassName[PassOrFail];
}

string GetQuestionLevelName(enQuestionLevel QuestionLevel)
{
	string QuestionLevelName[4] = { "Easy","Mid","Hard","Mix" };

	return QuestionLevelName[QuestionLevel - 1];
}

string GetOpTypeName(enOperationType OperationType)
{
	string OperationTypeName[5] = { "Add","Sub","Mul","Div","Mix" };

	return OperationTypeName[OperationType - 1];
}

void FinalResultScreen(int Counter)
{
	cout << "\n------------------------------\n" << endl;
	cout << "F I N A L  R E S U L T  I S  " << GetFailOrPassName(CheckPassOrFail(Counter)) << endl;
	cout << "\n------------------------------\n" << endl;

	if (CheckPassOrFail(Counter) == enPassOrFail::Pass)
		system("color 2f");
	else
		system("color 4f");

	cout << "Number Of Questions : " << ::HellowQuestions.NumberOfQuestions << endl;
	cout << "Question Level : " << GetQuestionLevelName(::HellowQuestions.QuestionLevel) << endl;
	cout << "Op Type : " << GetOpTypeName(::HellowQuestions.OperationType) << endl;
	cout << "Number Of Right Answers : " << Counter << endl;
	cout << "Number Of Wrong Answers : " << (::HellowQuestions.NumberOfQuestions - Counter) << endl;
	cout << "\n------------------------------" << endl;
}

void StartGame()
{
	char RePlay = 'y';
	int Counter = 0;

	do
	{
		SetScreen();
		fHellowQuestions();
		Counter = StartRound();
		FinalResultScreen(Counter);

		cout << " Do You Want To Play Again [ Y / N ]? ";
		cin >> RePlay;

	} while (RePlay == 'y' || RePlay == 'Y');
}

int main()
{
	srand((unsigned)time(NULL));

	StartGame();

	return 0;
}