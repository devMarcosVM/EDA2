#include <iostream>
#include <vector>

class FenwickTree {
private:
    std::vector<int> tree;
    int size;

    int lsb(int i) {
        return i & -i; // Least significant bit
    }

public:
    FenwickTree(int n) : size(n) {
        tree.resize(n + 1, 0);
    }

    void update(int index, int delta) {
        while (index <= size) {
            tree[index] += delta;
            index += lsb(index);
        }
    }

    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += tree[index];
            index -= lsb(index);
        }
        return sum;
    }

    int rangeQuery(int left, int right) {
        return query(right) - query(left - 1);
    }
};

int main() {
    int n = 10; // Size of the array
    FenwickTree fenwick(n);

    // Example updates
    fenwick.update(1, 5);
    fenwick.update(3, 7);
    fenwick.update(5, 6);

    // Example queries
    std::cout << "Sum of first 5 elements: " << fenwick.query(5) << '\n';
    std::cout << "Sum of elements from 2 to 5: " << fenwick.rangeQuery(2, 5) << '\n';

    return 0;
}