#include <iostream>

using namespace std;

class Node {
    private:
        char key;
        Node *pLeft;
        Node *pRight;
        Node *pParent;
    public:
        Node (char key) {
            this->key = key;
            this->pLeft = nullptr;
            this->pRight = nullptr;
            this->pParent = nullptr;
        }

        void setKey(char key) {
            this->key = key;
        }

        int getKey() {
            return key;
        }

        void setpLeft(Node *pLeft) {
            this->pLeft = pLeft;
        }

        Node *getpLeft() {
            return pLeft;
        }

        void setpRight(Node *pRight) {
            this->pRight = pRight;
        }

        Node *getpRight() {
            return pRight;
        }
        void setpParent(Node *pParent) {
            this->pParent = pParent;
        }

        Node *getpParent() {
            return pParent;
        }
        ~Node(){};
};
//Binary Search Tree
class BST {
    private:
        Node *pRoot;
        int nodeNumber;
    public:
        BST() {
            pRoot = nullptr;
            nodeNumber = 0;
        }

        void setpRoot(Node *pRoot) {
            this->pRoot = pRoot;
        }

        Node *getpRoot() {
            return pRoot;
        }

        void setNodeNumber(int nodeNumber) {
            this->nodeNumber = nodeNumber;
        }

        int getNodeNumber() {
            return nodeNumber;
        }

        bool insertNode(char x) {
            Node *p = new Node(x);
            if(pRoot == nullptr) {
                pRoot = p;
                nodeNumber++;
                return true;
            }
            else {
                Node *k = pRoot;
                while(k != nullptr) {
                    if(x == k->getKey()) {
                        return false;
                    }
                    else {
                        if(x > k->getKey()) {
                            if(k->getpRight() != nullptr) {
                                k = k->getpRight();
                            }
                            else {
                                k->setpRight(p);
                                p->setpParent(k);
                                nodeNumber++;
                                return true;
                            }
                        }
                        else {
                            if(k->getpLeft() != nullptr) {
                                k = k->getpLeft();
                            }
                            else {
                                k->setpLeft(p);
                                p->setpParent(k);
                                nodeNumber++;
                                return true;
                            }
                        }
                    }
                }
            }
        }

        void travelNRL(Node *pRoot) {
            if(pRoot != nullptr)
            {
                cout << (char)pRoot->getKey() << " ";
                travelNRL(pRoot->getpRight());
                travelNRL(pRoot->getpLeft());
            }
        }

        void travelLRN(Node *pRoot) {
            if(pRoot != nullptr)
            {
                travelLRN(pRoot->getpLeft());
                travelLRN(pRoot->getpRight());
                cout << (char)pRoot->getKey() << " ";
            }
        }

        Node* searchNode(int x) {
            Node *p = pRoot;
            while(p != nullptr) {
                if(x == p->getKey()) return p;
                if(x < p->getKey()) p = p->getpLeft();
                if(x > p->getKey()) p = p->getpRight();
            }
            return nullptr;
        }

        void delNode(Node *pRoot, char x) {
            if(pRoot == nullptr) {
                return;
            }
            else {
                if(pRoot->getKey() < x) {
                    delNode(pRoot->getpRight(), x);
                }
                else if(pRoot->getKey() > x) {
                    delNode(pRoot->getpLeft(), x);
                }
                else {
                    Node *p = pRoot;
                    if(pRoot->getpLeft() == nullptr && pRoot->getpRight() == nullptr) {
                        if(pRoot->getKey() > pRoot->getpParent()->getKey())
                        {
                            pRoot->getpParent()->setpRight(nullptr);
                        }
                        else {
                            pRoot->getpParent()->setpLeft(nullptr);
                        }
                    }
                    else if(pRoot->getpLeft() == nullptr) {
                        pRoot->getpParent()->setpLeft(pRoot->getpRight());
                        pRoot->getpRight()->setpParent(pRoot->getpParent());
                        pRoot = pRoot->getpRight();
                    }
                    else if(pRoot->getpRight() == nullptr){
                        pRoot->getpParent()->setpRight(pRoot->getpLeft());
                        pRoot->getpLeft()->setpParent(pRoot->getpParent());
                        pRoot = pRoot->getpLeft();
                    }
                    else {
                        Node *k = pRoot;
                        pRoot = pRoot->getpLeft();
                        if(pRoot->getpRight() == nullptr) {
                            k->getpParent()->setpRight(pRoot);
                            pRoot->setpRight(k->getpRight());
                            p = k;
                        }
                        else {
                            while(pRoot->getpRight() != nullptr) {
                                pRoot = pRoot->getpRight();
                            }
                            k->setKey(pRoot->getKey());
                            pRoot->getpParent()->setpRight(pRoot->getpLeft());
                            p = pRoot;
                        }
                    }
                    nodeNumber--;
                    delete p;
                }
            }
        }

        ~BST(){};
};

int main()
{
    BST a;
    a.insertNode('A');
    a.insertNode('B');
    a.insertNode('C');
    a.insertNode('D');
    a.insertNode('E');
    a.insertNode('F');
    a.insertNode('W');
    a.insertNode('Z');
    a.insertNode('U');
    a.insertNode('T');
    a.insertNode('K');
    a.insertNode('N');
    a.insertNode('G');
    a.insertNode('H');
    a.insertNode('M');
    a.insertNode('L');
    cout << "\nNRL: ";
    a.travelNRL(a.getpRoot());
    cout << "\nLRN: ";
    a.travelLRN(a.getpRoot());
    a.delNode(a.getpRoot(), 'W');
    cout << "\nNRL: ";
    a.travelNRL(a.getpRoot());
    a.delNode(a.getpRoot(), 'E');
    cout << "\nNRL: ";
    a.travelNRL(a.getpRoot());
    a.delNode(a.getpRoot(), 'H');
    cout << "\nNRL: ";
    a.travelNRL(a.getpRoot());
    a.delNode(a.getpRoot(), 'C');
    cout << "\nNRL: ";
    a.travelNRL(a.getpRoot());
    return 0;
}
