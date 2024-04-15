#include <iostream>
#include <string>
using namespace std;

void arithmetic(int a, int b, int* sum, int* diff, int* multi, int* divi) {
	//******************problem1-1*************//
	*sum = a + b;
	*diff = a - b;
	*multi = a * b;
	*divi = a / b;

	//******************problem1-1 END*************//
}
void split_student_id(string student_id, int& firsthalf_student_id, int& secondhalf_student_id) {
	//******************problem1-2*************//
	firsthalf_student_id = stoi(student_id.substr(0, student_id.length() / 2));
	secondhalf_student_id = stoi(student_id.substr(student_id.length() / 2, student_id.length()));
	//******************problem1-2 END*************//
}

int main() {
	string student_id;
	int first_half_stid, second_half_stid;
	cout << "Input your Student ID: ";
	//******************problem1-3*************//
	cin >> student_id;
	int m_sum, m_diff, m_multi, m_divi;

	/* main */
	split_student_id(student_id, first_half_stid, second_half_stid);
	/* main */
	arithmetic(first_half_stid, second_half_stid, &m_sum, &m_diff, &m_multi, &m_divi);


	cout << "first_half_student_id: " << first_half_stid << " second_half_student_id: " << second_half_stid << endl;
	cout << "sum: " << m_sum << " diff: " << m_diff << " multi: " << m_multi << " divi: " << m_divi << endl;
	//******************problem1-3 END*************//

	return 0;
}



