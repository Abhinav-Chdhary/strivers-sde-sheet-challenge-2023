 bool isValid(string s) {
        stack<char> brac;
        for(int i=0; i<s.length(); i++){
            char ch = s.at(i);
            if(ch!=')' && ch!='}' && ch!=']')
                brac.push(ch);
            else{
                if(brac.empty() || (brac.top()=='(' && ch!=')') || (brac.top()=='[' && ch!=']') || (brac.top()=='{' && ch!='}'))
                    return false;
                brac.pop();
            }
        }
        return brac.empty();
    }