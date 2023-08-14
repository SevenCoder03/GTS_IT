#include <iostream>
using namespace std;

class Node {
    private:
        int key;
        int height;
        Node *pLeft;
        Node *pRight;
    public:
        Node(){}

        Node (int key) {
            this->key = key;
            this->height = 1;
            this->pLeft = nullptr;
            this->pRight = nullptr;
        }

        Node* newNode(int key)
        {
            Node* node = new Node();
            node->key = key;
            node->pLeft = nullptr;
            node->pRight = nullptr;
            node->height = 1;

            return(node);
        }

        void setKey(int key) {
            this->key = key;
        }

        int getKey() {
            return key;
        }

        void setHeight(int height) {
            this->height = height;
        }

        int getHeight() {
            return height;
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

        ~Node(){};
};

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

        int calHeight(Node *p) {
            if(p == nullptr) {
                return 0;
            }
            return (1 + max(calHeight(p->getpLeft()), calHeight(p->getpRight())));
        }

        Node *rightRotate(Node *y) {
            Node *x = y->getpLeft();
            Node *T2 = x->getpRight();

            x->setpRight(y);
            y->setpLeft(T2);

            y->setHeight(max(calHeight(y->getpLeft()), calHeight(y->getpRight())) + 1);
            x->setHeight(max(calHeight(x->getpLeft()), calHeight(x->getpRight())) + 1);

            return x;
        }

        Node *leftRotate(Node *x) {
            Node *y = x->getpRight();
            Node *T2 = y->getpLeft();

            y->setpLeft(x);
            x->setpRight(T2);

            x->setHeight(max(calHeight(x->getpLeft()), calHeight(x->getpRight())) + 1);
            y->setHeight(max(calHeight(y->getpLeft()), calHeight(y->getpRight())) + 1);

            return y;
        }

        int getBalance(Node *N){
            if (N == nullptr)
                return 0;
            return calHeight(N->getpLeft()) - calHeight(N->getpRight());
        }

        Node* insertNode(Node* node, int key) {
            if (node == nullptr) {
                return(node->newNode(key));
            }
            if (key < node->getKey()) {
                node->setpLeft(insertNode(node->getpLeft(), key));
            }

            else if (key > node->getKey()) {
                node->setpRight(insertNode(node->getpRight(), key));
            }
            else {
                return node;
            }

            node->setHeight(1 + max(calHeight(node->getpLeft()), calHeight(node->getpRight())));

            int balance = getBalance(node);

            if (balance > 1 && key < node->getpLeft()->getKey()) {
                return rightRotate(node);
            }

            if (balance < -1 && key > node->getpRight()->getKey()) {
                return leftRotate(node);
            }

            if (balance > 1 && key > node->getpLeft()->getKey()) {
                node->setpLeft(leftRotate(node->getpLeft()));
                return rightRotate(node);
            }

            if (balance < -1 && key < node->getpRight()->getKey()) {
                node->setpRight(rightRotate(node->getpRight()));
                return leftRotate(node);
            }
            return node;
        }

        Node * minValueNode(Node* node) {
            Node* current = node;
            while (current->getpLeft() != NULL) {
                current = current->getpLeft();
            }
            return current;
        }

        Node* deleteNode(Node* pRoot, int key) {
            if (pRoot == nullptr) {
                return pRoot;
            }

            if (key < pRoot->getKey()) {
                pRoot->setpLeft(deleteNode(pRoot->getpLeft(), key));
            }
            else if( key > pRoot->getKey() ) {
                pRoot->setpRight(deleteNode(pRoot->getpRight(), key));
            }
            else {
                if((pRoot->getpLeft() == nullptr) || (pRoot->getpRight() == nullptr)) {
                    Node *temp = pRoot->getpLeft() ? pRoot->getpLeft() : pRoot->getpRight();

                    if (temp == nullptr) {
                        temp = pRoot;
                        pRoot = nullptr;
                    }
                    else {
                        *pRoot = *temp;
                    }
                    delete temp;
                }
                else {
                    Node* temp = minValueNode(pRoot->getpRight());
                    pRoot->setKey(temp->getKey());
                    pRoot->setpRight(deleteNode(pRoot->getpRight(), temp->getKey()));
                }
            }

            if (pRoot == nullptr) {
                return pRoot;
            }

            pRoot->setHeight(1 + max(calHeight(pRoot->getpLeft()), calHeight(pRoot->getpRight())));

            int balance = getBalance(pRoot);

            if (balance > 1 && getBalance(pRoot->getpLeft()) >= 0) {
                return rightRotate(pRoot);
            }

            if (balance > 1 && getBalance(pRoot->getpLeft()) < 0) {
                pRoot->setpLeft(leftRotate(pRoot->getpLeft()));
                return rightRotate(pRoot);
            }

            if (balance < -1 && getBalance(pRoot->getpRight()) <= 0) {
                return leftRotate(pRoot);
            }

            if (balance < -1 && getBalance(pRoot->getpRight()) > 0) {
                pRoot->setpRight(rightRotate(pRoot->getpRight()));
                return leftRotate(pRoot);
            }

            return pRoot;
        }

        void preOrder(Node *pRoot) {
            if(pRoot != nullptr) {
                cout << pRoot->getKey() << " ";
                preOrder(pRoot->getpLeft());
                preOrder(pRoot->getpRight());
            }
        }
        ~BST(){};
};

int main()
{
    BST a;
    a.setpRoot(a.insertNode(a.getpRoot(), 17));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 21));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 18));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 19));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 24));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(),28));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 13));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 16));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 20));
    a.preOrder(a.getpRoot());
    cout << endl;
    a.setpRoot(a.insertNode(a.getpRoot(), 15));
    a.preOrder(a.getpRoot());
    cout << endl;
    return 0;
}
