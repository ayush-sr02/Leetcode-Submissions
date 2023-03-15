//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    unordered_map<Node*,Node*> mp;
    
    Node* make_par(Node* root,int target){
        Node* t = new Node(-1);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* top = q.front();
            if(top->data==target) t=top;
            q.pop();
            if(top->left){
                mp[top->left] = top;
                q.push(top->left);
            }
            if(top->right){
                mp[top->right] = top;
                q.push(top->right);
            }
            
        }
        return t;
    }
  
    int minTime(Node* root, int target) {
        // Your code goes here
        
        Node* t=make_par(root,target);
        int ans=0;
        queue<Node*> q;
        q.push(t);
        unordered_map<Node*,int> vis;
        vis[t]=1;
        while(!q.empty()){
            int flag=0;
            int size = q.size();
            while(size--){
                Node* front = q.front();
                q.pop();
                if(mp.find(front)!=mp.end() and vis.find(mp[front])==vis.end()){
                    flag=1;
                    vis[mp[front]]=1;
                    q.push(mp[front]);
                }
                if(front->left and vis.find(front->left)==vis.end()){
                    flag=1;
                    vis[front->left]=1;
                    q.push(front->left);
                }
                if(front->right and vis.find(front->right)==vis.end()){
                    flag=1;
                    vis[front->right]=1;
                    q.push(front->right);
                }
                
            }
            if(flag) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends