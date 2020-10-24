//author: ivan vynnyk  
#include <iostream>
#include <vector>
using namespace std;
vector <int> del_complex(vector <int> &prime, int &size) //sieve search function of Eratosthenes
{
    prime[1] = 0;
    for (int i = 2; i < size; ++i)
    {
        if (i * i <= size)
        {
            for (int j = 2 * i; j < size; j += i) //searching complex numbers (sieve)
            {
                prime[j] = 0; // erasing complex numbers
            }

        }
        else // means that there are no prime numbers else
            break;
    }
    prime.erase(remove(prime.begin(), prime.end(), 0), prime.end()); // deleting complex numbers
    return prime;
}
int main()
{
    cout << "============Start working============\n"; // just beautiful
    int size;
    while (true) //checking for correct input
    {
        
        cout << "  Check up even numbers from 4 to : ";
        if ((cin >> size) && cin.peek() == '\n')
        {
            if (size < 0)
                cout << "Negative numbers are absolutely equal to positive. Please try again.\n";
            else if (size == 0)
                cout << "I can't check for 0. Please try again.\n";
            else if (size == 1)
                cout << "Number 1 is too small. Please try again.\n";
            else if (size == 2)
                cout << "Number 2 is not included in The Goldbach hypothesis. Please try again.\n";
            else if (size == 3)
                cout << "Number 3 is too small. Please try again.\n";
            else
                break;
        }
        else cout << "It is not a number. Please try again.\n";
        cin.clear(); // clear cin status
        cin.ignore(32767, '\n'); // delete previous enter
    }
    ++size; //if user enters 8, we can check even numbers including 8 too
    vector <int> vec;
    vector <int>::iterator p, q; //iterators for vectors. similar to 'i' and 'j'
    vector <int>::reverse_iterator s; //reverse iterator for less time
    for (int i = 0; i < size; ++i)
        vec.push_back(i); // add not negative numbers from 0 to size
    vec = del_complex(vec, size);
    vector <int>even;
    for (int i = 4; i < size; i += 2) // make vector with only even numbers (except 2)
    {
        even.push_back(i);
    }
    cout << "Even numbers from 2 to " << size - 1 << " are found.\n";
    int order = 0; //order counter
    cout << "Result (even numbers (except 2) as the sum of two prime).\n";
    for (p = even.begin(); p != even.end(); ++p) // prime numbers
    {
        bool fl = true; // clearing fl status to start cycles for new number
        for (q = vec.begin(); q != vec.end()&&fl; ++q) //normal search
        {
            for (s = vec.rbegin(); s != vec.rend() &&fl; ++s) // reverse search
            {
                if (*q + *s == *p) // if found
                {
                    cout << ++order << ") " << *p << " = " << *q << " + " << *s << endl;
                    fl = false; // break two cycles
                }
                else if (*s + *s == *p) //if it is the sum of two similar numbers
                {
                    cout << ++order << ") " << *p << " = " << *s << " + " << *s << endl;
                    fl = false;
                }
                else if (s +1 == vec.rend() && q +1 == vec.end()) // if the cycles have reached the end and couldn't find
                {
                    cout << ++order << ") Couldn't find for " << *p << endl;
                    fl = false;
                }
            }
            
        }
    }
    cout << "Stopped working. The Goldbach hypothesis is true for this amount of numbers.\n";
    system ("pause"); // press any key (needed in micosoft vs)
    return 0;
}