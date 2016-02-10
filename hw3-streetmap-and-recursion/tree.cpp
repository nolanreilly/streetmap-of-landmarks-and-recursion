#include <iostream>
using namespace std;

int countIncludes(const double a1[], int n1, const double a2[], int n2);
void exchange(double& x, double& y);
void split(double a[], int n, double splitter, int& firstNotGreater, int& firstLess);
void order(double a[], int n);


// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//	10 50 40 20 50 40 30
// then for this value of a2     the function must return
//	10 20 40			1
//	10 40 30			2
//	20 10 40			0
//	50 40 30			3

int countIncludes(const double a1[], int n1, const double a2[], int n2) {
// a1 = [ 1 | 0 | 1 | 2 | 3 ]
// a2 = [ 1 | 2 | 3 ]
    if(n2 == 0)
        return 1;
    if (n1 == 0)
        return 0;
// case #1:
    if(a1[0] != a2[0]) {
        return countIncludes(a1+1, n1-1, a2, n2);
    }
    // check first element
    else {
        // 2-3 in remainder?
        int c = countIncludes(a1+1, n1-1, a2+1, n2-1) + countIncludes(a1+1, n1-1, a2, n2);
        // check the rest of a2 for any more matches in a1 + check the rest of a1 for the full a2
        return c;
    }
}

/*int main() {
    //double a1[] = {50, 20, 40, 30, 50, 20, 30};
    //double a2[] = {50, 20, 30};
    //cout << countIncludes(a1, 7, a2, 3);
    //double a3[] = {20, 20, -40, 30, 50, 90, -30, 130};
    //order(a3, 8);
    //for(int i = 0; i < 8; i++)
    //    cout << a3[i] << " ";
}*/

// Exchange two doubles
void exchange(double& x, double& y)
{
    double t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is > splitter come before all the other elements,
// and all the elements whose value is < splitter come after all
// the other elements.  Upon return, firstNotGreater is set to the
// index of the first element in the rearranged array that is
// <= splitter, or n if there is no such element, and firstLess is
// set to the index of the first element that is < splitter, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotGreater, a[i] > splitter
//   * for firstNotGreater <= i < firstLess, a[i] == splitter
//   * for firstLess <= i < n, a[i] < splitter
// All the elements > splitter end up in no particular order.
// All the elements < splitter end up in no particular order.
void split(double a[], int n, double splitter,
           int& firstNotGreater, int& firstLess)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotGreater <= firstUnknown and firstUnknown <= firstLess
    //  Every element earlier than position firstNotGreater is > splitter
    //  Every element from position firstNotGreater to firstUnknown-1 is
    //    == splitter
    //  Every element from firstUnknown to firstLess-1 is not known yet
    //  Every element at position firstLess or later is < splitter
    
    firstNotGreater = 0;
    firstLess = n;
    int firstUnknown = 0;
    while (firstUnknown < firstLess)
    {
        if (a[firstUnknown] < splitter)
        {
            firstLess--;
            exchange(a[firstUnknown], a[firstLess]);
        }
        else
        {
            if (a[firstUnknown] > splitter)
            {
                exchange(a[firstNotGreater], a[firstUnknown]);
                firstNotGreater++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] >= a[1] >= a[2] >= ... >= a[n-2] >= a[n-1]
// If n <= 1, do nothing.
void order(double a[], int n) {
    if(n <= 1)
        return;
    // base case
    double p_splitter = a[0];
    int p_firstNotGreater, p_firstLess;
    
    // split before recursing
    split(a, n, p_splitter, p_firstNotGreater, p_firstLess);
    
    if(n > p_firstLess)
        order(a+1, n-1);
    // if n > index of (first item < splitter), "point" firstLess to tcheck the next item
    
    order(a, p_firstNotGreater);
    // when firstLess is done iterating, n = orig - (when first > splitter)
}

