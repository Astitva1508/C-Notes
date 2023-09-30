#include <bits/stdc++.h>
using namespace std;

class HuffManNode{
    public:
    char c;
    HuffManNode *left;
    HuffManNode *right;
    int freq;
    string encode;
    HuffManNode(char x,int f,HuffManNode *l,HuffManNode*r){
        this->c=x;
        this->left=l;
        this->right = r;
        this->freq = f;
        this->encode="";
    }
};

class Compare
{
public:
    bool operator()(HuffManNode *p1, HuffManNode *p2)
    {
        return (p1->freq > p2->freq);
    }
};

class HuffManCode{
    public:
    string s;
    HuffManNode *root;
    unordered_map<char,string> enCoder;
    unordered_map<string,char>deCoder;
    HuffManCode(string s){
        this->s= s;
        this->root=nullptr;
    }

    void constructTree(){
        unordered_map<char, int> freq;
        for (auto &it : s)
            freq[it]++;
        priority_queue<HuffManNode *, vector<HuffManNode *>, Compare> pq;
        for (auto &it : freq)
        {
            pq.push(new HuffManNode(it.first, it.second, nullptr, nullptr));
        }
        while (pq.size() > 1)
        {
            HuffManNode *l = pq.top();
            pq.pop();
            HuffManNode *r = pq.top();
            pq.pop();
            pq.push(new HuffManNode('~', l->freq + r->freq, l, r));
        }
        this->root = pq.top();
    }

    string enCode(){
        constructTree();
        inorder(root);
        string ans;
        for(auto &it:s){
            ans+=(enCoder[it]);
        }
        return ans;
    }

    void inorder(HuffManNode *root){
        if(root==nullptr) return;
        if(root->c!='~') enCoder[root->c]=root->encode;
        if(root->c!='~') deCoder[root->encode]=root->c;
        if(root->left)  root->left->encode=root->encode+'0';
        inorder(root->left);
        if(root->right) root->right->encode=root->encode+'1';
        inorder(root->right);
    }

    string decode(string encodedString){
        string decodedString;
        string ss;
        for(int i=0;i<encodedString.size();i++){
            ss+=encodedString[i];
            if(deCoder.find(ss)!=deCoder.end()){
                decodedString+=deCoder[ss];
                ss="";
            }
        }
        return decodedString;
    }
};

int main(){
    HuffManCode* hc = new HuffManCode("aaabbc");
    cout<<hc->enCode();
    return 0;
}