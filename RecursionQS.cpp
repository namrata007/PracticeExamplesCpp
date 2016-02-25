#include<iostream>
#include<vector>
#include<time.h> 
#include<stdlib.h>
#include<string>
using namespace std;

void quicksort(vector<int> &toSort, int left, int right){
  int pivot = toSort[(left + right)/2];
  int k = left;
  int l = right;
  while(k <= l){
    while(toSort[k] < pivot)
      k++;
    while(toSort[l] > pivot)
      l--;
    if(k <= l){
      int tmp;
      tmp = toSort[k];
      toSort[k] = toSort[l];
      toSort[l] = tmp;
      k++;
      l--;
    }
  }
  if(left < l)
    quicksort(toSort, left, l);
  if(k < right)
    quicksort(toSort, k, right);
}

int factorial(int x){
  if(x == 1)
    return 1;
  else 
    return x * factorial(x-1);
}
void FunctionCallChoiceBased(int choice){
  switch(choice){
    case 1: {
        int x; 
        cout<<"\nFactorial Example\nEnter the number to find factorial\t";
        cin>>x;
        cout<<"\nFactorial is\t"<<factorial(x)<<endl; 
      }
      break; 
    case 2: {
      vector<int> toSort;
      int a, b, size;
      cout<<"\nQuick sort Example\nEnter the range of random numbers for sorting\t";
      cin>>a>>b;
      cout<<"\nEnter the size of container\t";
      cin>>size;
      srand (time(NULL));
      std::cout<<"\nUnsorted Container\n";
      for (int i = 0; i <= size-1; i++){
        toSort.push_back(rand()%(b-1) + a);
        std::cout<<"\t"<<toSort[i];
      }  
      quicksort(toSort, 0, size-1);
      std::cout<<"\nSorted Container\n";
      for (int i = 0; i <= size-1; i++){
        std::cout<<"\t"<<toSort[i];
      }
    }
    break;
    default:
      cout<<"\nNo function selected. Program ends!\n";
      break;
  }
}

int main(){
  int choice;
  string more;
  do{
    cout<<"\nRecusion examples for practise.\n1. Factorial\n2. QuickSort\n0. Quit the program";
    cin>>choice;
    FunctionCallChoiceBased(choice);
    cout<<"\nWould you like to check a few more\t(y or n)";
    cin>>more;
  }while(more == "y" or more == "Y" or more == "Yes" or more == "YES" or more == "yes");

return 0;
}
