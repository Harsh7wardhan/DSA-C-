class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    void inOrder(Node *root, vector<int> &nums)
    {

        if (root)
        {

            inOrder(root->left, nums);

            nums.push_back(root->data);

            inOrder(root->right, nums);
        }
    }

    bool isBST(Node *root)

    {

        // Your code here

        vector<int> nums;

        if (root == NULL)
        {

            return 1;
        }

        inOrder(root, nums);

        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i] > nums[i + 1])
            {

                return 0;
            }
        }

        return 1;
    }
};

// 2

class Solution
{
public:
    // Function to check whether a Binary Tree is BST or not.
    bool isValidBST(Node *root, int min, int max)
    {

        if (root == NULL)
        { // base conditon

            return true;
        }

        bool left = isValidBST(root->left, min, root->data);

        bool right = isValidBST(root->right, root->data, max);

        bool cond = (root->data < max) && (root->data > min);

        return left && right && cond;
    }

    bool isBST(Node *root)

    {

        return isValidBST(root, INT_MIN, INT_MAX);
    }
};