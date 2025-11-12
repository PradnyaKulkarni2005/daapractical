#include <iostream>
#include <vector>
using namespace std;

// class with timestamp and customername
class CustomerOrder {
public:
    long long timestamp;
    string customername;

    // ADDED: default constructor so vectors of CustomerOrder can be default-initialized
    CustomerOrder() : timestamp(0), customername("") {}

    CustomerOrder(long long timestamp, string customername) {
        this->timestamp = timestamp;
        this->customername = customername;
    }
};

class MergeSort {
public:
    void sort(vector<CustomerOrder> &orders) {
        // if size is less than =1 then no need to sort - return
        if (orders.size() <= 1) return;
        // call mergesort function
        mergesort(orders, 0, orders.size() - 1);
    }

private:
    void mergesort(vector<CustomerOrder> &orders, int left, int right) {
        // base case
        if (left >= right) return;
        // calculate mid
        int mid = left + (right - left) / 2;
        // call mergesort - divide it into two parts 
        //1.left to mid 2.mid+1 to right

        mergesort(orders, left, mid);
        mergesort(orders, mid + 1, right);
        // merge it
        merge(orders, left, mid, right);
    }

    void merge(vector<CustomerOrder> &orders, int left, int mid, int right) {
        // length of the left part
        int n1 = mid - left + 1;
        // length of the right part
        int n2 = right - mid;
        // two vectors to store left and right part
        vector<CustomerOrder> L(n1), R(n2);
        // store left part in L
        for (int i = 0; i < n1; i++)
            L[i] = orders[left + i];
        // stores right part in R
        for (int j = 0; j < n2; j++)
            R[j] = orders[mid + 1 + j];

        int i = 0, j = 0, k = left;

        while (i < n1 && j < n2) {
            // according to the elements in the L & R , arrange them in ascending order and add it into orders
            if (L[i].timestamp <= R[j].timestamp) {
                orders[k++] = L[i++];
            } else {
                orders[k++] = R[j++];
            }
        }
        // add remaining elements
        while (i < n1) {
            orders[k++] = L[i++];
        }

        while (j < n2) {
            orders[k++] = R[j++];
        }
    }
};

int main() {
    // created orders vector of CustomerOrder class to store orders
    vector<CustomerOrder> orders = {
        CustomerOrder(1678901234, "A"),
        CustomerOrder(1678801111, "B"),
        CustomerOrder(1678956789, "C"),
        CustomerOrder(1678704321, "D")
    };

    MergeSort s;
    s.sort(orders);
    // display sorted orders by timestamp
    cout << "Sorted Orders by Timestamp:\n";
    for (auto &o : orders) {
        cout << o.timestamp << " - " << o.customername << endl;
    }

    return 0;
}
