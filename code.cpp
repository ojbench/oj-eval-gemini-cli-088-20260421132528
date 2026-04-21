#include <iostream>

using namespace std;

/**
 * Node structure for the manually implemented linked list.
 */
struct Node {
    long long val;
    Node* next;
    Node(long long v) : val(v), next(nullptr) {}
};

/**
 * Subtask 1: Simulate the magic trick using a manually implemented linked list.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 */
void solve_subtask1(long long n) {
    if (n <= 0) return;
    
    // Initialize the linked list with cards 1 to n
    Node* head = new Node(1);
    Node* tail = head;
    for (long long i = 2; i <= n; ++i) {
        tail->next = new Node(i);
        tail = tail->next;
    }
    
    // Perform n-1 rounds of the magic trick
    for (long long i = 0; i < n - 1; ++i) {
        // 1. "Good luck stays": Move the first card to the end
        tail->next = head;
        tail = head;
        head = head->next;
        tail->next = nullptr;
        
        // 2. "Troubles go out": Discard the new first card
        Node* temp = head;
        head = head->next;
        delete temp;
        
        // Output the first card of the pile after each round
        cout << head->val << "\n";
    }
    
    // Clean up the last remaining node
    delete head;
}

/**
 * Subtask 2: Directly predict the last card remaining.
 * This is a variation of the Josephus problem J(n, 2).
 * The formula for J(n, 2) where people are 1..n and every 2nd is removed starting from 2nd:
 * If n = 2^k + l, where 0 <= l < 2^k, then the last person is 2l + 1.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */
void solve_subtask2(long long n) {
    if (n <= 0) return;
    
    // Find the largest power of 2 less than or equal to n
    unsigned long long k = 1;
    while (k * 2 <= (unsigned long long)n) {
        k *= 2;
    }
    
    // Calculate l = n - k
    long long l = n - (long long)k;
    
    // The last card is 2l + 1
    long long ans = 2 * l + 1;
    cout << ans << endl;
}

int main() {
    // Speed up I/O operations
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int id;
    long long n;
    if (!(cin >> id >> n)) return 0;
    
    if (id == 1) {
        solve_subtask1(n);
    } else if (id == 2) {
        solve_subtask2(n);
    }
    
    return 0;
}
