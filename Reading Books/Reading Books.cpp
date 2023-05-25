/*
* There are n books, and Kotivalo and Justiina are going to read them all. For each book, you know the time it takes to read it.
*
* They both read each book from beginning to end, and they cannot read a book at the same time. What is the minimum total time required?
*
* The first input line has an integer n: the number of books.
* The second line has n integers t1,t2,…,tn: the time required to read each book.
*
* Print one integer: the minimum total time.
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long total = 0, maxEl = 0;
    while (n--) {
        long long t;
        cin >> t;
        total += t;
        maxEl = max(maxEl, t);
    }

    cout << max(total, maxEl * 2);
}