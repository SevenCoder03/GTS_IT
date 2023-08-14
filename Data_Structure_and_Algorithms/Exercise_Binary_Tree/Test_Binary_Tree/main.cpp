#include <iostream>

using namespace std;

class Node {
    private:
        int key;
        int Count;
        Node *pLeft;
        Node *pRight;
        Node *pParent;
    public:
        Node (int key) {
            this->key = key;
            this->Count = 1;
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

        void setCount(int Count) {
            this->Count = Count;
        }
        int getCount() {
            return Count;
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
                        k->setCount(k->getCount() + 1);
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
                cout << pRoot->getKey() << " " << pRoot->getCount() << endl;
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

        void sumTree(Node *pRoot,int  &Sum) {
            if(pRoot != nullptr)
            {
                Sum += pRoot->getKey();
                sumTree(pRoot->getpLeft(), Sum);
                sumTree(pRoot->getpRight(), Sum);
            }
        }

        int maxTree(Node *pRoot) {
            if(pRoot->getpLeft() != nullptr) {
                maxTree(pRoot->getpRight());
            }
            else {
                return pRoot->getKey();
            }
        }

        int minTree(Node *pRoot) {
            if(pRoot->getpRight() != nullptr) {
                minTree(pRoot->getpLeft());
            }
            else {
                return pRoot->getKey();
            }
        }
        ~BST(){};
};

int main()
{
    BST a;

    return 0;
}
