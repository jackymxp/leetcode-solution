#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
int val;
TreeNode *left,*right;
TreeNode() : left(nullptr),right(nullptr) {}
TreeNode(const int& value) :val(value),left(nullptr),right(nullptr) {}
TreeNode(const TreeNode*& tr) : val(tr->val), left(tr->left), right(tr->right){}
friend ostream& operator<<(ostream& os, TreeNode& l);
// stack-abusing recursion everywhere, for small code
~TreeNode() { delete left; delete right; }
int max_depth() const {
    const int left_depth = left ? left->max_depth() : 0;
    const int right_depth = right ? right->max_depth() : 0;
    return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
};
class DisTree {

    TreeNode *root;

public:
    DisTree(TreeNode* _root) : root(_root) 
    {
        Dump();
        cout << "\n\n";
        clear();
    }
    ~DisTree() { delete root; }

    int get_max_depth() const { return root ? root->max_depth() : 0; }
    void clear() { delete root; root = nullptr; }

    struct cell_display {
        string   valstr;
        bool     present;
        cell_display() : present(false) {}
        cell_display(std::string valstr) : valstr(valstr), present(true) {}
    };

    using display_rows = vector< vector< cell_display > >;

    // The text tree generation code below is all iterative, to avoid stack faults.

    // get_row_display builds a vector of vectors of cell_display structs
    // each vector of cell_display structs represents one row, starting at the root
    display_rows get_row_display() const {
        // start off by traversing the tree to
        // build a vector of vectors of TreeNode pointers
        vector<TreeNode*> traversal_stack;
        vector< std::vector<TreeNode*> > rows;
        if(!root) return display_rows();

        TreeNode *p = root;
        const int max_depth = root->max_depth();
        rows.resize(max_depth);
        int depth = 0;
        for(;;) {
            // Max-depth TreeNodes are always a leaf or null
            // This special case blocks deeper traversal
            if(depth == max_depth-1) {
                rows[depth].push_back(p);
                if(depth == 0) break;
                --depth;
                continue;
            }

            // First visit to node?  Go to left child.
            if(traversal_stack.size() == depth) {
                rows[depth].push_back(p);
                traversal_stack.push_back(p);
                if(p) p = p->left;
                ++depth;
                continue;
            }

            // Odd child count? Go to right child.
            if(rows[depth+1].size() % 2) {
                p = traversal_stack.back();
                if(p) p = p->right;
                ++depth;
                continue;
            }

            // Time to leave if we get here

            // Exit loop if this is the root
            if(depth == 0) break;

            traversal_stack.pop_back();
            p = traversal_stack.back();
            --depth;
        }

        // Use rows of TreeNode pointers to populate rows of cell_display structs.
        // All possible slots in the tree get a cell_display struct,
        // so if there is no actual TreeNode at a struct's location,
        // its boolean "present" field is set to false.
        // The struct also contains a string representation of
        // its TreeNode's value, created using a std::stringstream object.
        display_rows rows_disp;
        std::stringstream ss;
        for(const auto& row : rows) {
            rows_disp.emplace_back();
            for(TreeNode* pn : row) {
                if(pn) {
                    ss << pn->val;
                    rows_disp.back().push_back(cell_display(ss.str()));
                    ss = std::stringstream();
                } else {
                    rows_disp.back().push_back(cell_display());
        }   }   }
        return rows_disp;
    }

    // row_formatter takes the vector of rows of cell_display structs 
    // generated by get_row_display and formats it into a test representation
    // as a vector of strings
    vector<string> row_formatter(const display_rows& rows_disp) const {
        using s_t = string::size_type;

        // First find the maximum value string length and put it in cell_width
        s_t cell_width = 0;
        for(const auto& row_disp : rows_disp) {
            for(const auto& cd : row_disp) {
                if(cd.present && cd.valstr.length() > cell_width) {
                    cell_width = cd.valstr.length();
        }   }   }

        // make sure the cell_width is an odd number
        if(cell_width % 2 == 0) ++cell_width;

        // formatted_rows will hold the results
        vector<string> formatted_rows;

        // some of these counting variables are related,
        // so its should be possible to eliminate some of them.
        s_t row_count = rows_disp.size();

        // this row's element count, a power of two
        s_t row_elem_count = 1 << (row_count-1);

        // left_pad holds the number of space charactes at the beginning of the bottom row
        s_t left_pad = 0;

        // Work from the level of maximum depth, up to the root
        // ("formatted_rows" will need to be reversed when done) 
        for(s_t r=0; r<row_count; ++r) {
            const auto& cd_row = rows_disp[row_count-r-1]; // r reverse-indexes the row
            // "space" will be the number of rows of slashes needed to get
            // from this row to the next.  It is also used to determine other
            // text offsets.
            s_t space = (s_t(1) << r) * (cell_width + 1) / 2 - 1;
            // "row" holds the line of text currently being assembled
            string row;
            // iterate over each element in this row
            for(s_t c=0; c<row_elem_count; ++c) {
                // add padding, more when this is not the leftmost element
                row += string(c ? left_pad*2+1 : left_pad, ' ');
                if(cd_row[c].present) {
                    // This position corresponds to an existing TreeNode
                    const string& valstr = cd_row[c].valstr;
                    // Try to pad the left and right sides of the value string
                    // with the same number of spaces.  If padding requires an
                    // odd number of spaces, right-sided children get the longer
                    // padding on the right side, while left-sided children
                    // get it on the left side.
                    s_t long_padding = cell_width - valstr.length();
                    s_t short_padding = long_padding / 2;
                    long_padding -= short_padding;
                    row += string(c%2 ? short_padding : long_padding, ' ');
                    row += valstr;
                    row += string(c%2 ? long_padding : short_padding, ' ');
                } else {
                    // This position is empty, TreeNodeless...
                    row += string(cell_width, ' ');
                }
            }
            // A row of spaced-apart value strings is ready, add it to the result vector
            formatted_rows.push_back(row);

            // The root has been added, so this loop is finsished
            if(row_elem_count == 1) break;

            // Add rows of forward- and back- slash characters, spaced apart
            // to "connect" two rows' TreeNode value strings.
            // The "space" variable counts the number of rows needed here.
            s_t left_space  = space + 1;
            s_t right_space = space - 1;
            for(s_t sr=0; sr<space; ++sr) {
                string row;
                for(s_t c=0; c<row_elem_count; ++c) {
                    if(c % 2 == 0) {
                        row += string(c ? left_space*2 + 1 : left_space, ' ');
                        row += cd_row[c].present ? '/' : ' ';
                        row += string(right_space + 1, ' ');
                    } else {
                        row += string(right_space, ' ');
                        row += cd_row[c].present ? '\\' : ' ';
                    }
                }
                formatted_rows.push_back(row);
                ++left_space;
                --right_space;
            }
            left_pad += space + 1;
            row_elem_count /= 2;
        }

        // Reverse the result, placing the root node at the beginning (top)
        std::reverse(formatted_rows.begin(), formatted_rows.end());

        return formatted_rows;
    }

    // Trims an equal number of space characters from
    // the beginning of each string in the vector.
    // At least one string in the vector will end up beginning
    // with no space characters.
    static void trim_rows_left(vector<string>& rows) {
        if(!rows.size()) return;
        auto min_space = rows.front().length();
        for(const auto& row : rows) {
            auto i = row.find_first_not_of(' ');
            if(i==string::npos) i = row.length();
            if(i == 0) return;
            if(i < min_space) min_space = i;
        }
        for(auto& row : rows) {
            row.erase(0, min_space);
    }   }

    // Dumps a representation of the tree to cout
    void Dump() const {
        const int d = get_max_depth();

        // If this tree is empty, tell someone
        if(d == 0) {
            cout << " <empty tree>\n";
            return;
        }

        // This tree is not empty, so get a list of node values...
        const auto rows_disp = get_row_display();
        // then format these into a text representation...
        auto formatted_rows = row_formatter(rows_disp);
        // then trim excess space characters from the left sides of the text...
        trim_rows_left(formatted_rows);
        // then dump the text to cout.
        for(const auto& row : formatted_rows) {
            std::cout << ' ' << row << '\n';
        }
    }
};

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


ostream& operator<<(ostream& os, TreeNode& l)
{
    os << l.val ;
    return os;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    if(len == 0)
        return NULL;
    int mid = len / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin()+mid+1, nums.end());
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}



void preOrder(TreeNode* root)
{
    if(!root)
        return ;
    cout << root->val << "-->" ;
    preOrder(root->left);
    preOrder(root->right); 
}

void inOrder(TreeNode* root)
{
    if(!root)
        return ;
    inOrder(root->left); 
    cout << root->val << "-->" ;
    inOrder(root->right);
}

void postOrder(TreeNode* root)
{
    if(!root)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << "-->" ;
}


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(res.size() == p.second)
            res.push_back(vector<int>());
        res[p.second].push_back(p.first->val);
        if(p.first->left)   q.push(make_pair(p.first->left, p.second+1));
        if(p.first->right)   q.push(make_pair(p.first->right, p.second+1));
    }
    return res;
}






void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}
#endif /* TREE_NODE_H */
