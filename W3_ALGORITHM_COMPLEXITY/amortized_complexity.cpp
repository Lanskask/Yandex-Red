#include<iostream>
#include<cstdint>
#include<queue>

using namespace std;

class EventManager {
public:
    void Add(uint64_t time) {
        events.push(time);
    }

    int Count(uint64_t time) {
        Adjust(time);
        return events.size();
    }

    void PrintFirst() {
        cout << events.front() << endl;
    }
private:
    queue<uint64_t> events;

    void Adjust(uint64_t time) {
        while (!events.empty()
               && events.front() < (events.back() - time)
                ) {
            events.pop();
        }
    }

};

int main(int argc, char *argv[]) {
    vector<uint64_t> v1 = {1,3,14,15,21,31,40};
    EventManager em;

    for(auto x: v1) em.Add(x);

    em.PrintFirst();
    em.Count(30);
    em.PrintFirst();

    return EXIT_SUCCESS;
}