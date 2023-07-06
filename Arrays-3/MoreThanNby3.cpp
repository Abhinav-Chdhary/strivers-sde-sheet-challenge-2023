//Brute will be to check each element using 2 loops O(n^2)
//Better is hashing
vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        vector<int> res;
        for(int i=0; i<nums.size(); i++){
            um[nums[i]]++;
        }
        int must = nums.size()/3;
        for(auto it : um){
            if(it.second>must)
                res.push_back(it.first);
        }
        return res;
    }
//Optimal is modification of Moore's voting algo
vector<int> majorityElement(vector<int>& nums) {
        int cand1 = INT_MIN, cand2 = INT_MIN;
        int c1 = 0, c2=0;
        for(int i = 0; i<nums.size(); i++){
            if(c1==0 && nums[i]!=cand2){
                c1=1; cand1 = nums[i];
            }
            else if(c2==0 && nums[i]!=cand1){
                c2=1; cand2 = nums[i];
            }
            else if(cand1==nums[i]) c1++;
            else if(cand2==nums[i]) c2++;
            else{
                c1--; c2--;
            }
        }
        vector<int> res;
        c1=0; c2=0;
        for(int i = 0; i<nums.size(); i++){
            if(cand1==nums[i]) c1++;
            else if(cand2==nums[i]) c2++;
        }
        int must = nums.size()/3+1;
        if(c1>=must) res.push_back(cand1);
        if(c2>=must) res.push_back(cand2);
        sort(res.begin(), res.end());
        return res;
    }