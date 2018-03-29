


class LFUCache{
    unordered_nap<int,pair<int,int>>Map; // key->val,freq
    unordered_map<int,list<int,int>>frep;//freq->list of the keys
    unordered_map<int,list<int>::iterator>iter;  // key->iter
    int minFreq=0;
    int cap;
public:
   LFUCache(int capacity){cap=caoacity;}
   int get(int key){
      if(Map.find(key)==Map.end())return -1;
      int f=Map[key].second;
      Map[key].second++;
      auto it = iter[key];
      freq[f].erase(it);
      freq[f+1].push_back(key);
      iter[key]=--freq[f+1].end();
      if(freq[minFreq].size()==0)
              minFreq++;
      return Map[key].first;
                   }

       void put(int key,int value){
        if(cap<=0)return ;
        if(get(key)!=-1){
         Map[key].first=value;
         return;}
         if(Map.size()<cap){
             Map[key]={value,1};
             freq[1].push_back(key);
             iter[key]=--freq[1].end();
             minFreq=1; }
         else{
			 int minKey=freq[minFreq].front();
			 freq[minFreq].pop_front();
			 Map.erase(minKey);
			 iter.erase(minKey);
			 Map[key]={value,1};
			 freq[1].push_back(key);
			 iter[key]=--freq[1].end();
			 minFreq=1;
			 
		 }
       }
}