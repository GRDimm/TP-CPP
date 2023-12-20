
// Generic cardinality counter.
// It counts how many times a given object was inserted, all
// in constant time.
#include <unordered_map>
using namespace std;

template<class T>
class CardinalityCounter {
 public:
  // Adds an object once, i.e. increments its cardinality count.
  void Add(const T& t) {
    // TODO
    ++map[t];

    if(map[t] > highestFrequency){
        mostFrequent = t;
        highestFrequency = map[t];
    }

  }

  // Returns the current cardinality count of object t, i.e. the number of
  // times Add(t) was called. Can be 0 if t was never added.
  int NumOccurences(const T& t) const {
      auto it = map.find(t);
      if (it != map.end()) {
          return it->second;
      }
      return 0;
  }

  int Size() const {
    return map.size();
  }

  const T& MostFrequent() const {
    return mostFrequent;
  }

 private:
  // TODO
  unordered_map<T, int> map;
  int highestFrequency = 0;
  T mostFrequent;
};
