#include <iostream>
#include <math.h>
using namespace std;

bool scp(int n){
    int sqr = sqrt(n);
    return (sqr*sqr == n);
}

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
    public:
        BST() {
            pRoot = nullptr;
        }

        void setpRoot(Node *pRoot) {
            this->pRoot = pRoot;
        }

        Node *getpRoot() {
            return pRoot;
        }

        bool insertNode(int x) {
            Node *p = new Node(x);
            if(pRoot == nullptr) {
                pRoot = p;
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
                                return true;
                            }
                        }
                    }
                }
            }
        }

        void travelNLR(Node *p) {
            if(p != nullptr)
            {
                cout << p->getKey() << " ";
                travelNLR(p->getpLeft());
                travelNLR(p->getpRight());
            }
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
                    delete p;
                }
            }
        }

        void delScp(Node *p, BST a) {
            if(p != nullptr) {
                if(scp(p->getKey())) {
                    int delData = p->getKey();
                    p = p->getpParent();
                    delNode(a.getpRoot(), delData);

                }
                delScp(p->getpLeft(), a);
                delScp(p->getpRight(), a);
            }
        }

        void checkSumLR(Node *p) {
            if(p != nullptr) {
                int sumL = 0;
                sumTree(p->getpLeft(), sumL);
                int sumR = 0;
                sumTree(p->getpRight(), sumR);
                if(sumL == sumR && sumL != 0) {
                    cout << p->getKey() << " ";
                }
                checkSumLR(p->getpLeft());
                checkSumLR(p->getpRight());
            }
        }

        void sumTree(Node *p, int &Sum) {
            if(p != nullptr)
            {
                Sum += p->getKey();
                sumTree(p->getpLeft(), Sum);
                sumTree(p->getpRight(), Sum);
            }
        }
        ~BST(){};
};

int main()
{
    BST a;
    a.insertNode(10);
    a.insertNode(6);
    a.insertNode(15);
    a.insertNode(2);
    a.insertNode(9);
    a.insertNode(12);
    a.insertNode(26);
    a.insertNode(14);
    a.travelNLR(a.getpRoot());
    cout << endl;
    a.delScp(a.getpRoot(), a);
    a.travelNLR(a.getpRoot());
    cout << endl;
    cout << "Nut thoa dieu kien: ";
    a.checkSumLR(a.getpRoot());
    return 0;
}
