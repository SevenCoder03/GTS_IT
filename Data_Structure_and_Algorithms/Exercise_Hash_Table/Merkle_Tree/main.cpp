#include<bits/stdc++.h>
#include <merklecpp>
#include <conio.h>
using namespace std;

/* determines the maximum capacity of Hash Tree */
int maxim = 10;

/* determines the number of elements present in Hash Tree */
int size = 0;

/* node for storing an item in a Binary Tree */
struct node
{
    int key;
    int value;
    struct node *left;
    struct node *right;
};

/* for storing a Binary Tree at each index of Hash Tree */
struct bst
{
  /* head pointing to the root of Binary Tree */
    struct node *head;
};

bst *arr;

/* this function inserts the newly created node
   in the existing Binary Tree */
void insert_element(node *tree, node *item)
{
    if (item->key < tree->key) {
        if (tree->left == nullptr) {
            tree->left = item;
            return;
        }
        else {
            insert_element(tree->left, item);
            return;
        }
    }
    else if (item->key > tree->key) {
        if (tree->right == nullptr) {
            tree->right = item;
            return;
        }
        else {
            insert_element(tree->right, item);
            return;
        }
    }
}

/*
 * this function finds the given key in the Binary Tree
 * returns the node containing the key
 * returns nullptr in case key is not present
 */
node* find(node *tree, int key)
{
    if (tree == nullptr) {
        return nullptr;
    }
    if (tree->key == key) {
        return tree;
    }
    else if (key < tree->key) {
        return find(tree->left, key);
    }
    else {
        return find(tree->right, key);
    }
}

/* this function creates an index corresponding
   to the every given key */
int hashcode(int key)
{
    return (key % maxim);
}

void add(int key, int value)
{
    int index = hashcode(key);

    /* extracting Binary Tree at the given index */
    struct node *tree = (node*) arr[index].head;

    /* creating an item to insert in the hashTree */
    struct node *new_item = (node*) malloc(sizeof(node));

    new_item->key = key;
    new_item->value = value;
    new_item->left = nullptr;
    new_item->right = nullptr;

    if (tree == nullptr){
        /* absence of Binary Tree at a given index of Hash Tree */
        cout << "\n\t\t\t\t\tInserting " << key << " and " << value << endl;
        arr[index].head = new_item;
        size++;
    }
    else {
        /* a Binary Tree is present at given index of Hash Tree */
        node *temp = find(tree, key);
        if (temp == nullptr) {
            /*
            * Key not found in existing Binary Tree
            * Adding the key in existing Binary Tree
            */
            cout << "\n\t\t\t\t\tInserting " << key << " and " << value << endl;
            insert_element(tree, new_item);
            size++;
        }
        else {
            /*
            * Key already present in existing Binary Tree
            * Updating the value of already existing key
            */
            temp->value = value;
        }
    }
}

/* displays content of binary tree of
particular index */
void display_tree(node *tree)
{
    if (tree == nullptr) {
        return;
    }
    cout << "\t\t\t\t\t" << tree->key << " and " << tree->value << "   \n";
    if (tree->left != nullptr) {
        display_tree(tree->left);
    }
    if (tree->right != nullptr) {
        display_tree(tree->right);
    }
}

/* displays the content of hash Tree */
void display()
{
    int i = 0;
    for(i = 0; i < maxim; i++) {
        node *tree = arr[i].head;
        if (tree == nullptr) {
            cout << "\n\t\t\t\t\tarr[" << i << "] has no elements" << endl;
        }
        else {
            cout << "\n\t\t\t\t\tarr[" << i << "] has elements" << endl;
            display_tree(tree);
        }
    }
}

/* for initializing the hash Tree */
void init()
{
    for(int i = 0; i < maxim; i++) {
        arr[i].head = nullptr;
    }
}

/* returns the size of hash Tree */
int size_of_hashTree()
{
    return size;
}

node* remove_element(node *tree, int key)
{
    if (tree == nullptr) {
        return nullptr;
    }

    if (key < tree->key) {
        tree->left = remove_element(tree->left, key);
        return tree;
    }
    else if (key > tree->key) {
        tree->right = remove_element(tree->right, key);
        return tree;
    }
    else {
    /* reached the node */
        if (tree->left == nullptr  &&  tree->right == nullptr) {
            size--;
            return tree->left;
        }
        else if (tree->left != nullptr  &&  tree->right == nullptr) {
            size--;
            return tree->left;
        }
        else if (tree->left == nullptr  &&  tree->right != nullptr) {
            size--;
            return tree->right;
        }
        else {
            node *left_one = tree->left;
            while (left_one->right != nullptr) {
                left_one = left_one->right;
            }
            tree->key = left_one->key;
            tree->value = left_one->value;
            tree->left = remove_element(tree->left, tree->key);
            return tree;
        }
    }
}

/* to del a key from hash Tree */
void del(int key)
{
    int index = hashcode(key);
    node *tree = (node*)arr[index].head;
    if (tree == nullptr) {
        cout << key << "\n\t\t\t\t\tKey not present" << endl;
    }
    else {
        node *temp = find(tree, key);
        if (temp == nullptr) {
            cout << "\n\t\t\t\t\t" << key << " is not present";
        }
        else {
            tree = remove_element(tree, key);
            cout << "\n\t\t\t\t\t" << key << " has been removed form the hash tree" << endl;
        }
    }
}

void menu() {
    system("cls");
    cout << "\n\t\t\t\t              IMPLEMENTATION OF HASH TREE\n";
    cout << "\n\t\t\t\t+------------------------MENU------------------------+";
    cout << "\n\t\t\t\t|       1. Insert an item in the Hash Tree           |";
    cout << "\n\t\t\t\t|       2. Remove an item from the Hash Tree         |";
    cout << "\n\t\t\t\t|       3. Check the size of Hash Tree               |";
    cout << "\n\t\t\t\t|       4. Display Hash Tree                         |";
    cout << "\n\t\t\t\t|       0. Exit                                      |";
    cout << "\n\t\t\t\t+----------------------------------------------------+";
}

int main()
{
    int choice, key, value, n, c;
    arr = (bst*)malloc(maxim *sizeof(bst*));
    init();
    while(choice) {
        menu();
        cout << "\n\t\t\t\t\t\tEnter choice: ";
        cin >> choice;
        switch(choice) {
            case 0:
                break;
            case 1:
                cout << "\n\t\t\t\t\tInserting element in Hash Tree" << endl;
                cout << "\n\t\t\t\t\tEnter key: ";
                cin >> key;
                cout << "\n\t\t\t\t\tEnter value: ";
                cin >> value;
                add(key, value);
                cout << "\n\t\t\t\t[ANOUNCEMENT]: Press any key to return to MENU . . .";
                getch();
                break;

            case 2:
                cout << "\n\t\t\t\t\tDeleting item from Hash Tree \n\t\t\t\t\t Enter the key to delete: ";
                cin >> key;
                del(key);
                cout << "\n\t\t\t\t[ANOUNCEMENT]: Press any key to return to MENU . . .";
                getch();
                break;

            case 3:
                n = size_of_hashTree();
                cout << "\n\t\t\t\t\t    Size of Hash Tree is:" << n << endl;
                cout << "\n\t\t\t\t[ANOUNCEMENT]: Press any key to return to MENU . . .";
                getch();
                break;

            case 4:
                display();
                cout << "\n\t\t\t\t[ANOUNCEMENT]: Press any key to return to MENU . . .";
                getch();
                break;

            default:
                cout << "\n\t\t\t\t\tWrong Input" << endl;
                cout << "\n\t\t\t\t[ANOUNCEMENT]: Press any key to return to MENU . . .";
                getch();
        }
    }
    return 0;
}
