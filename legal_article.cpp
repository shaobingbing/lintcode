#include<cctype>
#include<iostream>

using namespace std;

int count(string &s);

int main()
{
	string s = "This won iz correkt. It has, No Mistakes et Oll. But there are two BIG mistakes in this sentence. and here is one more.";
	int x = count(s);
	cout << x << endl;
}

int count(string &s) {
	// Write your code here.
	bool begin_sentence = true;
	int begin_word = 0;
	int result = 0;
/*	for (int i = 0; i < s.size(); i++)
	{
		cout << i << ":" << s[i] << endl;
	}
*/
	for(int i = 0; i < s.size(); i++)
	{
		//cout << s[i] << endl;
		if(begin_sentence && islower(s[i]))
		{
	//		cout << " The first word of the sentence should be upper" << endl;
	//		cout << i << ":"<< s[i] << endl;
			result = result + 1;
			begin_sentence = false;
			begin_word++;
			continue;
		}
		if(begin_word!=0 && isupper(s[i]))
		{
	//		cout << " The other word of the word should be upper" << endl;
	//		cout << i << ":"<< s[i] << endl;
			result = result + 1;
			begin_word++;
			continue;
		}
		if(s[i] == ' ' || ispunct(s[i]))
		{
	//		cout << i << ":"<< s[i] << endl;
			if (s[i] == '.')
			{
				begin_sentence = true;
			}
			begin_word = 0;
			continue;
        }
		begin_word++;
		begin_sentence = false;
	}
	return result;
}