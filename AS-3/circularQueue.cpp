#include <iostream>
using namespace std;

class students
{
    string name;
    int rollNo;
    float sgpa;
    friend class queue;

public:
    students input()
    {
        students temp;
        cout << "Enter name: ";
        cin >> temp.name;
        cout << "Enter roll no: ";
        cin >> temp.rollNo;
        cout << "Enter sgpa: ";
        cin >> temp.sgpa;
        return temp;
    }
};

class queue
{
    students S;
    students s[10];
    int front, rear;
    int n;

public:
    queue(int no)
    {
        front = -1;
        rear = -1;
        n = no;
    }

    void insert()
    {
        if ((front == 0 && rear == n - 1) || front == rear + 1)
        {
            cout << "\nThe queue is full " << endl;
        }
        else
        {
            if (rear == -1)
            {
                front = 0;
            }
            rear = (rear + 1) % n;
            s[rear] = S.input();
        }
    }

    void remove()
    {
        if (front == -1)
        {
            cout << "The queue is empty" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % n;
        }
    }

    void display()
    {
        if (front != -1)
        {
            if (front <= rear)
            {
                for (int i = front; i <= rear; i++)
                {
                    cout << "Name is: " << s[i].name << endl;
                    cout << "Roll no is: " << s[i].rollNo << endl;
                    cout << "SGPA is: " << s[i].sgpa << endl;
                }
            }
            else
            {
                for (int i = front; i < n; i++)
                {
                    cout << "Name is: " << s[i].name << endl;
                    cout << "Roll no is: " << s[i].rollNo << endl;
                    cout << "SGPA is: " << s[i].sgpa << endl;
                }
                for (int i = 0; i <= rear; i++)
                {
                    cout << "Name is: " << s[i].name << endl;
                    cout << "Roll no is: " << s[i].rollNo << endl;
                    cout << "SGPA is: " << s[i].sgpa << endl;
                }
            }
        }
        else
        {
            cout << "";
        }
    }
};

int main()
{
    int check = 1;
    int no;
    //no=100;
    cout << "Enter the no of students: ";
    cin >> no;
    queue q(no);
    while (check == 1)
    {
        int c{0};
        cout << " " << endl;
        cout << "Choose your operation" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Display" << endl;
        cout << "4.Exist" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            q.insert();
            break;
        case 2:
            q.remove();
            break;
        case 3:
            q.display();
            break;
        case 4:
            check = 0;
            break;
        default:
            cout << "Error" << endl;
        }
    }
    return 0;
}