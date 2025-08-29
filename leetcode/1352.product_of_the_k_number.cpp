class ProductOfNumbers {
public:
vector<int>prifix;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
    if(num == 0){
        prifix.clear();
    }
    else
    if(prifix.empty()){
        prifix.push_back(num);
    }
    else{
        prifix.push_back(prifix.back()*num);
    }
        
    }
    
    int getProduct(int k) {
        if(k>prifix.size()) return 0;
        if(k == prifix.size()) return prifix.back();
        return prifix.back() / prifix[prifix.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
