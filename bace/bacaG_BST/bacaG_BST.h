//Weronika Zygis
#define KEY_TYPE K
#define DATA_TYPE D
#define nullptr 0
//using namespace std;

template <typename K, typename D>
class BST {

    struct Node {
        K key;
        D data;
        Node* left;
        Node* right;

        Node(K key, D data) : key(key), data(data), left(nullptr), right(nullptr) {}

        void display(){
            cout << key << data;
        }

        void postOrder(){
            if (left) left->postOrder();
            if (right) right->postOrder();
            display();
        }
        void inOrder(){
            if (left) left->inOrder();
            display();
            if (right) right->inOrder();
        }

        void preOrder(){
            display();
            if (left) left->preOrder();
            if (right) right->preOrder();
        }

    };

    struct Queue {
        struct qNode {
            Node* node;
            qNode* next;

            qNode(Node* node) : node(node), next(nullptr) {}
        };

        qNode* front;
        qNode* back;

        Queue() : front(nullptr), back(nullptr) {}

        ~Queue(){
            while (front){
                qNode* toDelete = front;
                front = front->next;
                delete toDelete;
            }
        }

        void push(Node* node) {
            qNode* newNode = new qNode(node);
            if (back) back->next = newNode;
            back = newNode;
            if (!front) front = back;
        }

        Node* pop() {
            if (!front) return nullptr;
            Node* frontNode = front->node;
            qNode* prevFront = front;
            front = front->next;
            if (!front) back = nullptr;
            delete prevFront;
            return frontNode;
        }

        bool empty() {
            return front == nullptr;
        }
    };

    Node *root; //holding the root

    bool insert(Node*& node, K key, D data) {
        if (!node) {
            node = new Node(key, data);
            return true;
        }

        //smaller on the left, bigger on the right
        else if (key < node->key) return insert(node->left, key, data);
        else if (node->key < key) return insert(node->right, key, data);
        else return false; //key == node key - already such a key
    }

    bool del(Node*& node, K key) {
        if (!node) return false;

        if (key < node->key) return del(node->left, key);
        else if (node->key < key) return del(node->right, key);

        else { //key = node.key
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                node = temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                node = temp;
            }
            else { //has both kids: replaces with following (acc to key) node
                Node* temp = leftestNode(node->right);
                node->key = temp->key;
                node->data = temp->data;
                return del(node->right, temp->key);
            }
            return true;
        }
    }


    Node* leftestNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    D* search(Node* node, K key) { //smaller on the left, bigger on the right side
        if (node == nullptr) return nullptr;
        else if (key < node->key) return search(node->left, key);
        else if (node->key < key) return search(node->right, key);
        else return &node->data;
    }

    Node* searchNode(Node* node, K key) { //smaller on the left, bigger on the right side
        if (node == nullptr) return nullptr;
        else if (key < node->key) return searchNode(node->left, key);
        else if (node->key < key) return searchNode(node->right, key);
        else return node;
    }

    int height(Node* node){ //recursively - the max of left and right subtree
        if (!node) return -1;
        int l = height(node->left);
        int r = height(node->right);
        return max(l, r) + 1;
    }

    void levelOrder(Node* node) {
            if (node == nullptr) return;

            Queue q;
            q.push(node);

            while (!q.empty()) { //take off the current top (&display) and push its children
                Node* current = q.pop();
                current->display();
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
    }

    void destructor(Node* node){ //postorder - subtrees first
        if (!node) return;
        destructor(node->left);
        destructor(node->right);
        delete node;
    }


public:
    BST() : root(nullptr) {}

    ~BST(){ destructor(root); }

    bool Insert(K key, D data) { // insertion successful - true, else false
        return insert(root, key, data);
    }

    D* Search(K key){ //returns the address of key or null
        return search(root, key);
    }

    bool Delete(K key){
        return del(root, key);
    }

    void PreOrder(){
        if (!root) return;
        root->preOrder();
    }

    void InOrder(){
        if (!root) return;
       root->inOrder();
    }

    void PostOrder(){
        if (!root) return;
        root->postOrder();
    }


    void LevelOrder(){
        if(!root) return;
        levelOrder(root);
    }


    int Height(){
        return height(root);
    }

};


