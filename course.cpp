#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
struct employee {
    int importance;
    int numberofsubs;
    vector<int> subordinates;
    employee(int importance, int numberofsubs) : importance(importance), numberofsubs(numberofsubs) {
        
    }
};
int ImportanceSum(const vector<employee*>&employees, int i) {
    if(employees[i]->subordinates.empty()) {
        return employees[i]->importance;
    }
    else {
        int sum = employees[i]->importance;
        for(auto j: employees[i]->subordinates) {
            sum += ImportanceSum(employees, j);
        }
        return sum;
    }
}
int main()
{
    int number, person;
    cin >> number >> person;
    vector<employee*>employees;
    employees.push_back(nullptr);
    
    while(number--) {
        int importance, numberofsubs;
        cin >> importance >> numberofsubs;
        employees.push_back(new employee(importance,numberofsubs));
        while(numberofsubs--) {
            int n;
            cin >> n;
            employees[employees.size()-1]->subordinates.push_back(n);
        }
    }
    cout << ImportanceSum(employees, person);
}