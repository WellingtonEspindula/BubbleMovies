#include "../../header/datastructures/tst.h"

#define MAX_LEN 1024

TST::TST() {
    this->size = 0;
    this->root = NULL;
}

Node* Insert_Movie(Node* root, string str, int id, int d){
    if (root == NULL){
        root = new Node();

        //Insert first character of string in the root node
        root->character = str.at(d);
        root->id = -1;
        root->left = root->eq = root->right = NULL;
    }

    //Checks if the character's value is greater than the value stored in this node
    if(str.at(d)  < root->character)
        root->left = Insert_Movie(root->left, str, id, d);

    //Checks if the character's value is equal to the one stored in this node
    else if (str.at(d) == root->character){
        //Checks if the string has ended
        if (d < (str.length() - 1))
            root->eq = Insert_Movie(root->eq, str, id, d+1);
        else
            root->id = id;
    }

    //In this instance the character's value is greater than the value stored in this node
    else
        root->right = Insert_Movie(root->right, str, id, d);
    return root;
}


bool TST::insert(string str, int id) {
    str = clear_string(str);

    if (str.empty()){
        return false;
    }
    if (!exists(str)){  // verify if this element already exists in the tst
        size++;
    }

    this->root = Insert_Movie(this->root, str, id, 0);
    return true;
}


int Search_For(Node *root, string word) {
    int d = 0;
    while (root != NULL) {
        //Searches for the character in the tree
        //Checks if the character's value is greater than the value stored in this node
        if (word.at(d) < root->character){
            root = root->left;
        } else if (word.at(d) == root->character) {
            //If end of string flag is found and the word length is also exhausted,
            //we can safely say that the word is present in the TST
            if (d == (word.length() - 1))
                return root->id;
            d++;
            root = root->eq;
        } else {
            root = root->right;
        }
    }
    return -1;
}


void Aux_Function(Node *root, char *buffer, int depth) {
    if (root) {
        // Traverse the left subtree
        Aux_Function(root->left, buffer, depth);

        buffer[depth] = root->character;
        //Once end of string flag is encountered, print the string
        if (root->id != -1) {
            buffer[depth + 1] = '\0';
            cout << buffer << ":" << root->id << endl;
        }

        // Traverse the middle subtree
        Aux_Function(root->eq, buffer, depth + 1);

        // Traverse the right subtree
        Aux_Function(root->right, buffer, depth);
    }
}


// Function to print TST's strings
void TST::show() {
    char buffer[MAX_LEN];
    Aux_Function(this->root, buffer, 0);
}

// Function to print TST status
void TST::show_info() {
    cout << "\n" << endl;
    cout << "-------------------------" << endl;
    cout << "TST size: " << size << endl;
    cout << "-------------------------" << endl;
}

bool TST::exists(string str) {
    str = clear_string(str);
    return (Search_For(this->root, str) != -1);
}

int TST::get(string str){
    str = clear_string(str);
    return Search_For(this->root, str);
}