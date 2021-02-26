class LRUCache
{
    int c;
    list<int> dq;
    unordered_map<int, list<int>::iterator> m;
    
    public:
        LRUCache(int capacity);
        int get(int key);
        void set(int key, int value);
};

LRUCache::LRUCache(int capacity) 
{
    c = capacity;
}

int LRUCache::get(int key) 
{
	int value;
	
    if(m.find(key) == m.end()) 
    {
        if (dq.size() == c) 
        {
            int last = dq.back();
            dq.pop_back();
            m.erase(last);
        }
    }
 
    else
    {
    	value = m[key];
        dq.erase(m[key]); 
    }
      
    dq.push_front(value);
    m[key] = dq.begin();
    
    return value;
}

void LRUCache::set(int key, int value) 
{
    dq.push_front(value);
    m[key] = value;
}

