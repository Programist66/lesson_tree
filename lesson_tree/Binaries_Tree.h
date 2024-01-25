template <class T>
class BinaryTree;

template <typename T>
class TreeNode 
{
    private:
        T data;
        TreeNode* left;
        TreeNode* right;
        friend class BinaryTree<T>;
    public:
        TreeNode(T value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree 
{
    private:
        TreeNode<T>* deleteRec(TreeNode<T>* root, T key) 
        {
            if (root == nullptr) return root;

            if (key < root -> data) 
            {
                root-> left = deleteRec(root->left, key);
            }
            else if (key > root->data)
            {
                root-> right = deleteRec(root->right, key);
            }
            else 
            {
                if (root-> left == nullptr) return root->right;
                else if (root -> right == nullptr) return root->left;

                root-> data = minValue(root->right);

                root-> right = deleteRec(root->right, root->data);
            }
            return root;
        }

        T minValue(TreeNode<T>* root)
        {
            T minValue = root->data;
            while (root->left != nullptr)
            {
                minValue = root->left->data;
                root = root->left;
            }
            return minValue;
        }

    public:
        TreeNode<T>* root;

        BinaryTree() : root(nullptr) {}

        void insert(T value) 
        {
            if (root == nullptr) 
            {
                root = new TreeNode<T>(value);
            }
            else 
            {
                insert(root, value);
            }
        }

        void insert(TreeNode<T>* currentNode, T value) 
        {
            if (value < currentNode->data) {
                if (currentNode->left == nullptr) {
                    currentNode->left = new TreeNode<T>(value);
                }
                else {
                    insert(currentNode->left, value);
                }
            }
            else {
                if (currentNode->right == nullptr) {
                    currentNode->right = new TreeNode<T>(value);
                }
                else {
                    insert(currentNode->right, value);
                }
            }
        }

        void remove(T key) 
        {
            root = deleteRec(root, key);
        }

        

        void printIndent(int level) 
        {
            for (int i = 0; i < level; i++) 
            {
                std::cout << "    ";
            }
        }

        void Print(TreeNode<T>* node, int level = 0)
        {
            if (node != nullptr) 
            {
                Print(node->right, level + 1);
                printIndent(level);
                std::cout << node->data << std::endl;
                Print(node->left, level + 1);
            }
        }

        void Print()
        {
            Print(root);
        }
};