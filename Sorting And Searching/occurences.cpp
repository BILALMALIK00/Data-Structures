#include <iostream>
using namespace std;

struct Student {
    int id;
    double gpa;
};

// Binary search function to find the first GPA greater than the target
int binarySearchGPA(Student s1[], int n, double target) {
  int s=0;
  int e=n-1;
  int ans=0;
  while(s<=e){
  	int mid=(s+e)/2;
  	if(s1[mid].gpa==target){
  		ans=mid;
  		e=mid-1;
	  }else if(s1[mid].gpa>target){
	  	e=mid-1;
	  }else{
	  	s=mid+1;
	  }
  }
  return ans;
}
int getStudentIDsWithGpaGreaterThan3(Student students[], int n, int result[], double target) {
    int startIndex = binarySearchGPA(students, n, target);
    int count = 0;
    for (int i = startIndex; i <n&&students[i].gpa==target; i++) {
        result[count++] = students[i].id;
    }
    
    return count; 
}

int main() {
    Student students[] = {
        {101, 3.0}, {102, 3.0}, {103, 3.0}, {104, 3.0}, {105, 3.1}
    };
    
    int n = sizeof(students) / sizeof(students[0]);
        int result[n];
        double target= 3.0;
    int count = getStudentIDsWithGpaGreaterThan3(students, n, result, target);
    
    // Output the result
    if (count == 0) {
        cout << "No students have GPA " << endl;
    } else {
        cout << "Student IDs with GPA  "<<target<<": ";
        for (int i = 0; i < count; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

