#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

void CountDown(int countInt) {
   if (countInt <= 0) {
      cout << "Go!\n";  // BASE CASE
   }
   else {

      CountDown(countInt - 1);
       cout << countInt << endl;

   }
}

int FindNumber(int number[], int lowIndex, int highIndex, int target) {
    int midIndex, midVal;

    midIndex = (highIndex + lowIndex) / 2;
    midVal = number[midIndex];
    cout << midVal;

    if (target == midVal) {
        return midIndex;
    }
    else if (lowIndex == highIndex) {
        return -1;
    }
    else {

        if (target < midVal) {

            return FindNumber(number, lowIndex, midIndex - 1, target);
        }
        else {

            return FindNumber(number, midIndex + 1, highIndex, target);
        }
    }

}

void FindNumber(int number, int lowVal, int highVal, int& count) {
    int midVal;

    midVal = (highVal + lowVal) / 2;
    cout << number;
    cout << " ";
    cout << midVal;

    if (number == midVal) {
        cout << " o" << endl;
    }
    else {
        count++;
        if (number < midVal) {
            cout << " p" << endl;

            FindNumber(number, lowVal, midVal, count);
        }
        else {
            cout << " q" << endl;
            FindNumber(number, midVal + 1, highVal, count);
        }
    }
}

void generate(int numbers[], int size, int index) {
    if (index >= size) {
        return;
    }

    numbers[index] = rand();
    generate(numbers, size, index+1);
}

void print(int numbers[], int size, int index) {
    if (index >= size) {
        return;
    }
    cout << numbers[index] << endl;
    print(numbers, size, index+1);
}

int main() {
    int n[10];
    generate(n, 10, 0);
    sort(n, n+10);
    print(n, 10, 0);
    int index = FindNumber(n, 0, 10, 99);
    cout << endl <<  index << endl;

}


//int main() {
//    int number;
//
//    cin >> number;
//    int count = 0;
//    FindNumber(number, 0, 1200, count);
//    cout << count << endl;
//    return 0;
//}

//void countDown(int n) {
//    while (n > 0) {
//        --n;
//    }
//}
//
