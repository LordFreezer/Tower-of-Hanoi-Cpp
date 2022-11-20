#include <iostream>
#include <chrono>

using namespace std;
void MoveDisk(int N, int start, int finish, int temp)
{
    if (N <= 0) return;
    MoveDisk(N - 1, start, temp, finish);
    //cout << "Move disk " << N << " from " << start << " to " << finish << endl;
    MoveDisk(N - 1, temp, finish, start);
}
/*void move(int count, int start, int finish, int temp) 
{
    int swap, c = 0;
    while (count > 0) 
    {
        move(count - 1, start, temp, finish);
        cout << "Move disk " << count << " from "<< start << " to " << finish << endl;
        count--;
        swap = start;
        start = temp;
        temp = start;
    }   
}*/

int main()
{
    int N = 5;
    auto start = chrono::high_resolution_clock::now();
    MoveDisk(N, 1, 3, 2);
    auto end = chrono::high_resolution_clock::now();
    cout << "Elapsed time in nanosecond : "
        << chrono::duration_cast<chrono::nanoseconds>(end - start).count()
        << " μs" << endl;

    cout << "number of disks: " << N << endl;
}
