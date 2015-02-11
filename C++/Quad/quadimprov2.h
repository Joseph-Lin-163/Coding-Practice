#ifndef quadimprov2_h
#define quadimprov2_h
#include <math.h>

/*
	Contains simple constructor using a default parameter, advanced copy constructor,
	advanced assignment operator, destructor.
*/

class Quad2 {
	public:
		// Normal constructor with default parameter
		Quad2(int size = 1) {
			m_arr = new int[size];
		}

		/* Copy constructor
			Anytime we:
			1) Allocate dynamic memory
			2) Open system resources like a file
			We need to:
			1) Determine how much memory is allocated by old variable
			2) Allocate the same amount of memory
			3) Copy the contents of the old variable to the new variable appropriately
		*/
		Quad2(const Quad2 &src) {
			size = src.size;
			m_arr = new int[size];
			for (int i = 0; i < size; i++) {
				m_arr[i] = src.m_arr[i];
			}
		}

		/* Assignment operator
			Anytime we:
			1) Allocate dynamic memory
			2) Open system resources like a file
			We need to:
			1) Free all dynamic memory used by the target instance
			2) Re-allocate memory in the target instance to hold any member
			   variables from the source instance.
			3) Explicitly copy the contents of the source instance to the target instance
		*/
		Quad2 &operator= (const Quad2 &src) {
			// Error checking
			if (&src == this) {
				return (*this);
			}

			delete [] m_arr;
			size = src.size;
			m_arr = new int[size];
			for (int i = 0; i < size; i++) {
				m_arr[i] = src.m_arr[i];
			}
			return (*this);
		}

		// Destructor
		~Quad2() {
			std::cout << "And I'm done!" << std::endl;
			delete [] m_arr;
		}

	private:
		int *m_arr;
		int size;
};

#endif