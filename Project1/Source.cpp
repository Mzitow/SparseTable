#include <iostream>
#include <string>
#include  "LinkedList.h"

using namespace std;


int roll(int min, int max)
{
    // x is in [0,1]
    double x = rand() / static_cast<double>(RAND_MAX + 1);

    // [0,1] * (max - min) + min is in [min,max[
    int that = min + static_cast<int>(x * (max - min));

    return that;
}




int main() {
   

  
    //Assuming we Have  9 students and 7 courses
    LinkedList<int>* sparseTable[7][9];
   


   
    //initialize our table with link lists all null pointing
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sparseTable[i][j] = new LinkedList<int>;
          
        }
    }

   //add some  random data to our sparseTable
   
    int no_of_elements = 0;
    for (int y = 0; y < 9; y++)
    {
       
        no_of_elements = 0;
            while (no_of_elements < 4)
            {
                int x_rand = roll(0, 7);

                if (sparseTable[x_rand][y]->isEmpty() && no_of_elements < 4)
                {
                    no_of_elements++;
                    sparseTable[x_rand][y]->appendNode(x_rand);
                   
                }

            }
    
    }

    
 
  
   //See the Links in the table
    // - represents a null node
    //otherwise the linked list is linked

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            sparseTable[i][j]->printSequence();

        }
        cout << endl;
       
    }

  
    cout << "Print Courses Studnet is Taking :\nEnter Student code: from 1 to 9: ";
    int studentID;
    cin >> studentID;
    studentID--;

    for (int j = 0; j < 7; j++)
    {
        if ( ! sparseTable[j][studentID]->isEmpty())
        sparseTable[j][studentID]->printSequence();

    }
    cout << endl;
   


    cout << "Print Students taking a Courses  :\nEnter Course code: from 1 to 7 : " ;
    int courseID;
    cin >> courseID;
    courseID--;

    for (int j = 0; j < 9; j++)
    {
        if (!sparseTable[courseID][j]->isEmpty())
            cout << j + 1<< " ";

    }
    cout << endl;

    return 0;
}