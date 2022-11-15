// HashTable.hpp by Chengxun Wu (James)
// File from MTH9815 Software Engineering HW1

#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <forward_list>

using namespace std;

// A hasher
// Allows for hasher(key)
template <typename K>
class Hasher
{
public:
	virtual size_t operator()(const K &key) = 0;
};

// equality conditions
// EqualityPridicate(x,y) returns whether they are equal
template <typename K>
class EqualityPredicate
{
public:
	virtual bool operator()(const K &k1, const K &k2) = 0;
};

// template K, V specifies the types for key and values
// we use an array of linked lists to implement the hash table
template <typename K, typename V>
class Hashtable
{
protected:
	vector<forward_list<pair<K, V>>> hashmap;
	size_t size;
	Hasher<K> hasher;
	EqualityPredicate<K> ep; // the equality predicate

public:
	// Contain checks whether a key is in the hashtable.
	bool Contains(const K &key)
	{
		// iterate and check if key in the stored keys
		for (auto &i : hashmap[hasher(key)])
		{
			if (ep(i.first, key))
				return true;
		}
		return false;
	}

	V &operator[](const K &key)
	{
		for (auto &i : hashmap[hasher(key)])
		{
			if (ep(i.first, key))
				// found
				return i.second;
		}

		// otherwise we return the default value of type V
		V defaultValue{};
		hashmap[hasher(key)].push_front(make_pair(key, defaultValue));
		size++; // when we encounter a new key, we will create a slot for it, so we add 1 in the size
		return hashmap[hasher(key)].front().second;
	}

	// Set: use the [] operator overloaded above
	// it also does the insert job
	void Set(const K &key, const V &value)
	{
		this->operator[](key) = value;
	}

	// remove the (k,v) pair
	// first we identify the location of the k,v pair
	void Erase(const K &key)
	{
		auto target = hashmap[hasher(key)];
		for (auto it = target.begin(); it != target.end(); ++it)
		{
			if (ep(it->first, key))
			{
				hashmap[hasher(key)].erase_after(--it);
				size--; // after removal, we decrease the size
				return;
			}
		}
		std::cout << "Delete not successful. Key not stored." << std::endl;
	}
};

#endif // HASHTABLE_HPP
