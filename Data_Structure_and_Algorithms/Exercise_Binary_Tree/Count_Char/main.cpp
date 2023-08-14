#include <iostream>

using namespace std;

class Node {
    private:
        int key;
        Node *pLeft;
        Node *pRight;
        Node *pParent;
    public:
        Node (int key) {
            this->key = key;
            this->pLeft = nullptr;
            this->pRight = nullptr;
            this->pParent = nullptr;
        }

        void setKey(int key) {
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

        bool insertNode(int x) {
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
        //Duyet Truoc
        void travelNLR(Node *pRoot) {
            if(pRoot != nullptr)
            {
                cout << pRoot->getKey() << " ";
                travelNLR(pRoot->getpLeft());
                travelNLR(pRoot->getpRight());
            }
        }
        //Duyet Giua
        void travelLNR(Node *pRoot) {
            if(pRoot != nullptr)
            {
                travelLNR(pRoot->getpLeft());
                cout << pRoot->getKey() << " ";
                travelLNR(pRoot->getpRight());
            }
        }
        //Duyet Sau
        void travelLRN(Node *pRoot) {
            if(pRoot != nullptr)
            {
                travelLRN(pRoot->getpLeft());
                travelLRN(pRoot->getpRight());
                cout << pRoot->getKey() << " ";
            }
        }
        //Tim kiem
        Node* searchNode(int x) {
            Node *p = pRoot;
            while(p != nullptr) {
                if(x == p->getKey()) return p;
                if(x < p->getKey()) p = p->getpLeft();
                if(x > p->getKey()) p = p->getpRight();
            }
            return nullptr;
        }
        //Chieu cao cay
        int calHeight(Node *pRoot) {
            if(pRoot == nullptr) {
                return 0;
            }
            return (1 + max(calHeight(pRoot->getpLeft()), calHeight(pRoot->getpRight())));
        }
        //So Node la
        int countLeafNode(Node *pRoot) {
            if(pRoot == nullptr) {
                return 0;
            }
            if(pRoot->getpLeft() ==  nullptr && pRoot->getpRight() == nullptr) {
                return 1;
            }
            return countLeafNode(pRoot->getpLeft()) + countLeafNode(pRoot->getpRight());
        }

        void delNode(Node *pRoot, int x) {
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
                        pRoot->getpParent()->setpRight(pRoot->getpRight());
                        pRoot->getpRight()->setpParent(pRoot->getpParent());
                        pRoot = pRoot->getpRight();
                    }
                    else if(pRoot->getpRight() == nullptr){
                        pRoot->getpParent()->setpLeft(pRoot->getpLeft());
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
                            pRoot->getpParent()->setpRight(nullptr);
                            p = pRoot;
                        }
                    }
                    delete p;
                }
            }
        }
        ~BST(){};
};

int main()
{
    BST a;
    /*a.insertNode(12);
    a.insertNode(4);
    a.insertNode(23);
    a.insertNode(2);
    a.insertNode(9);
    a.insertNode(15);
    a.insertNode(25);
    a.insertNode(1);
    a.insertNode(3);
    a.insertNode(7);
    a.insertNode(11);
    a.insertNode(8);*/
    a.insertNode(17);
    a.insertNode(13);
    a.insertNode(20);
    a.insertNode(12);
    a.insertNode(14);
    a.insertNode(19);
    a.insertNode(23);
    a.insertNode(18);
    a.insertNode(22);
    a.delNode(a.getpRoot(), 20);
    cout << "\n1: ";
    a.travelNLR(a.getpRoot());
    //cout << "\n2: ";
    //a.travelLNR(a.getpRoot());
    //cout << "\n3: ";
    //a.travelLRN(a.getpRoot());
    //cout << endl << a.getNodeNumber() << endl;
    //cout << a.calHeight(a.getpRoot()) << endl;
    //cout << a.countLeafNode(a.getpRoot()) << endl;
    return 0;
}
