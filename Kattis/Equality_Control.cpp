#include<bits/stdc++.h>
using namespace std;

struct Node{
  string type;
  Node *l, *r, *v;
  list<int> ls;

  ~Node(){
    if(l!=nullptr)
      delete l;
    if(r!=nullptr)
      delete r;
    if(v!=nullptr)
      delete v;
  }

};

Node* shuf(Node *v) {
  return new Node{"shuf", nullptr, nullptr, move(v)};
}

Node* sort(Node *v) {
  return new Node{"sort", nullptr, nullptr, move(v)};
}

Node* ls(list<int> v) {
  return new Node{"list", nullptr, nullptr, nullptr, move(v)};
}

Node* cat(Node *l, Node *r) {
  return new Node{"cat", l, r};
}

bool allEq(list<int> &l){
  for(int v : l)
    if(v!=l.front())
      return false;
  return true;
}

Node* parse(string &s) {
  int i = 0;
  stack<string> fst;
  stack<Node*> vst;
  while(i < s.size()){
    if(s[i] >= 'a' && s[i] <= 'z'){
      string o = "";
      while(s[i] >= 'a' && s[i] <= 'z'){
        o+=s[i];
        i+=1;
      }
      i+=1; //consume (
      fst.push(o);
    }else if(s[i] == ')') {
      i+=1;
      string c = fst.top();fst.pop();

      if(c=="concat"){
        auto r = vst.top();vst.pop();
        auto l = vst.top();vst.pop();

        vst.push(cat(l,r));
      }else if(c=="shuffle"){

        auto v = vst.top();vst.pop();

        if(v->type=="list" && allEq(v->ls))
          vst.push(v);
        else
          vst.push(shuf(v));
      }else if(c=="sorted"){
        auto v = vst.top(); vst.pop();
        vst.push(sort(v));
      }
    } else if(s[i] == '['){
      ++i;
      list<int> o;
      while(s[i] != ']'){
        int a = 0;
        while(s[i] >= '0' && s[i] <= '9'){
          a = 10*a + (s[i]-'0');
          ++i;
        }
        if(a)
          o.push_back(a);
        if(s[i]==',')
          ++i;
      }
      vst.push(ls(o));
    } else {
      i+=1;
    }
  }
  assert(vst.size()==1);
  return vst.top();
}

Node* pr(Node * t){
  cout << t->type << endl;
  if(t->l)
    pr(t->l);
  if(t->r)
    pr(t->r);
  if(t->v)
    pr(t->v);
  if(!t->ls.empty()){
    for(int v : t->ls)
      cout << v << ',';
    cout << endl;
  }
  return t;
}

Node* comp(Node* t){
  stack<Node*> st;
  st.push(t);
  stack<Node* > vst;
  while(!st.empty()){
    auto v = st.top();
    if(v->type == "list"){
      vst.push(v); //osort?
      st.pop();
    }
    else if(v->type=="cat"){
      if(v->l != nullptr){
        st.push(v->l);
        v->l = nullptr;
      }
      else if(v->r != nullptr){
        st.push(v->r);
        v->r=nullptr;
      }
      else{
        auto r = vst.top(); vst.pop();

        vst.top()->ls.splice(vst.top()->ls.end(), r->ls);

        st.pop();
      }
    }
    else {
      auto r = v->v;
      st.pop();
      st.push(r);
    }
  }

  assert(vst.size()==1);
  return vst.top();
}

Node* osort(Node *v){
  if(v->type != "list")
    return v;
  v->ls.sort();
  return v;
}

Node* ev(Node * v) {
  stack<Node*> st;
  st.push(v);
  stack<Node*> vst;
  while(!st.empty()){
    auto t = st.top();
    string n = t->type;
    if(n == "list"){
      vst.push(t);
      st.pop();
    }
    if(n == "cat"){
      if(t->l != nullptr){
        st.push(t->l);
        t->l=nullptr;
      }else if(t->r != nullptr){
        st.push(t->r);
        t->r=nullptr;
      } else {
        auto r = vst.top();vst.pop();
        auto l = vst.top();vst.pop();
        vst.push(cat(l, r));
        st.pop();
      }
    }
    if(n == "shuf"){
      vst.push(shuf(comp(t->v)));
      st.pop();
    }
    if(n == "sort"){
      vst.push(osort(comp(t->v)));
      st.pop();
    }
  }
  assert(vst.size()==1);
  return vst.top();
}

list<int> gen(Node* v) {
  stack<Node*> st;
  st.push(v);
  list<int> l;
  while(!st.empty()){
    auto t = st.top();
    string n = t->type;
    if(n == "list"){
      l.splice(l.end(), t->ls);
      st.pop();
    }
    else if(n=="cat"){
      if(t->l != nullptr){
        st.push(t->l);
        t->l = nullptr;
      } else if(t->r != nullptr){
        auto r = t->r;
        st.pop();
        st.push(r);
      }
    }
    else if(n=="shuf") {
      l.push_back(-1);
      l.splice(l.end(), osort(t->v)->ls);
      l.push_back(-1);
      st.pop();
    }
  }
  return l;
}

int main(){
  string s1,s2;
  getline(cin,s1);
  getline(cin,s2);
  auto p = gen(ev(parse(s1)));
  auto q = gen(ev(parse(s2)));
  if(p==q)
    puts("equal");
  else
    puts("not equal");
  return 0;
}
