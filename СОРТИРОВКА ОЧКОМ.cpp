#include <iostream>
#include <fstream>
#include <string>

using namespace std;


ifstream fin("students.txt");
ofstream fout;
void split(string* split_string, string s, int& n, char c) {
	string temp = "";
	s += c;
	for (int k = 0; k < s.size(); k++) {
		if (s[k] != c) {
			temp += s[k];
		}
		else {
			split_string[n] = temp;
			temp = "";
			n++;
		}
	}
}

struct Student {
	string name, surname, otch;
	int yearbirth, m1, m2, m3, m4, m5, group;
	void put_in_file();
	int get_sum_of_marks();
	Student();
	Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_);
};
Student::Student(int group_, string surname_, string name_, string otch_, int yearbirth_, int m1_, int m2_, int m3_, int m4_, int m5_) {
	group = group_;
	name = name_;
	surname = surname_;
	otch = otch_;
	yearbirth = yearbirth_;
	m1 = m1_;
	m2 = m2_;
	m3 = m3_;
	m4 = m4_;
	m5 = m5_;
}
Student::Student() {
	group = 0;
	name = " ";
	surname = " ";
	otch = " ";
	yearbirth = 0;
	m1 = 0;
	m2 = 0;
	m3 = 0;
	m4 = 0;
	m5 = 0;
}

void Student::put_in_file() {
	fout << group << " " << surname << " " << name << " " << otch << " ";
	fout << yearbirth << " " << m1 << " " << m2 << " " << m3 << " " << m4 << " " << m5 << endl;
}

int Student::get_sum_of_marks() {
	return m1 + m2 + m3 + m4 + m5;
}

void bubble_sort(Student* students, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + 1 < n - i; j++) {
			auto s1 = students[j + 1];
			auto s2 = students[j];
			if (s1.get_sum_of_marks() < s2.get_sum_of_marks()) {
				auto t = students[j + 1];
				students[j + 1] = students[j];
				students[j] = t;
			}
		}
	}
}
void insertion_sort(Student* students, int n) {
	for (int i = 1; i < n; i++) {
		auto d = students[i];
		int ss = d.get_sum_of_marks();
		int j = i;
		while (j > 0 && (ss < students[j - 1].get_sum_of_marks())) {
			students[j] = students[j - 1];
			j--;
		}
		students[j] = d;
	}
}

void selection_sort(Student* students, int n) {
	int key, j, i;
	for (i = 0; i < n - 1; i++) {
		key = i;
		for (j = i + 1; j < n; j++) {
			auto s1 = students[j];
			auto s2 = students[key];
			if (s1.get_sum_of_marks() < s2.get_sum_of_marks()) {
				key = j;
			}
		}
		if (key != j) {
			auto t = students[i];
			students[i] = students[key];
			students[key] = t;
		}
	}
}


int main() {
	setlocale(LC_ALL, "Russian");
	int n = 100, c = 0, nn = 10, k = 0;
	Student* students = new Student[n];
	string info;
	while (fin.peek() != EOF) {
		getline(fin, info);
		nn = 10;
		k = 0;
		string* tmp = new string[nn];
		split(tmp, info, k, ' ');
		students[c].group = stoi(tmp[0]);
		students[c].surname = tmp[1];
		students[c].name = tmp[2];
		students[c].otch = tmp[3];
		students[c].yearbirth = stoi(tmp[4]);
		students[c].m1 = stoi(tmp[5]);
		students[c].m2 = stoi(tmp[6]);
		students[c].m3 = stoi(tmp[7]);
		students[c].m4 = stoi(tmp[8]);
		students[c].m5 = stoi(tmp[9]);
		c++;
	}
	fout.open("bubble_sort.txt");
	bubble_sort(students, c);
	for (int i = 0; i < c; i++)
		students[i].put_in_file();
	fout.close();
	fout.open("insertion_sort.txt");
	insertion_sort(students, c);
	for (int i = 0; i < c; i++)
		students[i].put_in_file();
	fout.close();
	fout.open("selection_sort.txt");
	selection_sort(students, c);
	for (int i = 0; i < c; i++)
		students[i].put_in_file();
	fout.close();


}