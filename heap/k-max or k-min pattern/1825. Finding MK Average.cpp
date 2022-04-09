/*
ek tareeka hei ki we can maintain a m size ka vector + 3 ordered multiset then jab tk vector bhar nhi jata tb tk values ko add krte 
rahenge and jaise hi vector bhar jayega tb aapn us index ki value ko phle remove krenge(dhyan rahe ki wo 3 multiset bhi update krne pdenge)
then value ko us index mei update krdenge in between which 3 multiset bhi update honge

key take aways
auto it=left.rbegin();
left.erase(it)

ye nhi chal raha 

auto it=prev(end(left))
left.erase(it)
ye chal raha
*/

class MKAverage {
public:
    MKAverage(int m, int k):m(m),k(k) {
       mSizeVector=vector<int>(m);
        size=m-2*k;
        pos=0;
        sum=0;
    }
    
    void remove(int num){
        //check if num lies in left multiset
        if(num<=*rbegin(left)){
            auto it=left.find(num);
            left.erase(it);
        }
        
        //else check if num lies in mid
        else if(num<=*rbegin(mid)){
            auto it=mid.find(num);
            sum-=*it;
            mid.erase(it);
        }
        
        //at this point of time num is present in right
        else{
            auto it=right.find(num);
            right.erase(it);
        }
        
        //maintain the size 
        if(left.size()<k){
            auto it=mid.begin();
            left.insert(*it);
            sum-=*it;
            mid.erase(it);
        }
        
        if(mid.size()<size){
            auto it=right.begin();
            mid.insert(*it);
            sum+=*it;
            right.erase(it);
        }
    }
    
    void add(int num){
        left.insert(num);
        
        if(left.size()>k){
            auto it=prev(end(left));
            sum+=*it;
            mid.insert(*it);
            left.erase(it);
        }
        
        //check if mid is overloaded or not
        if(mid.size()>size){
            auto it=prev(end(mid));
            sum-=*it;
            right.insert(*it);
            mid.erase(it);
        }
    }
    
    void addElement(int num) {
        if(pos>=m){
            //remove index (pos%m)
            remove(mSizeVector[pos%m]);
        }
        
        mSizeVector[pos%m]=num;
        add(num);
        pos++;
    }
    
    int calculateMKAverage() {
        if(pos<m){
            return -1;
        }
        
        return sum/size;
    }

private:
    vector<int> mSizeVector;
    long sum;
    multiset<int> left,mid,right;
    int m;
    int k;
    int size;
    int pos;
};

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */