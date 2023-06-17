//t.c O(1)
int findMinimumCoins(int amount) 
{
    int coins = 0, i=0;
    vector<int> denom = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    while(amount>0 && i<9){
        if(amount>=denom[i]){
            coins+=amount/denom[i];
            amount%=denom[i];
        }
        i++;
    }
    return coins;
}