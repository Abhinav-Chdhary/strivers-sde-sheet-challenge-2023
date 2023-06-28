//I came up with this on my own I could not find anything better
//t.c->O(n^2) ->for every value we might remake the stack in worst case
//s.c->O(n) ->recursion
void mySort(stack<int>& st, int x){
    if(st.empty() || st.top()<x){
        st.push(x);
        return;
    }
    int t = st.top();
    st.pop();
    mySort(st, x);
    st.push(t);
}
void sortStack(stack<int> &s)
{
	if(!s.empty()){
        int a = s.top();
        s.pop();
        sortStack(s);
        mySort(s, a);
    }
}