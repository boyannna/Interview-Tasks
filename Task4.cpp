#include<iostream>
#include<vector>

using namespace std;

int strength(int number) {

	int counter = 0;

	while (number != 1) {
		if (number % 2 == 0) {

			number = number / 2;
			counter++;
		}
		else {
			number = number * 3 + 1;
			counter++;
		}
	}

	return counter;
}

vector<pair<int, int>> makePair(int low, int high) {

	vector<pair<int, int>> numbers;
	int secondPos;

	for (int i = low; i <= high; i++) {
		secondPos = strength(i);
		numbers.push_back(make_pair(i, secondPos));
	}

	return numbers;
}

vector<pair<int, int>> sort(vector<pair<int, int>> numbers) {

	int n = numbers.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (numbers[j].second > numbers[j + 1].second) {
				swap(numbers[j], numbers[j + 1]);
			}
		}
	}
	return numbers;
}

int main() {

	vector<pair<int, int>> numbers;
	int k = 4;
	int counter = 0;
	numbers = makePair(7, 11);
	
	for (const auto& pair : numbers) {
		cout << "Number: " << pair.first << ", Strength: " << pair.second << endl;
	}

	numbers = sort(numbers);
	cout << "Number: ";
	for (const auto& pair : numbers) {
		cout << pair.first << " ";
	}

	cout << "\n";

	for (const auto& pair : numbers) {
		
		counter++;
		if (counter == k) {
			cout << "In index "<< k << " is number " << pair.first;
		}
	}
	
	return 0;
}