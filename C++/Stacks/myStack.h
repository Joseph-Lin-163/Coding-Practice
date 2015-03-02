#ifndef myStack_h
#define myStack_h
using namespace std;

class myStack {
public:
	myStack(int size) {
		m_size = size;
		m_position = -1;
		m_stack = new int[size];
	}

	~myStack() {
		delete [] m_stack;
	}
	
	void push(int i) {
		if (++m_position > m_size) {
			cout << "Stack is full! Did not push." << endl;
			return;
		}
		m_stack[m_position] = i;
		cout << "Push operation complete." << endl;
	}

	int pop() {
		if (--m_position < -1) {
			cout << "Stack is empty! Did not pop. Returning -1." << endl;
			m_position = -1;
			return -1;
		}

		return m_stack[m_position+1];
	}

	bool is_empty() {
		if (m_position == -1)
			return true;
		
		return false;
	}

	int peek_top() {
		if (m_position == -1) {
			cout << "Stack is empty! Returning -1." << endl;
			return -1;
		}

		return m_stack[m_position];
	}

	void printSizeOfStack () {
		if (m_position == -1) 
			cout << "Stack is empty!" << endl;
		else
			cout << "Size of stack is: " << m_position+1 << endl;
	}

private:
	int m_size;
	int m_position;
	int *m_stack;

};

#endif