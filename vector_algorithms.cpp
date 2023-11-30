#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <algorithm>
using namespace std;


void print(vector<int> vec, string text = "") {
	cout << "Vector "<< text <<": ";
	for (auto item : vec) {
		cout << item << "\t";
	}
	cout << endl;
}

int main()
{

	//1
	vector<int> vec;
	vec.resize(5);
	for (size_t i = 0; i < 5; i++)
	{
		cout << "Enter " << i+1 << " number: ";
		cin >> vec[i];
	}
	print(vec, "1");
	vector<int> vector2;
	for (size_t i = 0; i < 10; i++)
	{
		vector2.push_back(0);
	}
	print(vector2, "2");
	
	int amount;
	cout << "Enter amount: ";
	cin >> amount;
	vector<int> vector3 = {};
	for (size_t i = 0; i < amount; i++)
	{
		vector3.push_back(rand() % 50);
	}


	vector<int> vector4;
	vector4.resize(vec.size());
	copy(vec.begin(), vec.end(), vector4.begin());
	print(vector4, "4");
	vector<int> vector5;
	vector5.resize(vector3.size()-2);
	copy(vector3.begin() + 1, vector3.end() - 1, vector5.begin());
	print(vector5, "5");



	//2
	print(vector3, "3");
	ofstream file("Numbers.txt");
	if (file.bad()) {
		cout << "Error during an attempt to write in file";
	}
	else {
		file << "Vector 3:\t";
		for (auto it = vec.rbegin(); it != vec.rend(); it++) {
			file << *it << "\t";
		}
		file.close();
	}

	//3
	int increaser = 0;
	for (size_t i = 0; i < 10; i++)
	{
		++increaser;
		vector2[i] = increaser;
	}
	print(vector2, "2");

	for (size_t i = 0; i < 10; i++)
	{
		int tmp = vector2[i];
		vector2[rand() % 10] = tmp;
		vector2[i] = vector2[rand() % 10];
	}
	print(vector2, "2");
	cout << endl;
	vector2.erase(vector2.begin()+1);
	vector2.pop_back();
	print(vector2, "2");

	//4
	const int old_size = vector4.size();
	vector<int>new_vector;
	for (auto item : vector4) {
		new_vector.push_back(item);
		new_vector.push_back(item);
	}
	vector4.clear();
	vector4 = new_vector;
	print(vector4, "4");

	//5
	vector5.clear();
	vector5.resize(vector4.size());
	auto is_even = [](int const& elem) { return !(elem % 2); };
	copy_if(vector4.begin(), vector4.end(), vector5.begin(), is_even);
	transform(vector5.begin(), vector5.end(), vector5.begin(), [](int const& elem) { return elem / 2; });
	print(vector5, "5");

	//6
	vector<int> v{ 10,2,10,5,10,6,10 };
	int value = 10;
	auto it = find(v.begin(), v.end(), value);
	while (it != v.end())
	{
		cout << "value :: " << *it << "\t index :: " << it - v.begin() << endl;
		it = find(it + 1, v.end(), value);
	}
	cout << "Count value {" << value << "} :: " << count(v.begin(), v.end(), value) << endl;


	// II

	vector<vector<int>> mult;
	vector<int> sample;
	for (size_t i = 1; i <= 10; i++)
	{
		sample.push_back(i);
	}
	sample.resize(10);
	mult.push_back(sample);
	print(sample, "sample");
	sample.clear();
	mult.resize(10);
	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 1; j < 10; j++)
		{
			mult[i].push_back(mult[0][j] * i);
		}
	}
	for (auto item : mult) {
		print(item);
	}
	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 1; j < 10; j++)
		{
			if (i == 1) {
				cout << i << " x " << j << " = " << mult[0][j-1] << endl;
			}
			else if (j == 1){
				cout << i << " x " << j << " = " << mult[0][i-1] << endl;
			}
			else {
				cout << i << " x " << j << " = " << mult[j][i-2] << endl;
			}
			
		}
		cout << endl;
	}
}
	

