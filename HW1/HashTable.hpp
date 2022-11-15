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
class Hasher {
public:
	virtual size_t operator() (const K& key) = 0;
};

// equality conditions
// EqualityPridicate(x,y) returns whether they are equal
template <typename K>
class EqualityPredicate {
public:
	virtual bool operator() (const K& k1, const K& k2) = 0;
};

// template K, V specifies the types for key and values
// we use an array of linked lists to implement the hash table
template <typename K, typename V>
class Hashtable {
protected:
	vector<forward_list<pair<K, V>>> hashmap;
	size_t size;
	Hasher<K> hasher;
	EqualityPredicate<K> ep;		// the equality predicate

public:
	// Contain checks whether a key is in the hashtable. 
	bool Contain(const K& key) {
		// iterate and check if key in the stored keys
		for (auto& i : hashmap[hasher(key)]) {
			if (ep(i.first, key))
				return true;
		}
		return false;
	}

	V& operator[] (const K& key) {
		for (auto& i : hashmap[hasher(key)]) {
			if (ep(i.first, key))
				// found
				return i.second;
		}

		// otherwise we return the default value of type V
		V defaultValue{};
		hashmap[hasher(key)].push_front(make_pair(key, defaultValue));
		return hashmap[hasher(key)].front().second;
	}

	// get
	// same functionality as [], but we cannot modify the element
	V Get(const K& key) {
		return this->[](key)
	}

	// Set: use the [] operator overloaded above
	void Set(const K& key, const V& value) {
		this->operator[](key) = value;
	}

	// remove the (k,v) pair
	// first we identify the location of the k,v pair
	void Erase(const K& key) {
		auto target = hashmap[hasher(key)];
		for (auto it = target.begin(); it != target.end(); ++it) {
			if (ep(it->first, key)) {
				hashmap[hasher(key)].erase_after(--it);
				return;
			}
		}
	}
};


#endif //HASHTABLE_HPP
