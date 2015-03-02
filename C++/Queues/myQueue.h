#ifndef myQueue_h
#define myQueue_h
using namespace std;

// create a queue based on a circular design
class myQueue {
public:
	myQueue(int size) {
		if (size < 1)
			size = 1;
		m_size = size;
		m_array = new int[size];
		currentSize = 0;
		headpos = 0;
		tailpos = 0;
	}

	~myQueue() {
		delete [] m_array;
	}

	void push(int i) {
		if (currentSize == 0) {
			m_array[0] = i;
			currentSize++;
			return;
		}
		if (currentSize == m_size) {
			cout << "Queue is full! Did not push." << endl;
			return;
		}
		if (tailpos < m_size-1) {
			tailpos++;
			m_array[tailpos] = i;
			currentSize++;
		}
		else {
			if (headpos > 0)
				cout << "Something went wrong. Investigate." << endl;
			tailpos = 0;
			m_array[tailpos] = i;
			currentSize++;
		}
		return;
	}

	void pop() {
		if (currentSize == 0) {
			cout << "Queue is empty! Did not pop." << endl;
			return;
		}
		if (headpos == tailpos) {
			currentSize--;
			cout << "Pop is successful. Queue is now empty." << endl;
			return;
		}
		if (headpos < m_size-1) {
			headpos++;
			currentSize--;
			cout << "Pop is successful." << endl;
		}
		else {
			headpos = 0;
			currentSize--;
			cout << "Pop is successful." << endl;
		}
		return;
	}

	int front() {
		if (currentSize == 0) {
			cout << "Queue is empty! Returning -1." << endl;
			return -1;
		}
		return m_array[headpos];
	}

	bool is_empty() {
		if (currentSize == 0)
			return true;

		return false;
	}

	int sizeOfQueue() {
		return currentSize;
	}

private:
	int m_size;
	int currentSize;
	int *m_array;
	int headpos, tailpos;
};

#endif