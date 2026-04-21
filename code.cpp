#include <iostream>

using namespace std;

struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

void solve_subtask1(long long n) {
    if (n <= 0) return;
    Node* head = new Node(1);
    Node* tail = head;
    for (long long i = 2; i <= n; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    
    for (long long i = 0; i < n - 1; ++i) {
        // 1. Move first to end
        tail->next = head;
        tail = head;
        head = head->next;
        tail->next = nullptr;
        
        // 2. Discard first
        Node* temp = head;
        head = head->next;
        delete temp;
        
        // Output first card
        cout << head->val << "\n";
    }
    delete head; // Last remaining card
}

void solve_subtask2(long long n) {
    if (n <= 0) return;
    unsigned long long k = 1;
    while (k * 2 <= (unsigned long long)n) {
        k *= 2;
    }
    long long l = n - (long long)k;
    long long ans = 2 * l + 1;
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int id;
    long long n;
    if (!(cin >> id >> n)) return 0;
    if (id == 1) {
        solve_subtask1(n);
    } else {
        solve_subtask2(n);
    }
    return 0;
}
