class minStack
{
	stack<pair<int, int>> stk;
	public:
		
		// Constructor
		minStack() 
		{}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(!stk.empty() && stk.top().second<num)
				stk.push({num, stk.top().second});
			else stk.push({num, num});
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(stk.empty()) return -1;
			int top = stk.top().first;
			stk.pop();
			return top;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(stk.empty()) return -1;
			return stk.top().first;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			if(stk.empty()) return -1;
			return stk.top().second;
		}
};