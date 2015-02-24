#include <thread>
#include <queue>


using namespace std;
template <class T>
class DPriorityQ {
private:
    priority_queue<T> pq;
