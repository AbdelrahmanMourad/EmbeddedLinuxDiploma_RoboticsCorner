#include <iostream>
#include <list>
#include <map>
#include <stdexcept>

class LRUCache
{
private:
    size_t capacity;
    std::list<int> lruList; // Stores keys in LRU order (front = most recent)
    /*________________________*/
    std::map<int, std::pair<int, std::list<int>::iterator>> cacheMap; // key -> {value, list_iterator}
    /*________________________*/
public:
    LRUCache(size_t cap) : capacity(cap)
    {
        if (cap == 0)
            throw std::invalid_argument("Cache capacity must be positive.");
    }

    int get(int key)
    {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end())
            throw std::out_of_range("Key not found in cache.");

        // Move the key to the front of the LRU list
        lruList.splice(lruList.begin(), lruList, it->second.second);

        return it->second.first; // Return the value
    }

    void put(int key, int value)
    {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end())
        {
            // Key exists, update value and move to front
            it->second.first = value;
            lruList.splice(lruList.begin(), lruList, it->second.second);
        }
        else
        {
            // New key
            if (cacheMap.size() >= capacity)
            {
                // Cache is full, remove the least recently used item
                int lruKey = lruList.back();
                lruList.pop_back();
                cacheMap.erase(lruKey);
            }

            // Add new key to the front of the list
            lruList.push_front(key);

            // Insert into the map with a reference to the new list iterator
            cacheMap.insert({key, {value, lruList.begin()}});
        }
    }
};

int main()
{
    LRUCache cache(3);

    cache.put(1, 10);
    cache.put(2, 20);
    cache.put(3, 30);

    std::cout << "Value for key 2: " << cache.get(2) << std::endl; // Accessing 2 moves it to the front

    cache.put(4, 40); // Cache is full, 1 should be removed

    // Attempting to access key 1 should throw an exception.
    try
    {
        std::cout << "Value for key 1: " << cache.get(1) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
