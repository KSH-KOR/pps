class Element{

public:
    int key;
    int count;
    vector<int>::iterator start;
    vector<int>::iterator end;

    Element(int key,
    int count,
    vector<int>::iterator start,
    vector<int>::iterator end){
        this->key = key;
        this->count = count;
        this->start = start;
        this->end = end;
    }
};

class Solution {
    vector<Element>::iterator findElement(vector<Element>& count, int num){
        vector<Element>::iterator it = count.begin();
        for(; it < count.end(); it++){
            if((*it).key == num) break;
        }
        return it;
    }
    void newNumber(vector<Element>& count, int num, vector<int>::iterator num_it){ 
        count.push_back(Element(num, 1, num_it, num_it));
    }
    void addNumber(vector<Element>& count, vector<int>::iterator num_it){
        auto it = findElement(count, *num_it);
        if (it == count.end()) {
            newNumber(count, *num_it, num_it);
        }
        else {
            (*it).count++;
            (*it).end = num_it;
        }
    }
    static int cmp(Element a, Element b){
        return a.count > b.count;
    }
public:
    int findShortestSubArray(vector<int>& nums) {
        vector<Element> count;
        for(auto it = nums.begin(); it < nums.end(); it++){
            addNumber(count, it);
        }
        sort(count.begin(), count.end(), cmp);
        int i=0;
        int max_freq = count.at(i).count;
        int min_sub_length = 50000;

        for(auto x: count){
            int freq = x.count;
            if(freq < max_freq) break;
            int sub_length = x.end - x.start;
            if(sub_length < min_sub_length) min_sub_length = sub_length;
        }
        return min_sub_length + 1;
    }
};