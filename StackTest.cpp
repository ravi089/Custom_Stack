#include "Stack.h"
#include <iostream>
using namespace std;

int main()
{
	/*	Stack<int> st;
	st.addToStack(3);
	st.addToStack(1);
	st.addToStack(4);
	st.addToStack(2);
	st.addToStack(5);	*/

	Stack<string> st;
	st.addToStack("ravi");
	st.addToStack("dev");
	st.addToStack("anees");
	st.addToStack("priya");
	st.addToStack("karan");	

	//st.reverseStack();
	st.sortStack();

	cout << st << endl;

	system("pause");
	return 0;
}