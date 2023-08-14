#include <iostream>
#include <string>
#define M 101
using namespace std;

struct Student {
    string id;
    string name;
    string email;
    string phoneNumber;
};

struct Node {
    Student St;
    Node *next;
};

Node *createNode(Student St) {
    Node *node = new Node;
    node->St = St;
    node->next = nullptr;
    return node;
}

void init(Node *heads[]) {
    for (int i = 0; i < M; i++)
    {
        heads[i] = nullptr;
    }
}

int hashFunc(string name) {
    int h = 0;
    for (int i = 0; i < name.length(); i++)
    {
        h = h + (int)tolower(name[i]);
    }
    return h % M;
}

void add(Node *heads[], Student St) {
    int h = hashFunc(St.name);
    cout << h << endl;
    Node *temp = heads[h];
    Node *p = createNode(St);
    if (temp == nullptr) {
        heads[h] = p;
    }
    else
    {
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void list(Node *heads[]) {
    for (int i = 0; i < M; i++) {
        if (heads[i] != nullptr) {
            Node *p = heads[i];
            while (p != nullptr) {
                cout << p->St.id << "\t" << p->St.name << "\t" << p->St.email << "\t" << p->St.phoneNumber << endl;
                p = p->next;
            }
        }
    }
}

void findName(Node *heads[], string name)
{
    int h = hashFunc(name);
    Node *curr = heads[h];
    while (curr != nullptr)
    {
        if (curr->St.name == name)
        {
            cout << curr->St.id << "\t" << curr->St.name << "\t" << curr->St.email << "\t" << curr->St.phoneNumber << endl;
            return;
        }
        curr = curr->next;
    }
}

int main()
{
  Student St1, St2, St3, St4;
  // Student1
  St1.id = "21H1120013";
  St1.name = "Ho Chi Nhan";
  St1.email = "hochinhan5612@gmail.com";
  St1.phoneNumber = "0328909007";
  // Student 2
  St2.id = "21H1120054";
  St2.name = "Do Kim Lam";
  St2.email = "LamPussy@gmail.com";
  St2.phoneNumber = "0927622092";
  // Student 3
  St3.id = "21H1120034";
  St3.name = "Nguyen Duc Thiep";
  St3.email = "ThiepNgonLu@gmail.com";
  St3.phoneNumber = "9875643210";

  St4.id = "21H1120013";
  St4.name = "Ho Chan Nhi";
  St4.email = "hochinhan5612@gmail.com";
  St4.phoneNumber = "0328909007";

  Node *heads[M];
  init(heads);

  add(heads, St1);
  add(heads, St2);
  add(heads, St3);
  add(heads, St4);

  //list(heads);

  //findName(heads, "Ho Chan Nhi");

  return 0;
}
