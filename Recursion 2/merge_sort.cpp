/*
Merge Sort Code

Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 1000

Sample Input:
6 
2 6 8 5 4 3

Sample Output:
2 3 4 5 6 8
*/

#include <iostream>
using namespace std;

void merge(int part1[], int size1, int part2[], int size2, int output[]){
    int i=0, j=0, k=0;
    while(i<size1 && j<size2){
        if(part1[i] < part2[j]){
            output[k]=part1[i];
            k++;
            i++;
        }
        else{
            output[k]=part2[j];
            k++;
            j++;
        }
    }

    while(i<size1){
        output[k]=part1[i];
        k++;
        i++;
    }
    while(j<size2){
        output[k]=part2[j];
        k++;
        j++;
    }
}

void mergeSort(int input[], int size){
    if(size <= 1){
        return;
    }
    int mid=size/2;
    int part1[500], part2[500];
    int size1=mid, size2=size-mid;
    for(int i=0; i<mid; i++){
        part1[i]=input[i];
    }
    int k=0;
    for(int i=mid; i<size; i++){
        part2[k]=input[i];
        k++;
    }
    mergeSort(part1, size1);
    mergeSort(part2, size2);
    merge(part1, size1, part2, size2, input);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
