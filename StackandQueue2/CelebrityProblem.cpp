//Brute
int findCelebrity(int n) {
	int candi=-1;
	for(int i=0; i<n; i++){
		 int cnt=0;
		 for(int j=0; j<n; j++){
			 if(j!=i && knows(i, j))
			 	cnt++;//if i knows j then increment
		 }
		 //if i does not any one then this is our potential candidate
		 if(cnt==0)
		 	candi = i;
	}
	int cnt=0;
		 for(int j=0; j<n; j++){

			 if(j!=candi && knows(j, candi) ){
				 cnt++;
			 }
		 }
		 if(cnt==n-1) return candi;
	 return -1;
}
//Better
int findCelebrity(int n) {
	int candi=-1;
	stack<int> stk;
	for(int i=0; i<n; i++){
		stk.push(i);
	}
	while(stk.size()>1){
		int a = stk.top();
		stk.pop();
		int b = stk.top();
		stk.pop();

		if(knows(a, b))
			stk.push(b);
		else
			stk.push(a);
	}
	candi = stk.top();
	for(int i=0; i<n; i++){
		if(i!=candi){
			if(knows(candi, i))
				return -1;
			if(!knows(i, candi)) return -1;
		}
	}
	return candi;
}