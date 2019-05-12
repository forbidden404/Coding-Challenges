#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
class Box {
	//l,b,h are integers representing the dimensions of the box
	private:
		int l, b, h;
		// The class should have the following functions : 

		// Constructors:
		// Box();
		// Box(int,int,int);
		// Box(Box);
	public:
		Box() : l(0), b(0), h(0) {}
		Box(int l, int b, int h) : l(l), b(b), h(h) { }
		Box(Box &box) {
			this->l = box.l;
			this->b = box.b;
			this->h = box.h;
		}

		// int getLength(); // Return box's length
		// int getBreadth (); // Return box's breadth
		// int getHeight ();  //Return box's height
		// long long CalculateVolume(); // Return the volume of the box
		int getLength() {
			return l;
		}

		int getBreadth() {
			return b;
		}

		int getHeight() {
			return h;
		}

		long long CalculateVolume() {
			long long a1 = l;
			long long a2 = b;
			long long a3 = h;
			return a1 * a2 * a3;
		}

		// Overload operator < as specified
		// bool operator<(Box& b)
		bool operator<(Box &b) {
			if (this->l < b.l) {
				return true;
			} else if (this->l == b.l) {
				if (this->b < b.b) {
					return true;
				} else {
					if (this->h < b.h) {
						return true;
					}
				}
			}
			return false;
		}

		// Overload operator << as specified
		// ostream& operator<<(ostream& out, Box& B)
		friend ostream& operator<<(ostream& out, Box& B);
};

ostream& operator<<(ostream& out, Box& b) {
	out << b.l << " " << b.b << " " << b.h;
	return out;
}
